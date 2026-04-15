/**
 * CopyCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the CopyCommand class, which implements the AbstractCommand interface.
 * The class provides functionality to copy an existing file in the file system and duplicate its contents
 * in a new separate file.
 */

#ifndef MOCKOS_COPY_COMMAND_H
#define MOCKOS_COPY_COMMAND_H
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class CopyCommand : public AbstractCommand {
    AbstractFileSystem* fileSystemPtr;

public:
    CopyCommand(AbstractFileSystem* fileSystemPtr);
    virtual ~CopyCommand() = default;
    int execute(std::string) override;
    void displayInfo() override;
};
#endif