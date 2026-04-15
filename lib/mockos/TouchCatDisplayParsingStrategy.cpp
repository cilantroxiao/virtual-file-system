/**
 * TouchCatDisplayParsingStrategy.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the TouchCatDisplayParsingStrategy class.
 */

#include "mockos/TouchCatDisplayParsingStrategy.h"

#include <sstream>
#include <string>
#include "mockos/AbstractParsingStrategy.h"

using namespace std;

vector<string> TouchCatDisplayParsingStrategy::parse(string input) {
    istringstream iss(input);
    string file;
    iss >> file;
    return {file, file, file};
}