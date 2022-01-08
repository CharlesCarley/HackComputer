from genericpath import isdir, isfile
import xml.etree.ElementTree as Xml
import sys, os


class Path:

    def __init__(self, directory=None, fileName=None, extension=None):
        if (directory != None):
            self.path = directory
            self.normalize()
        else:
            self.path = os.getcwd()
            self.normalize()

        if (fileName != None):
            self.path += os.sep
            self.path += fileName
            if (extension != None):
                self.path += extension
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
        result = os.path.join(result, path)
        of = open(result, "w")
        of.write("")
        of.close()

        return Path(result)

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

    def subdir(self, relitave):
        result = self.path
        if (sys.platform == "win32"):
            relitave = relitave.replace('/', '\\')
        else:
            relitave = relitave.replace('\\', '/')

        joinResult = os.path.join(result, relitave)
        if (not os.path.isdir(joinResult)):
            msg = "The path '%s' does not exist " % joinResult
            raise Exception(msg)

        return Path(joinResult)

    def recreate(self):
        result = self.path

        os.makedirs(result)
        return Path(result)

    def pathName(self):
        if (os.path.isdir(self.path)):
            return self.path
        elif (os.path.isfile(self.path)):
            return os.path.split(self.path)[0]

    def base(self):
        if (os.path.isdir(self.path)):
            return self.path
        elif (os.path.isfile(self.path)):
            return os.path.split(self.path)[1]
    def removeFile(self, file):
        localFile = os.path.join(self.path, file)

        if (os.path.isfile(localFile)):
            print("Removing", localFile)
            os.remove(localFile)

class Reference:
    def __init__(self):
        self.refId = None
        self.kind = None
        self.input = None
        self.output = None
        self.title = None


    def __repr__(self) -> str:
        return "{%s, %s, %s}"%(self.input, self.refId, self.kind)


class Application:

    def __init__(self):
        self.input = None
        self.output = None
        self.classes = {}
        self.namespaces = {}
        self.pages = {}
        self.files = {}


    def valid(self):
        return self.input != None and self.output!=None

    def writePage(self, ref):

        result = Xml.parse(ref.input.path)
        root = result.getroot()
        
        compoundIter = root.iter("compounddef")

        outFile = None
        for compound in compoundIter:
            outFile = self.output.file(compound.attrib['id']+".md");
            ref.output = Path(outFile.path)

            fp = open(outFile.path, "w")

            titleIter = compound.iterfind("title");
            for title in titleIter:
                ref.title = title.text
                fp.write("# %s\n"%title.text)

            
        

            fp.close();


    def writeClass(self, ref):

        result = Xml.parse(ref.input.path)
        root = result.getroot()
        
        compoundIter = root.iter("compounddef")

        outFile = None
        for compound in compoundIter:
            outFile = self.output.file(compound.attrib['id']+".md");
            ref.output = Path(outFile.path)

            fp = open(outFile.path, "w")

            titleIter = compound.iterfind("compoundname");
            for title in titleIter:
                ref.title = title.text
                fp.write("# %s\n"%title.text)

            
        

            fp.close();

    def write(self):

        self.input = Path(self.input);
        self.output = Path(self.input.pathName())
        
        result = Xml.parse(self.input.path)
        root = result.getroot()

        compound = root.iter("compound")
        for c in compound:

            ref = Reference()

            if ('kind' in c.attrib):
                ref.kind = c.attrib['kind']
            if ('refid' in c.attrib):
                ref.refId = c.attrib['refid']

            ref.input  = Path(self.output.path, ref.refId, ".xml")

            if (ref.kind == "class"):
                self.classes[ref.refId] = ref;
            if (ref.kind == "namespace"):
                self.namespaces[ref.refId] = ref;
            if (ref.kind == "page"):
                self.pages[ref.refId] = ref;
            if (ref.kind == "file"):
                self.files[ref.refId] = ref;

        for page in self.pages.keys():
            ref = self.pages[page]
            self.writePage(ref)

        for clsRef in self.classes.keys():
            ref = self.classes[clsRef]
            self.writeClass(ref)


        outFile = self.output.file("index.md");
        fp = open(outFile.path, "w")
        fp.write("# Table of contents\n\n");

        fp.write("## Pages\n\n");

        for page in self.pages.keys():
            ref = self.pages[page]
            if (ref.output != None):
                fp.write("- [%s](%s)\n"%(ref.title, ref.output.base()))

        fp.write("\n");
        fp.write("## Classes\n\n");
        for clsId in self.classes.keys():
            ref = self.classes[clsId]
            if (ref.output != None):
                fp.write("- [%s](%s)\n"%(ref.title, ref.output.base()))



def usage():
    str = """
%s -i <input> -o <output>
    """%(sys.argv[0])
    print(str)

def parseOptions(app, argc, argv):

    argc = len(sys.argv)
    if (argc <= 1):
        usage();
        return False


    for i in range(1, argc):

        if (sys.argv[i] == '-i'):
            app.input = sys.argv[i+1]
        elif (sys.argv[i] == '-o'):
            app.output = sys.argv[i+1]

    return app.valid()

def main():
    app = Application()
    if (parseOptions(app, len(sys.argv), sys.argv)):
        app.write();





if __name__=='__main__':
    main()
