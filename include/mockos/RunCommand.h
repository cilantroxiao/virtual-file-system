/**
* RunCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This file defines the run command which will run a script that a user supplies and
 * execute all the following commands in the script file.
 */

#ifndef MOCKOS_RUNCOMMAND_H
#define MOCKOS_RUNCOMMAND_H
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "CommandPrompt.h"

class RunCommand : public AbstractCommand {
    AbstractFileSystem* fileSystemPtr;
    CommandPrompt* prompt;

public:
    RunCommand(AbstractFileSystem* fs, CommandPrompt* prompt);
    int execute(std::string filename) override;
    void displayInfo() override;
};

#endif