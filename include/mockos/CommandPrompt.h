/**
* CommandPrompt.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the CommandPrompt class, which is responsible for managing
 * user interaction with the file system. It allows users to add commands, display available
 * commands, and execute commands with or without additional arguments.
 */

#ifndef MOCKOS_COMMANDPROMPT_H
#define MOCKOS_COMMANDPROMPT_H
#include <map>
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class CommandPrompt {
    std::map<std::string, AbstractCommand *> commandPtrs;
    AbstractFileSystem *fileSystemPtr;
    AbstractFileFactory *fileFactoryPtr;

public:
    CommandPrompt();
    ~CommandPrompt() = default;
    void setFileSystem(AbstractFileSystem *);
    void setFileFactory(AbstractFileFactory *);
    int addCommand(std::string, AbstractCommand *);
    int run();
    void runCommand(std::string result);

protected:
    void listCommands();
    std::string prompt();
};
#endif
