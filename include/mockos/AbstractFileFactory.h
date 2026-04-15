/**
* AbstractCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file outlines the abstract interface of the SimpleFileFactory class used in this project.
 */

#pragma once


#ifndef MOCKOS_ABSTRACTFILEFACTORY_H
#define MOCKOS_ABSTRACTFILEFACTORY_H
#include "AbstractFile.h"
class AbstractFileFactory {
public:
    virtual AbstractFile* createFile(std::string name)=0;
};
#endif