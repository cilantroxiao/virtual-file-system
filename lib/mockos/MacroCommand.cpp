/**
 * MacroCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the MacroCommand class and its methods for executing a sequence
 * of commands as one composite command. It uses a parsing strategy to correctly split up
 * the commands.
 */

#include "mockos/MacroCommand.h"
#include <iostream>
#include "mockos/AbstractFileSystem.h"
#include "mockos/Constants.h"
using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem *fileSystemPtr) : fileSystemPtr(fileSystemPtr) {
}

int MacroCommand::execute(string name) {

    if (parsingStrategy == nullptr) {
        cout << "NO PARSING STRATEGY SET" << endl;
        return NO_STRATEGY;
    }
    vector<string> parsedInput = parsingStrategy->parse(name);

    if (parsedInput.size() != commands.size()) {
        cerr << "PARSED INPUTS AND EXPECTED INPUTS COUNT DO NOT MATCH" << endl;
        return COMMANDS_INPUT_MISMATCH;
    }
    for (auto i = 0; i < commands.size(); ++i) {
        int result = commands[i]->execute(parsedInput[i]);
        if (result != SUCCESS) {
            return result;
        }
    }
    return SUCCESS;
}

void MacroCommand::displayInfo() {
    cout << "This is a macro command which is composed of multiple commands combined (such as rename or touch cat display)." << endl;
}

void MacroCommand::addCommand(AbstractCommand *command) {
    commands.push_back(command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy *strategy) {
    parsingStrategy = strategy;
}
