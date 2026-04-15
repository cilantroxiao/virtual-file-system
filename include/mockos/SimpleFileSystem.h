/**
 * SimpleFileSystem.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the SimpleFileSystem class, which implements the AbstractFileSystem
 * interface. It declares the functions that add, create, delete, open, and close files.
 */

#ifndef MOCKOS_SIMPLEFILESYSTEM_H
#define MOCKOS_SIMPLEFILESYSTEM_H
#include <map>
#include <set>
#include <string>
#include "mockos/AbstractFile.h"
#include "mockos/AbstractFileSystem.h"

class SimpleFileSystem: public AbstractFileSystem {
    std::map<std::string, AbstractFile*> files;
    std::set<AbstractFile*> openFiles;
public:
    int addFile(std::string name, AbstractFile* abFileptr);
    int createFile(std::string name);
    int deleteFile(std::string name);
    AbstractFile* openFile(std::string name);
    int closeFile(AbstractFile * absFileptr);
    std::set<std::string> getFileNames();
};
#endif