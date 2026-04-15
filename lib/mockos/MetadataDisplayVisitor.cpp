/**
 * MetadataDisplayVisitor.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the MetadataDisplayVisitor class and its visit methods
 * for displaying metadata about each specific file type (file type, name, size).
 */

#include "mockos/MetadataDisplayVisitor.h"
#include <iomanip>
#include <iostream>
#include "mockos/Constants.h"
using namespace std;

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
    string fileType = "image";
    cout << left << setw(NAME_LENGTH) << file->getName() <<
    left << setw(NAME_LENGTH) << fileType   << left << setw(NAME_LENGTH) << file->getSize()<< endl;
}

void MetadataDisplayVisitor::visit_TextFile(TextFile* file) {
    string fileType = "text";
    cout << left << setw(NAME_LENGTH) << file->getName() <<
    left << setw(NAME_LENGTH) << fileType  << left << setw(NAME_LENGTH) << file->getSize()  << endl;
}
void MetadataDisplayVisitor::visit_ScriptFile(ScriptFile* file) {
    string fileType = "script";
    cout << left << setw(NAME_LENGTH) << file->getName() <<
        left << setw(NAME_LENGTH) << fileType  << left << setw(NAME_LENGTH) << file->getSize()  << endl;
}