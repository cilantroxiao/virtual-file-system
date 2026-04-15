/**
* AbstractCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file outlines the abstract interface of the filetype classes used in this project.
 */

#pragma once
#include <vector>
#include <sstream>

class AbstractFileVisitor;

class AbstractFile {
    public:
    virtual std::vector <char> read() = 0;
    virtual int write(std::vector<char>) = 0;
    virtual int append(std::vector<char>) = 0;
    virtual unsigned int getSize() = 0;
    virtual std::string getName() = 0;
    virtual void accept(AbstractFileVisitor* visitor)=0;
    virtual AbstractFile* clone(std::string newName) = 0;
    ~AbstractFile()=default;
};
