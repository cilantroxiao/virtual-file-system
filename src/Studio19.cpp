#include "mockos/AbstractFileSystem.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>
#include <sstream>

using namespace std;
int main(int argc, char *argv[]) {
    AbstractFileSystem* fileSystemPtr = new SimpleFileSystem();
    AbstractFileFactory* factoryPtr = new SimpleFileFactory();
    AbstractFile * YUMMYFile = factoryPtr->createFile("YUMMY.txt");
    fileSystemPtr->addFile("YUMMY.txt", YUMMYFile);

    fileSystemPtr->openFile("YUMMY.txt");

    vector<char> writingYUMMY = {'Y','U','M','M','Y'};
    YUMMYFile->write(writingYUMMY);
    YUMMYFile->read();

    AbstractFile * DISGUSTINGFile = factoryPtr->createFile("DISGUSTING.img");
    fileSystemPtr->addFile("DISGUSTING.img", DISGUSTINGFile);
    fileSystemPtr->openFile("DISGUSTING.img");
    vector<char> writingDISGUSTING = {'X','X','X',' ','2'};
    DISGUSTINGFile->write(writingDISGUSTING);
    DISGUSTINGFile->read();

    AbstractFileVisitor * visitorY = new BasicDisplayVisitor();
    AbstractFileVisitor * visitorG = new BasicDisplayVisitor();
    YUMMYFile->accept(visitorY);
    DISGUSTINGFile->accept(visitorG);
    return 0;
}