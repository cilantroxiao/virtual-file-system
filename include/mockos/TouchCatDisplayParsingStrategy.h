/**
 * TouchCatDisplayParsingStrategy.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the TouchCatDisplayParsingStrategy class, which implements
 * the AbstractParsingStrategy interface.
 */

#ifndef TOUCHCATDISPLAYPARSINGSTRATEGY_H
#define TOUCHCATDISPLAYPARSINGSTRATEGY_H
#include <string>
#include "AbstractParsingStrategy.h"

class TouchCatDisplayParsingStrategy : public AbstractParsingStrategy {
public:
    std::vector<std::string> parse(std::string input) override;
};

#endif
