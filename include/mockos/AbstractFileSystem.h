/**
* AbstractCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file outlines the abstract interface of the SimpleFileSystem class used in this project.
 */


#pragma once
#include <set>

#include "AbstractFile.h"

#ifndef MOCKOS_ABSTRACTFILESYSTEM_H
#define MOCKOS_ABSTRACTFILESYSTEM_H
class AbstractFileSystem {
public:
    virtual int addFile(std::string name, AbstractFile * abFileptr)=0;
    virtual int deleteFile(std::string name)=0;
    virtual AbstractFile* openFile(std::string name)=0;
    virtual int closeFile(AbstractFile* abFileptr)=0;
    virtual std::set<std::string> getFileNames() = 0;
};
#endif