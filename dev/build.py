# -----------------------------------------------------------------------------
#
#   Copyright (c) Charles Carley.
#
#   This software is provided 'as-is', without any express or implied
# warranty. In no event will the authors be held liable for any damages
# arising from the use of this software.
#
#   Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
#
# 1. The origin of this software must not be misrepresented; you must not
#    claim that you wrote the original software. If you use this software
#    in a product, an acknowledgment in the product documentation would be
#    appreciated but is not required.
# 2. Altered source versions must be plainly marked as such, and must not be
#    misrepresented as being the original software.
# 3. This notice may not be removed or altered from any source distribution.
# ------------------------------------------------------------------------------
import sys
import os
import subprocess
import shutil


def getPlatform():
    if (sys.platform == "win32"):
        return "windows"
    else:
        return "linux"


def normalize(path):
    if (sys.platform == "win32"):
        path = path.replace('/', '\\')
    else:
        path = path.replace('\\', '/')
    return path


def execProgram(args):

    print("".ljust(80, "="))
    print("Calling => ", args)
    subprocess.run(args, shell=True, env=os.environ)
    print("".ljust(2, "\n"))


def changeDirectory(directory):
    try:
        os.chdir(directory)
        print(directory)
        return directory == os.getcwd()
    except:
        print("Failed to change working directory to", directory)
        exit(1)


def ensureDirectory(directory):
    absDir = os.path.join(os.getcwd(), directory)
    if not os.path.isdir(absDir):
        os.mkdir(absDir)


def removeDirectory(directory):
    absDir = os.path.join(os.getcwd(), directory)
    if os.path.isdir(absDir):
        print("Removing ", absDir)
        shutil.rmtree(absDir)


def buildClean():
    print("".ljust(80, "="))
    print("Cleaning...")
    removeDirectory(getPlatform())
    print("".ljust(2, "\n"))
    changeDirectory("../Web")
    execProgram("flutter clean")


class Builder:

    def __init__(self):
        self.opts = {}
        self.opts['dev'] = normalize(os.path.abspath(os.getcwd()))
        self.opts['source'] = normalize(
            os.path.abspath(os.path.join(os.getcwd(), "..")))
        self.opts['web'] = normalize(os.path.join(self.opts['source'], "Web"))
        self.opts['web_test'] = normalize(
            os.path.join(self.opts['web'], "test"))
        self.opts['web_asset'] = normalize(
            os.path.join(self.opts['web'], "assets"))
        self.opts['web_content'] = normalize(
            os.path.join(self.opts['web'], "content"))

        if (sys.platform == "win32"):
            self.opts['platform'] = 'windows'
        else:
            self.opts['platform'] = 'linux'

        self.ensureDirectory(self.opts['dev'], self.opts['platform'])
        self.ensureDirectory(self.opts['dev'], self.opts['platform'] + "/cpp")
        self.ensureDirectory(self.opts['dev'], self.opts['platform'] + "/em")

        self.opts['build_cpp'] = normalize(
            self.opts['dev'] + '/' + self.opts['platform'] + "/cpp")
        self.opts['build_em'] = normalize(
            self.opts['dev'] + '/' + self.opts['platform'] + "/em")

        # CMake will copy the files to
        # ${CMAKE_BINARY_DIR}/build_files

        if (sys.platform == 'win32'):
            self.opts['bindings'] = self.opts['build_cpp'] + \
                "/build_files/bindings.dll"
            self.opts['computer'] = self.opts['build_cpp'] + \
                "/build_files/Computer.dll"
        else:
            self.opts['bindings'] = self.opts['build_cpp'] + \
                "/build_files/libbindings.so"
            self.opts['computer'] = self.opts['build_cpp'] + \
                "/build_files/Computer"

    def ensureDirectory(self, directory, makeDir):
        absDir = normalize(os.path.abspath(os.path.join(directory, makeDir)))
        if not os.path.isdir(absDir):
            print("Creating directory, ", absDir)
            os.mkdir(absDir)

    def copyBindings(self):

        if (sys.platform == 'win32'):
            dest = os.path.join(self.webDir(), "build/windows/runner/Release/")
            dest = os.path.join(dest, "bindings.dll")

            shutil.copyfile(self.opts['bindings'], dest)

            dest = os.path.join(self.webDir(), "bindings.dll")
            shutil.copyfile(self.opts['bindings'], dest)

    def copyEmBindings(self):
        src = os.path.join(self.emDir(), "build_files/bindings.js")
        dst = os.path.join(self.webDir(), "assets/bindings.js")
        shutil.copyfile(src, dst)


        src = os.path.join(self.emDir(), "build_files/bindings.wasm")
        dst = os.path.join(self.webDir(), "assets/bindings.wasm")
        shutil.copyfile(src, dst)


    def home(self):
        return self.opts['dev']

    def sourceDir(self):
        return self.opts['source']

    def cppDir(self):
        return self.opts['build_cpp']

    def emDir(self):
        return self.opts['build_em']

    def webDir(self):
        return self.opts['web']

    def webTestDir(self):
        return self.opts['web_test']

    def flutterPlatform(self):
        return self.opts['platform']

    def buildCpp(self, argc, argv):
        print("Building C++", argv)

        changeDirectory(self.cppDir())

        defines = "-DHack_BUILD_TEST=ON -DHack_AUTO_RUN_TEST=ON "
        defines += "-DHack_USE_SDL=ON "
        defines += "-DHack_IMPLEMENT_BLACK_BOX=OFF"

        execProgram("cmake %s %s" % (self.sourceDir(), defines))
        execProgram("cmake --build .")

    def buildEm(self, argc, argv):
        print("Building Emscripten", argv)

        changeDirectory(self.emDir())

        execStr = "emcmake.bat cmake "

        if (sys.platform == 'win32'):
            execStr += '-G "NMake Makefiles" '
        execStr += self.sourceDir()
        execStr += " -DHack_IMPLEMENT_BLACK_BOX=OFF"

        execProgram(execStr)
        execProgram("cmake --build . --config MinSizeRel")


    def buildClean(self):
        print("".ljust(80, "="))

        removeDirectory(self.cppDir())
        removeDirectory(self.emDir())
        changeDirectory(self.webDir())

        execProgram("flutter clean")

    def buildFl(self, argc, argv):
        print("".ljust(80, "="))
        print("Building Flutter Source")

        if (argc == 0):
            self.buildCpp(0, [])

            self.copyBindings()
            changeDirectory(self.webDir())
            execProgram("flutter test")
            dest = os.path.join(self.webDir(), "bindings.dll")
            os.remove(dest)

            changeDirectory(self.webDir())
            execProgram("flutter run -d %s --release" % self.flutterPlatform())
        else:

            if (argv[0]=='web'):
                self.buildEm(0, [])
                self.copyEmBindings()

                changeDirectory(self.webDir())
                execProgram("flutter run -d chrome --release")
            else: 
                self.buildCpp(0, [])
                changeDirectory(self.webDir())
                execProgram("flutter run -d %s --release" % self.flutterPlatform())
                self.copyBindings()


def main(argc, argv):
    build = Builder()

    if (argc > 1):
        if (argv[1] == 'cpp'):
            build.buildCpp(argc-2, argv[2:])
        elif (argv[1] == 'em'):
            build.buildEm(argc-2, argv[2:])
        elif (argv[1] == 'fl'):
            build.buildFl(argc-2, argv[2:])
        elif (argv[1] == 'clean'):
            build.buildClean()
    else:
        build.buildCpp(0, [])

    changeDirectory(build.home())


if __name__ == '__main__':
    main(len(sys.argv), sys.argv)
