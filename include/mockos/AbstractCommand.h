/**
* AbstractCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file outlines the abstract interface of the command classes used in this project.
 */

#ifndef MOCKOS_ABSTRACTCOMMAND_H
#define MOCKOS_ABSTRACTCOMMAND_H
#include <string>
class AbstractCommand {
public:
    virtual ~AbstractCommand() = default;
    virtual int execute(std::string) = 0;
    virtual void displayInfo() = 0;
};




#endif