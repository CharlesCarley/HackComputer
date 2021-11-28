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
    subprocess.run(args, shell=True, env=os.environ, stdout=None)
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


class Path:

    def __init__(self, directory=None):
        if (directory != None):
            self.path = directory
            self.normalize()
        else:
            self.path = os.getcwd()
            self.normalize()

        if (not self.check()):
            msg = "The supplied path %s is invalid" % self.path
            raise Exception(msg)

    def normalize(self):
        if (sys.platform == "win32"):
            self.path = self.path.replace('/', '\\')
        else:
            self.path = self.path.replace('\\', '/')
        self.path = os.path.abspath(self.path)

    def check(self):
        return os.path.exists(self.path)

    def __repr__(self) -> str:
        return self.path

    def back(self, n=1):

        back = self.path
        for i in range(n):
            back = os.path.join(back, "../")

        return Path(back)

    def join(self, directory):
        result = self.path
        return Path(os.path.join(result, directory))

    def file(self, path):
        result = self.path
        return os.path.join(result, path)

    def create(self, relitave):
        result = self.path
        if (sys.platform == "win32"):
            relitave = relitave.replace('/', '\\')
        else:
            relitave = relitave.replace('\\', '/')

        joinResult = os.path.join(result, relitave)
        if (not os.path.isdir(joinResult)):
            os.makedirs(joinResult)
        return Path(joinResult)

    def remove(self):
        result = self.path
        if (os.path.isdir(result)):
            print("Removing", result)
            shutil.rmtree(result)

    def copyTo(self, file, toPath):
        shutil.copyfile(self.file(file), toPath().file(file))



class Builder:

    def __init__(self, verbose=True, release=False):

        self.verbose = verbose
        self.release = release

        self.opts = {}

        thisDir = Path()
        sourceDir = thisDir.back()
        self.opts['dev'] = thisDir
        self.opts['source'] = sourceDir

        webDir = sourceDir.join("Web")
        self.opts['web'] = webDir
        self.opts['web_test'] = webDir.join("test")
        self.opts['web_asset'] = webDir.join("assets")
        self.opts['web_content'] = webDir.join("content")

        if (sys.platform == "win32"):
            platname = "windows"
        else:
            platname = 'linux'

        self.opts['platform'] = platname

        buildDir = thisDir.create(platname)

        self.opts['build_cpp'] = buildDir.create("cpp")
        self.opts['build_em'] = buildDir.create("em")

        buildOutput = self.opts['build_cpp'].create("build_files")
        self.opts['build_files'] = buildOutput

        if (sys.platform == "win32"):
            self.opts['binding_file'] = buildOutput.file("bindings.dll")
        else:
            self.opts['binding_file'] = buildOutput.file("libbindings.so")


        buildOutput = self.opts['build_em'].create("build_files")
        self.opts['em_build_files'] = buildOutput

    def dumpOpts(self):
        for k in self.opts.keys():
            print(k, " => ", self.opts[k])

    def goto(self, path):
        try:
            os.chdir(path.path)
        except:
            msg = "Failed to change working directory to %s" % path.path
            raise Exception(msg)

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

    def webAssetDir(self):
        return self.opts['web_asset']

    def flutterPlatform(self):
        return self.opts['platform']

    def buildOutput(self):
        return self.opts['build_files']

    def buildOutputEm(self):
        return self.opts['em_build_files']

    def bindingFile(self):
        return self.opts['binding_file']

    def configString(self):
        config = "Debug"
        if (self.release):
            config = "Release"
        return config

    def flutterBuildMode(self):
        config = ""
        if (self.release):
            config = "--release"
        return config

    def run(self, cmd):
        print("".ljust(80, '='))
        print("Calling => ", cmd)
        subprocess.run(cmd, shell=True, env=os.environ)
        print("".ljust(2, '\n'))

    def copyBindings(self):

        if (sys.platform == 'win32'):

            buildDir = self.webDir().create("build/windows/runner/%s" %
                                            self.configString())
            shutil.copyfile(self.bindingFile(),
                            buildDir.file("bindings.dll"))

            shutil.copyfile(self.bindingFile(),
                            self.webTestDir().file("bindings.dll"))

    def copyEmBindings(self):

        self.buildOutputEm().copyTo(
            "bindings.js", 
            self.webAssetDir()
        )
        self.buildOutputEm().copyTo(
            "bindings.wasm", 
            self.webAssetDir()
        )
    
    def findOpt(self, argc, argv, opt):
        for i in range(argc):
            if (opt == argv[i]):
                return True
        return False

    def buildCpp(self, argc, argv):
        print("Building C++", argv)

        self.goto(self.cppDir())

        defines = "-DHack_BUILD_TEST=ON -DHack_AUTO_RUN_TEST=ON "
        defines += "-DHack_IMPLEMENT_BLACK_BOX=OFF "
        defines += "-DHack_USE_SDL=%s" %self.findOpt(argc, argv, "--with-sdl")

        self.run("cmake %s %s" % (self.sourceDir(), defines))
        self.run("cmake --build %s --config %s" %
                 (self.cppDir(), self.configString()))


        



    def buildEm(self, argc, argv):
        print("Building Emscripten", argv)

        self.goto(self.emDir())

        execStr = "emcmake.bat cmake "
        if (sys.platform == 'win32'):
            execStr += '-G "NMake Makefiles" '

        execStr += self.sourceDir().path
        execStr += " -DHack_IMPLEMENT_BLACK_BOX=OFF"

        self.run(execStr)
        self.run("cmake --build %s --config %s" %
                 (self.emDir(), self.configString()))

    def buildClean(self):

        self.cppDir().remove()
        self.emDir().remove()

        self.goto(self.webDir())
        self.run("flutter clean")

    def buildFl(self, argc, argv):
        print("Building Flutter Source", argv)


        if (self.findOpt(argc, argv, "web")):

            self.buildEm(0, [])

            self.copyEmBindings()

            self.goto(self.webDir())
            self.run("flutter run -d chrome %s" %
                     self.flutterBuildMode())

        else:

            self.buildCpp(0, [])
            self.copyBindings()

            self.goto(self.webTestDir())
            self.run("flutter test")

            self.goto(self.webDir())
            self.run("flutter run -d %s %s" %
                     (self.flutterPlatform(),
                      self.flutterBuildMode()))


def main(argc, argv):

    build = Builder()
    build.release = build.findOpt(argc, argv, "--release")

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
        build.buildCpp(argc, argv)

    build.goto(build.home())


if __name__ == '__main__':
    main(len(sys.argv), sys.argv)
