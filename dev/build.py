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
    return path;


def execProgram(args):

    print("".ljust(80, "="))
    print("Calling => ", args)
    subprocess.run(args, shell=True, env=os.environ)
    print("".ljust(2, "\n"))


def changeDirectory(directory):
    directory = normalize(os.path.join(os.getcwd(), directory))
    try:
        os.chdir(directory)
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


def buildCpp(argc, argv):
    print("Building C++", argv)
    config = "Debug"
    root = getPlatform() + "/cpp"

    ensureDirectory(getPlatform())
    ensureDirectory(root)
    changeDirectory(root)

    defines = "-DHack_BUILD_TEST=ON -DHack_AUTO_RUN_TEST=ON "
    defines += "-DHack_USE_SDL=ON "
    defines += "-DHack_IMPLEMENT_BLACK_BOX=OFF"

    execProgram("cmake ../../../ %s" % defines)
    execProgram("cmake --build . --config %s" % config)

    if (sys.platform == "win32"):
        shutil.copyfile("Source/Computer/%s/Computer.exe" %
                        config, "../../Computer.exe")
    else:
        shutil.copyfile("Source/Computer/Computer", "../../Computer")

    changeDirectory("../../")


def buildEm(argc, argv):
    print("Building Emscripten")

    root = getPlatform() + "/em"
    ensureDirectory(getPlatform())
    ensureDirectory(root)
    changeDirectory(root)

    execProgram(
        'emcmake.bat cmake -G "NMake Makefiles" ../../../ -DHack_IMPLEMENT_BLACK_BOX=OFF')
    execProgram("cmake --build . --config MinSizeRel")
    changeDirectory("../../")


def buildFl(argc, argv):
    print("Building Flutter")

    plat = getPlatform()

    if (argc > 0):
        if argv[0] == 'win':
            buildCpp(0, [])
            changeDirectory("../Web")
            execProgram("flutter run -d %s --release"%plat)

        elif argv[0] == 'web':
            buildEm(0, [])
            changeDirectory("../Web")
            execProgram("flutter run -d chrome --release")

        else:
            buildCpp(0, [])
            changeDirectory("../Web")
            execProgram("flutter run -d %s"%plat)
    else:
        buildCpp(0, [])
        changeDirectory("../Web")
        execProgram("flutter run -d %s"%plat)

    changeDirectory("../")


def buildClean():
    print("".ljust(80, "="))
    print("Cleaning...")
    removeDirectory(getPlatform())
    print("".ljust(2, "\n"))
    changeDirectory("../Web")
    execProgram("flutter clean")


def main(argc, argv):
    currentDir = os.getcwd()
    if (argc > 1):
        if (argv[1] == 'cpp'):
            buildCpp(argc-2, argv[2:])
        elif (argv[1] == 'em'):
            buildEm(argc-2, argv[2:])
        elif (argv[1] == 'fl'):
            buildFl(argc-2, argv[2:])
        elif (argv[1] == 'clean'):
            buildClean()
    else:
        buildCpp(0, [])

    changeDirectory(currentDir)


if __name__ == '__main__':
    main(len(sys.argv), sys.argv)
