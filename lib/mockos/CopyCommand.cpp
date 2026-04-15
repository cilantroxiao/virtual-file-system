/**
 * CopyCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the CopyCommand class and its methods for copying files within the file
 * system. It uses the prototype design pattern to clone an existing file and save it under a
 * new name with the same file extension.
 */

#include "mockos/Constants.h"
#include "mockos/CopyCommand.h"
#include <iostream>
#include <sstream>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem *fileSystemPtr) : fileSystemPtr(fileSystemPtr) {
}

int CopyCommand::execute(string command) {
    istringstream iss(command);
    string originalName, newName;
    iss >> originalName >> newName;

    if (originalName.empty() || newName.empty()) {
        cout << "Error: Please provide both an original filename and a new name." << endl;
        return INVALID_INPUT;
    }

    AbstractFile *originalFile = fileSystemPtr->openFile(originalName);
    if (originalFile == nullptr) {
        cout << "Error: File " << originalName << " could not be opened." << endl;
        return FILE_OPEN_FAIL;
    }

    size_t dotPosition = originalName.find('.');
    string extension = (dotPosition != string::npos) ? originalName.substr(dotPosition) : "";

    newName += extension;

    //clone using prototype pattern
    AbstractFile *copyFile = originalFile->clone(newName);
    if (copyFile == nullptr) {
        cout << "Error cloning file " << originalName << endl;
        fileSystemPtr->closeFile(originalFile);
        return FILE_OPEN_FAIL;
    }

    int result = fileSystemPtr->addFile(newName, copyFile);
    if (result != SUCCESS) {
        cout << "Error adding file " << newName << endl;
        delete copyFile;
        fileSystemPtr->closeFile(originalFile);
        return FILE_OPEN_FAIL;
    }

    cout << "File successfully copied" << endl;
    fileSystemPtr->closeFile(originalFile);
    return SUCCESS;
}

void CopyCommand::displayInfo() {
    cout << "cp copies a file that exists in the file system and adds the copy to the file system with a different name. Usage: cp <file_to_copy> <new_name_with_no_extension>" << endl;
}
