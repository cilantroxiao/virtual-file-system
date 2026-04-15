/**
* CatCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the CatCommand class and its methods for displaying and optionally
 * appending content to files in the file system depending on the user's input.
 */

#include "mockos/CatCommand.h"
#include <iostream>
#include <regex>
#include <sstream>
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/Constants.h"

using namespace std;
CatCommand::CatCommand(AbstractFileSystem *fileSystemPtr) : fileSystemPtr(fileSystemPtr) {
}

int CatCommand::execute(string name) {
    istringstream iss(name);
    string fileName, flag;
    iss >> fileName >> flag;

    if (fileName.empty() || fileName == "-a") {
        cout << "NO VALID FILENAME PROVIDED." << endl;
        return FILE_DOES_NOT_EXIST;
    }

    AbstractFile *file = fileSystemPtr->openFile(fileName);
    if (!file) {
        cout << "FILE OPEN ERROR" << endl;
        return FILE_OPEN_FAIL;
    }

    regex anyOtherFlag("-[a-zA-Z]");
    if (flag == "-a") {
        BasicDisplayVisitor *visitor = new BasicDisplayVisitor();
        file->accept(visitor);
        delete visitor;
    }
    else if (regex_match(flag, anyOtherFlag)) {
        cout << "INVALID FLAG CALLED" << endl;
        return INVALID_FLAG;
    }

    cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving"
    << endl;

    string line;
    vector<char> input;

    while (true) {
        getline(cin, line);

        if (line == ":q") {
            fileSystemPtr->closeFile(file);
            return SUCCESS;
        }

        if (line == ":wq") {
            if (!input.empty() && input.back() == '\n') {
                input.pop_back();
            }

            int result;
            if (flag == "-a") {
                result = file->append(input);
            } else {
                result = file->write(input);
                if (result != 0) {
                    fileSystemPtr->closeFile(file);
                    return result;
                }
            }

            fileSystemPtr->closeFile(file);
            return result;
        }

        for (char c: line) {
            input.push_back(c);
        }
        input.push_back('\n');
    }
}

void CatCommand::displayInfo() {
    cout << "cat allows you to write to a file, cat can be invoked with the command: cat <filename> [-a]" << endl;
}
