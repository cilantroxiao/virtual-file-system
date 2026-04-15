/**
 * MacroCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the MacroCommand class, which implements the AbstractCommand interface.
 * It allows multiple commands to be executed at once.
 */

#ifndef MOCKOS_MACROCOMMAND_H
#define MOCKOS_MACROCOMMAND_H
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractParsingStrategy.h"

class MacroCommand : public AbstractCommand {
    AbstractFileSystem* fileSystemPtr;
    std::vector<AbstractCommand *> commands;
    AbstractParsingStrategy* parsingStrategy;
public:
    MacroCommand(AbstractFileSystem* fileSystemPtr);
    virtual ~MacroCommand() = default;
    int execute(std::string) override;
    void displayInfo() override;
    void addCommand(AbstractCommand* command);
    void setParseStrategy(AbstractParsingStrategy* strategy);
};
#endif