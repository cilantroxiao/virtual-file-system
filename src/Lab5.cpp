/**
 * Lab5.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This is the main function that sets up and runs the file system.
 * It adds all commands and parsing strategies used for Lab 5.
 */

#include <iostream>
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/CommandPrompt.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TouchCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/LSCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/CopyCommand.h"
#include "mockos/MacroCommand.h"
#include "mockos/RenameParsingStrategy.h"
#include "mockos/TouchCatDisplayParsingStrategy.h"
#include "mockos/Constants.h"
#include "mockos/RunCommand.h"

using namespace std;

int main(int argc, char *argv[]) {
    AbstractFileSystem* systemPtr = new SimpleFileSystem();
    AbstractFileFactory* factoryPtr = new SimpleFileFactory();
    CommandPrompt prompt;
    prompt.setFileSystem(systemPtr);
    prompt.setFileFactory(factoryPtr);

    TouchCommand* touch = new TouchCommand(systemPtr, factoryPtr);
    LSCommand* ls = new LSCommand(systemPtr);
    RemoveCommand* rm = new RemoveCommand(systemPtr);
    CatCommand* cat = new CatCommand(systemPtr);
    DisplayCommand* ds = new DisplayCommand(systemPtr);
    CopyCommand* cp = new CopyCommand(systemPtr);
    RunCommand* run = new RunCommand(systemPtr, &prompt);

    prompt.addCommand("touch", touch);
    prompt.addCommand("ls", ls);
    prompt.addCommand("rm", rm);
    prompt.addCommand("cat", cat);
    prompt.addCommand("ds", ds);
    prompt.addCommand("cp", cp);
    prompt.addCommand("run", run);


    MacroCommand * macroRename = new MacroCommand(systemPtr);
    macroRename->addCommand(cp);
    macroRename->addCommand(rm);
    RenameParsingStrategy* rename_strat = new RenameParsingStrategy();
    macroRename->setParseStrategy(rename_strat);
    prompt.addCommand("rn", macroRename);

    MacroCommand * macroTCD = new MacroCommand(systemPtr);
    macroTCD->addCommand(touch);
    macroTCD->addCommand(cat);
    macroTCD->addCommand(ds);


    TouchCatDisplayParsingStrategy* TCD_strat = new TouchCatDisplayParsingStrategy();
    macroTCD->setParseStrategy(TCD_strat);
    prompt.addCommand("tcd", macroTCD);

    MacroCommand * NO_STRATEGYMacro = new MacroCommand(systemPtr);
    prompt.addCommand("ns", NO_STRATEGYMacro);

    prompt.run();

    delete touch;
    delete ls;
    delete rm;
    delete cat;
    delete ds;
    delete cp;
    delete macroRename;
    delete rename_strat;
    delete macroTCD;
    delete TCD_strat;
    delete factoryPtr;
    delete systemPtr;
    return SUCCESS;
}
