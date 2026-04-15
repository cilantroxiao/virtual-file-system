/**
* CatCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the CatCommand class and its methods for displaying and optionally
 * appending content to files in the file system depending on the user's input.
 */

#ifndef MOCKOS_CAT_COMMAND_H
#define MOCKOS_CAT_COMMAND_H
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class CatCommand : public AbstractCommand {
    AbstractFileSystem *fileSystemPtr;

public:
    CatCommand(AbstractFileSystem *fileSystemPtr);
    virtual ~CatCommand() = default;
    int execute(std::string) override;
    void displayInfo() override;
};
#endif
