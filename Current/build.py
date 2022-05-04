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
import subprocess, os

def run(cmd):
    subprocess.run(cmd, shell=True)

def main():
    if (not os.path.isdir("markdown")):
        os.mkdir("markdown")
    if (not os.path.isdir("html")):
        os.mkdir("html")

    run("doxygen Doxyfile")
    os.chdir("xml")

    run("MdDox -i index.xml -c ../MdDox.cfg")
    os.chdir("../images/dot/")

    run("python ../../../CMake/Modules/invokeDot.py")

if __name__ =='__main__':
    main()
