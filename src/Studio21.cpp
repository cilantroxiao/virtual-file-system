#include <iostream>
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/CommandPrompt.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TouchCommand.h"

using namespace std;

int main(int argc, char *argv[]) {
    AbstractFileSystem* systemPtr = new SimpleFileSystem();
    AbstractFileFactory* factoryPtr = new SimpleFileFactory();
    TouchCommand* touch = new TouchCommand(systemPtr, factoryPtr);
    CommandPrompt prompt;
    prompt.setFileSystem(systemPtr);
    prompt.setFileFactory(factoryPtr);
    prompt.addCommand("touch", touch);
    prompt.run();
    delete touch;
    delete factoryPtr;
    delete systemPtr;
    return 0;
}
