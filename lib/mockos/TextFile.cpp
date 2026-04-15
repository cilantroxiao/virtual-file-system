/**
* TextFile.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the TextFile class and its methods for reading, writing, appending,
 * and cloning text-based file content.
 */

#include "mockos/TextFile.h"
#include "mockos/AbstractFileVisitor.h"
#include <iostream>
#include "mockos/AbstractFile.h"

using namespace std;

TextFile::TextFile(std::string fileName) : fileName(fileName) {
}

unsigned int TextFile::getSize() {
    return fileContents.size();
}

std::string TextFile::getName() {
    return fileName;
}

int TextFile::write(std::vector<char> fileCopy) {
    fileContents.clear();
    std::copy(fileCopy.begin(), fileCopy.end(), std::back_inserter(fileContents));
    return 0;
}

int TextFile::append(std::vector<char> v) {
    for (unsigned int i = 0; i < v.size(); i++) {
        fileContents.push_back(v[i]);
    }
    return 0;
}
vector<char> TextFile::read() {
    vector<char> text;
    for(unsigned int i = 0; i < getSize(); i++) {
        //std::cout << fileContents[i];
        text.push_back(fileContents[i]);
    }
    return text;
}
void TextFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_TextFile(this);
}

AbstractFile* TextFile::clone(std::string newName) {
    TextFile* newFile = new TextFile(newName);
    newFile->write(fileContents);
    return newFile;
}
