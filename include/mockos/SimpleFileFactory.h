/**
* SimpleFileFactory.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the SimpleFileFactory class, which implements
 * the AbstractFileFactory interface. It declares the createFile method to create a file
 * based on the type (TextFile, ImageFile).
 */

#ifndef MOCKOS_SIMPLEFILEFACTORY_H
#define MOCKOS_SIMPLEFILEFACTORY_H
#include "AbstractFile.h"
#include "AbstractFileFactory.h"

class SimpleFileFactory: public AbstractFileFactory {
public:
    virtual AbstractFile* createFile(std::string name);
};
#endif