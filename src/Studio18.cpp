#include <iostream>

#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"

using namespace std;
int main(int argc, char *argv[]) {
    AbstractFileSystem* fileSystemPtr = new SimpleFileSystem();
    AbstractFileFactory* factoryPtr = new SimpleFileFactory();
    AbstractFile * yupFile = factoryPtr->createFile("yup.txt");
    AbstractFile * yippeeFile = factoryPtr->createFile("yippee.txt");
    fileSystemPtr->addFile("yup.txt", yupFile);
    fileSystemPtr->addFile("yippee.txt", yippeeFile);

    fileSystemPtr->openFile("yup.txt");
    fileSystemPtr->openFile("yippee.txt");

    vector<char> writingYup = {'y','u','p'};
    yupFile->write(writingYup);
    vector<char> writingYippee = {'y','i','p','p','e','e'};
    yippeeFile->write(writingYippee);
    yupFile->read();
    cout << endl;
    yippeeFile->read();
    return 0;
}
