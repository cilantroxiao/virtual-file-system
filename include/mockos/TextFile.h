/**
* TextFile.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the TextFile class, which implements the AbstractFile interface.
 * It represents a basic text file and declares the functions that allow the user to manage (read,
 * write, append) to a text file.
 */

#include "AbstractFile.h"
#ifndef MOCKOS_TEXTFILE_H
#define MOCKOS_TEXTFILE_H

class TextFile: public AbstractFile {
    std::vector<char> fileContents;
    std::string fileName;

public:
    TextFile(std::string fileName);
    unsigned int getSize();
    std::string getName();
    int write(std::vector<char>);
    int append(std::vector<char>);
    std::vector<char> read();
    void accept(AbstractFileVisitor *visitor);
    AbstractFile* clone(std::string newName) override;
};
#endif