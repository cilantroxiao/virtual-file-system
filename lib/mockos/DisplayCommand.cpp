/**
* DisplayCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the DisplayCommand class and its methods for displaying the contents of
 * a file. It supports both a formatted display using a visitor pattern and an unformatted
 * display using a flag (-d).
 */

#include "mockos/DisplayCommand.h"
#include <iostream>
#include "mockos/BasicDisplayVisitor.h"
#include <sstream>
#include "mockos/Constants.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fileSystemPtr) : fileSystemPtr(fileSystemPtr) {
}

int DisplayCommand::execute(string name) {
    istringstream iss(name);
    string fileName, flag;
    iss >> fileName >> flag;
    if (fileName.empty()) {
        cout << "Error: No file name provided." << endl;
        return INVALID_INPUT;
    }
    AbstractFile* filePtr = fileSystemPtr->openFile(fileName);
    if (filePtr == nullptr) {
        cout << "Error: File " << fileName << " could not be opened." << endl;
        return FILE_OPEN_FAIL;
    }


    if (flag == "-d") {
        vector<char> contents = filePtr->read();
        for (char c : contents) {
            cout << c;
        }
        cout << endl;
    } else {
        BasicDisplayVisitor * visitor = new BasicDisplayVisitor();
        filePtr->accept(visitor);
    }

    fileSystemPtr->closeFile(filePtr);
    return SUCCESS;
}

void DisplayCommand::displayInfo() {
    cout << "ds opens and displays a file's contents. Usage: ds <filename> [-d] (use -d for unformatted display)" << endl;
}
