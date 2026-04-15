/**
* AbstractCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file outlines the abstract interface of the parsing strategy classes used in this project.
 */
#ifndef MOCKOS_ABSTRACTPARSINGSTRATEGY_H
#define MOCKOS_ABSTRACTPARSINGSTRATEGY_H
#include <vector>
#include <string>

class AbstractParsingStrategy {
public:
    virtual std::vector<std::string> parse(std::string) = 0;
};
#endif