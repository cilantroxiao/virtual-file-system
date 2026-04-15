/**
 * RenameParsingStrategy.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the RenameParsingStrategy class and the parse method.
 * The method splits the input into a sequence of arguments (copy followed by a delete command)
 * in order to rename a file.
 */

#include "mockos/RenameParsingStrategy.h"
#include <sstream>
#include <string>
#include "mockos/AbstractParsingStrategy.h"

using namespace std;

vector<string> RenameParsingStrategy::parse(string input) {
    istringstream iss(input);
    string existingFile, newName;
    iss >> existingFile >> newName;

    return {existingFile + " " + newName,existingFile};
}
