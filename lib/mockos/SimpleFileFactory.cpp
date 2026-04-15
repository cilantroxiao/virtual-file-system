/**
 * SimpleFileFactory.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the SimpleFileFactory class and the createFile method.
 * The method returns a new instance of a file based on the file extension.
 */

#include "mockos/SimpleFileFactory.h"
#include "mockos/ImageFile.h"
#include "mockos/ScriptFile.h"
#include "mockos/TextFile.h"

using namespace std;

AbstractFile *SimpleFileFactory::createFile(std::string name) {
    AbstractFile *newFile = nullptr;
    string extension = name.substr(name.find_last_of(".") + 1);

    if (extension == "txt") {
        newFile = new TextFile(name);
    }
    else if (extension == "img") {
        newFile = new ImageFile(name);
    }
    else if (extension == "scp") {
        newFile = new ScriptFile(name);
    }
    else {
        return nullptr;
    }
    return newFile;
}
