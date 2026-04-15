/**
 * SimpleFileSystem.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the SimpleFileSystem class and its methods for managing file objects.
 * The methods include adding, deleting, opening, and closing files.
 */

#include "mockos/SimpleFileSystem.h"
#include <iostream>
#include <string>
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/Constants.h"

using namespace std;

int SimpleFileSystem::addFile(std::string name, AbstractFile *abFileptr) {
    auto it = files.find(name);
    if (it != files.end()) {
        return DUPLICATE_FILE;
    }
    if (abFileptr == nullptr) {
        return NULL_PTR;
    }
    files[name] = abFileptr;
    return SUCCESS;
}

int SimpleFileSystem::deleteFile(std::string name) {
    auto it = files.find(name);
    if (it == files.end()) {
        return FILE_DOES_NOT_EXIST;
    }
    AbstractFile *file_ptr = files[name];
    auto it2 = openFiles.find(file_ptr);
    if (it2 != openFiles.end()) {
        return FILE_ALREADY_OPENED;
    }
    openFiles.erase(file_ptr);
    delete file_ptr;
    files.erase(it);
    return SUCCESS;
}

AbstractFile *SimpleFileSystem::openFile(std::string name) {
    auto it = files.find(name);
    if (it == files.end()) {
        return nullptr;
    }
    AbstractFile *file_ptr = files[name];
    auto it2 = openFiles.find(file_ptr);
    if (it2 == openFiles.end()) {
        openFiles.insert(file_ptr);
        return file_ptr;
    }
    return nullptr;
}

int SimpleFileSystem::closeFile(AbstractFile *absFileptr) {
    auto it = openFiles.find(absFileptr);
    if (it == openFiles.end()) {
        return FILE_NOT_OPENED;
    }
    openFiles.erase(it);
    return SUCCESS;
}

set<string> SimpleFileSystem::getFileNames() {
    set<string> fileNames;
    for (auto it: files) {
        fileNames.insert(it.first);
    }
    return fileNames;
}
