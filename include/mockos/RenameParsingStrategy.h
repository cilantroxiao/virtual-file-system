/**
 * RenameParsingStrategy.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the RenameParsingStrategy class, which implements the
 * AbstractParsingStrategy interface. It provides a parse method used to split and reformat
 * input for renaming a specific file.
 */

#ifndef RENAMEPARSINGSTRATEGY_H
#define RENAMEPARSINGSTRATEGY_H
#include "AbstractParsingStrategy.h"


class RenameParsingStrategy : public AbstractParsingStrategy {
public:
    std::vector<std::string> parse(std::string input) override;
};

#endif
