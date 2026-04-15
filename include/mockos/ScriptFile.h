/**
* ScriptFile.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the ScriptFile class, which inherits from the AbstractFile interface.
 * The class represents a line-by-line list of commands in a file and allows all forms of access to the
 * file.
 */

#ifndef SCRIPTFILE_H
#define SCRIPTFILE_H

#include "AbstractFile.h"

class ScriptFile: public AbstractFile {
    std::string fileName;
    std::vector<char> scriptContents;

public:
    ScriptFile(std::string name);
    unsigned int getSize();
    std::string getName();
    int write(std::vector<char> fileCopy);
    int append(std::vector<char> data);
    std::vector<char> read();
    void accept(AbstractFileVisitor *visitor);
    AbstractFile* clone(std::string newName) override;
};
#endif

