/**
 * TouchCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the TouchCommand class, which implements the AbstractCommand interface.
 * It defines the methods that will implement file creation.
 */

#ifndef MOCKOS_TOUCH_COMMAND_H
#define MOCKOS_TOUCH_COMMAND_H
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include <string>

class TouchCommand : public AbstractCommand {
    AbstractFileSystem* fileSystemPtr;
    AbstractFileFactory* fileFactoryPtr;
public:
    TouchCommand(AbstractFileSystem* fileSystemPtr, AbstractFileFactory* fileFactoryPtr);
    virtual ~TouchCommand() = default;
    int execute(std::string) override;
    void displayInfo() override;
};
#endif