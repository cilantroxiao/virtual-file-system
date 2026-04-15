/**
 * TouchCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the TouchCommand class and its methods for creating new files
 * in the file system. The command uses the AbstractFileFactory to create files
 * and the AbstractFileSystem to add them.
 */

#include "mockos/TouchCommand.h"
#include "mockos/PasswordProxy.h"
#include <iostream>
#include <sstream>
#include "mockos/Constants.h"
#include <regex>

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* fileSystemPtr, AbstractFileFactory* fileFactoryPtr)
    : fileSystemPtr(fileSystemPtr), fileFactoryPtr(fileFactoryPtr) {}

int TouchCommand::execute(string name) {
    istringstream iss(name);
    string fileName, flag;
    iss >> fileName >> flag;

    AbstractFile* file = fileFactoryPtr->createFile(fileName);
    if (file == nullptr) {
        cout << "FILE CREATION FAILED" << endl;
        return FILE_CREATE_FAIL;
    }

    regex anyOtherFlag("-[a-zA-Z]");
    if (flag == "-p") {
        string password;
        cout << "What is the password for " << fileName << "?" << endl;
        getline(cin, password);
        PasswordProxy* password_ptr = new PasswordProxy(file, password);
        int result = fileSystemPtr->addFile(fileName, password_ptr);
        if (result == NULL_PTR) {
            cout << "FILE ADD FAILED" << endl;
            delete password_ptr;
            return FILE_ADD_FAIL;
        }
    }
    else if (regex_match(flag, anyOtherFlag)) {
        cout << "INVALID FLAG CALLED" << endl;
        return INVALID_FLAG;
    }
    else {
        int result = fileSystemPtr->addFile(fileName, file);
        if (result == NULL_PTR) {
            cout << "FILE ADD FAILED" << endl;
            delete file;
            return FILE_ADD_FAIL;
        }
    }

    return SUCCESS;
}

void TouchCommand::displayInfo() {
    cout << "touch creates a file, touch can be invoked with the command: touch <filename> [-p]" << endl;
}
