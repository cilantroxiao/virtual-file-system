/**
 * RemoveCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the RemoveCommand class and its methods for deleting a file from the
 * file system. When prompted, the removeCommand will remove a file from the file system.
 */

#include "mockos/RemoveCommand.h"
#include "mockos/Constants.h"
#include <iostream>
using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* fileSystemPtr) : fileSystemPtr(fileSystemPtr) {
}

int RemoveCommand::execute(string name) {
    istringstream iss(name);
    string rm;
    iss >> rm;
    int result = fileSystemPtr->deleteFile(rm);
    if (result != SUCCESS) {
        cout << "FILE REMOVE FAILED" << endl;
        return REMOVE_FAIL;
    }
    cout<<"File removed successfully."<<endl;
    return SUCCESS;
}

void RemoveCommand::displayInfo() {
    cout << "remove deletes a file, remove can be invoked with the command: rm <filename>" << endl;
}
