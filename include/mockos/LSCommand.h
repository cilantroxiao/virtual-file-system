/**
 * LSCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the LSCommand class, which implements the AbstractCommand interface.
 * It declares the methods and member variables needed to list files in the file system,
 * with optional metadata display using the -m flag.
 */

#ifndef MOCKOS_LS_COMMAND_H
#define MOCKOS_LS_COMMAND_H
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class LSCommand : public AbstractCommand {
    AbstractFileSystem* fileSystemPtr;
public:
    LSCommand(AbstractFileSystem* fileSystemPtr);
    virtual ~LSCommand() = default;
    int execute(std::string) override;
    void displayInfo() override;
};
#endif