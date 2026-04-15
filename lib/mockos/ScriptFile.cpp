/**
 * ScriptFile.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the ScriptFile class, which represents a list of terminal commands
 * that would be run in per line upon calling "run".
 * It implements the AbstractFile interface and supports reading,writing, and cloning via the prototype pattern.
 * However, appending to an image file is not allowed.
 */

#include "mockos/ScriptFile.h"
#include <iostream>
#include "mockos/AbstractFile.h"
#include "mockos/AbstractFileVisitor.h"
#include "mockos/Constants.h"

using namespace std;

ScriptFile::ScriptFile(std::string name): fileName(name){
}

unsigned int ScriptFile::getSize() {
    return scriptContents.size();
}

std::string ScriptFile::getName() {
    return fileName;
}

int ScriptFile::write(std::vector<char> fileCopy) {
    scriptContents.clear();
    std::copy(fileCopy.begin(), fileCopy.end(), std::back_inserter(scriptContents));
    return 0;
}

int ScriptFile::append(std::vector<char> v) {
    scriptContents.push_back('\n');
    for (unsigned int i = 0; i < v.size(); i++) {
        scriptContents.push_back(v[i]);
    }
    return 0;
}

vector<char> ScriptFile::read() {
    vector<char> text;
    for(unsigned int i = 0; i < getSize(); i++) {
        //std::cout << fileContents[i];
        text.push_back(scriptContents[i]);
    }
    return text;
}

void ScriptFile::accept(AbstractFileVisitor *visitor) {
    visitor->visit_ScriptFile(this);
}

AbstractFile *ScriptFile::clone(std::string newName) {
    ScriptFile *newFile = new ScriptFile(newName);
    newFile->write(scriptContents);
    return newFile;
}
