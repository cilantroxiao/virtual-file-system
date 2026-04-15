/**
* RemoveCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the RemoveCommand class, which implements the AbstractCommand interface.
 * It provides methods to delete a file from the file system.
 */

#ifndef MOCKOS_REMOVE_COMMAND_H
#define MOCKOS_REMOVE_COMMAND_H
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class RemoveCommand : public AbstractCommand {
    AbstractFileSystem* fileSystemPtr;
public:
    RemoveCommand(AbstractFileSystem* fileSystemPtr);
    virtual ~RemoveCommand() = default;
    int execute(std::string) override;
    void displayInfo() override;
};
#endif