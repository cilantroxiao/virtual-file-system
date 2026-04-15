#include "mockos/AbstractFileSystem.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>
#include <sstream>

#include "mockos/PasswordProxy.h"

using namespace std;
int main(int argc, char *argv[]) {

    AbstractFileSystem* fileSystemPtr = new SimpleFileSystem();
    AbstractFileFactory* factoryPtr = new SimpleFileFactory();
    AbstractFile * pwrdFile = factoryPtr->createFile("pwrd.txt");
    fileSystemPtr->addFile("YUMMY.txt", pwrdFile);
    fileSystemPtr->openFile("YUMMY.txt");

    vector <char> contents = {'p', 'w','r','d'};
    pwrdFile->write(contents);
    string password = "password";

    PasswordProxy pwrdProtected = PasswordProxy(pwrdFile, password);

    pwrdProtected.read();

    vector<char> writtenInput =  {'h','i'};
    pwrdProtected.write(writtenInput);

    vector<char> appendedInput = {'h','e','h','e'};
    pwrdProtected.append(appendedInput);

    AbstractFileVisitor * visitor = new BasicDisplayVisitor();
    pwrdProtected.accept(visitor);

    return 0;



}