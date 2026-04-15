/**
 * CommandPrompt.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the CommandPrompt class and its methods for handling user interaction
 * with the file system. It allows users to enter commands, view help text, and execute commands
 * with optional arguments.
 */

#include "mockos/CommandPrompt.h"
#include <iostream>
#include <string>
#include "mockos/Constants.h"

using namespace std;

CommandPrompt::CommandPrompt() : fileSystemPtr(nullptr), fileFactoryPtr(nullptr) {
}

void CommandPrompt::setFileSystem(AbstractFileSystem *absFileSysPtr) {
    fileSystemPtr = absFileSysPtr;
}

void CommandPrompt::setFileFactory(AbstractFileFactory *absFileFacPtr) {
    fileFactoryPtr = absFileFacPtr;
}

int CommandPrompt::addCommand(std::string name, AbstractCommand *command) {
    int initSize = commandPtrs.size();
    commandPtrs.insert({name, command});
    int finalSize = commandPtrs.size();
    if (initSize < finalSize) {
        return SUCCESS;
    }
    else {
        return FAIL_TO_INSERT_COMMAND;
    }
}

void CommandPrompt::listCommands() {
    for (auto it: commandPtrs) {
        cout << it.first << endl;
    }
}

std::string CommandPrompt::prompt() {
    cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;
    cout << "$  ";
    string line;
    getline(cin, line);
    return line;
}

int CommandPrompt::run() {
    while (true) {
        string result = prompt();
        if (result == "") {
            continue;
        }
        //user quits
        if (result == "q") {
            return USER_QUIT;
        }
        //user calls for help
        if (result == "help") {
            listCommands();
            continue;
        }
        //check for more than one word
        size_t space = result.find(' ');
        //input is one command
        if (space == string::npos) {
            map<string, AbstractCommand *>::iterator it = commandPtrs.find(result);
            if (it != commandPtrs.end()) {
                int code = it->second->execute("");
                if (code != SUCCESS) {
                    cout << "COMMAND FAILED TO EXECUTE" << endl;
                }
            } else {
                cout << "COMMAND NOT FOUND" << endl;
            }
        }
        //input is multiple commands
        else {
            istringstream iss(result);
            string firstInput;
            iss >> firstInput;

            if (firstInput == "help") {
                string secondInput;
                iss >> secondInput;
                map<string, AbstractCommand *>::iterator it = commandPtrs.find(secondInput);
                if (it != commandPtrs.end()) {
                    it->second->displayInfo();
                }
                else {
                    cout << "COMMAND DOES NOT EXIST" << endl;
                }
            }
            else {
                map<string, AbstractCommand *>::iterator it = commandPtrs.find(firstInput);
                if (it != commandPtrs.end()) {
                    string remainingInput;
                    getline(iss, remainingInput);
                    int code = it->second->execute(remainingInput);
                    if (code != SUCCESS) {
                        cout << "COMMAND FAILED TO EXECUTE" << endl;
                    }
                }
            }
        }
    }
}
