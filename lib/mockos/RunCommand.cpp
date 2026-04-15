/**
 * RunCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This file defines the run command which will run a script that a user supplies and
 * execute all the following commands in the script file.
 */

#include "mockos/RunCommand.h"
#include <fstream>
#include <iostream>
#include "mockos/Constants.h"

using namespace std;

RunCommand::RunCommand(AbstractFileSystem *fileSystemPtr, CommandPrompt *prompt): fileSystemPtr(fileSystemPtr),
    prompt(prompt) {
}


void CommandPrompt::runCommand(string command) {
    if (command == "") {
        return;
    }
    //user quits
    if (command == "q") {
        return;
    }
    //user calls for help
    if (command == "help") {
        listCommands();
        return;
    }
    //check for more than one word
    size_t space = command.find(' ');
    //input is one command
    if (space == string::npos) {
        map<string, AbstractCommand *>::iterator it = commandPtrs.find(command);
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
        istringstream iss(command);
        string firstInput;
        iss >> firstInput;

        if (firstInput == "help") {
            string secondInput;
            iss >> secondInput;
            map<string, AbstractCommand *>::iterator it = commandPtrs.find(secondInput);
            if (it != commandPtrs.end()) {
                it->second->displayInfo();
            } else {
                cout << "COMMAND DOES NOT EXIST" << endl;
            }
        } else {
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


int RunCommand::execute(string fileName) {
    istringstream iss(fileName);
    string name;
    iss >> name;
    ifstream scriptFile(name);
    if (!scriptFile.is_open()) {
        cout << "Failed to open script file." << endl;
        return FILE_OPEN_FAIL;
    }

    //read all the lines in the script
    string line;
    while (getline(scriptFile, line)) {
        if (line.empty()) {
            continue;
        }
        //run command
        prompt->runCommand(line);
    }

    return SUCCESS;
}

void RunCommand::displayInfo() {
    cout << "run executes a script file of commands: run <filename>" << endl;
}
