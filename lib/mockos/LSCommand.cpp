/**
 * LSCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the LSCommand class and its methods for listing the names of files
 * in the file system. It can print additional metadata with the optional -m flag.
 */

#include "mockos/LSCommand.h"
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include "mockos/Constants.h"
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;


LSCommand::LSCommand(AbstractFileSystem* fileSystemPtr): fileSystemPtr(fileSystemPtr) {}

int LSCommand::execute(string name) {
    istringstream iss(name);
    string flag;
    iss >> flag;

    set<string> files = fileSystemPtr->getFileNames();
    int counter = 0;

    MetadataDisplayVisitor visitor;

    regex anyOtherFlag("-[a-zA-Z]");
    if (flag.empty() || flag == "-m") {
        for (auto it = files.begin(); it != files.end(); ++it) {
            if (flag.empty()) {
                cout << left << setw(NAME_LENGTH) << *it;
                counter++;
                if (counter % EVEN == 0) {
                    cout << endl;
                }
            }
            else if (flag == "-m") {
                AbstractFile* file = fileSystemPtr->openFile(*it);
                if (file) {
                    file->accept(&visitor);
                    fileSystemPtr->closeFile(file);
                }
            }
        }
        //check final newline if uneven number of files
        if (flag.empty() && counter % EVEN != 0) {
            cout << endl;
        }
    }
    else if (regex_match(flag, anyOtherFlag)) {
        cout << "INVALID FLAG CALLED" << endl;
        return INVALID_FLAG;
    }
    else {
        displayInfo();
        return LS_COMMAND_FAILED;
    }
    return SUCCESS;
}

void LSCommand::displayInfo() {
    cout << "ls shows a list of files in the file system, ls can be invoked with the command: ls [-m]" << endl;
}
