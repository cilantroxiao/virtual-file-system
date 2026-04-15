/**
 * DisplayCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the DisplayCommand class, which implements the AbstractCommand interface.
 * The class provides functionality to open and display the contents of a file in the file system.
 */


#ifndef MOCKOS_DISPLAY_COMMAND_H
#define MOCKOS_DISPLAY_COMMAND_H
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class DisplayCommand : public AbstractCommand {
    AbstractFileSystem* fileSystemPtr;
public:
    DisplayCommand(AbstractFileSystem* fileSystemPtr);
    virtual ~DisplayCommand() = default;
    int execute(std::string) override;
    void displayInfo() override;
};
#endif