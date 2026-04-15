/**
* MetadataDisplayVisitor.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the MetadataDisplayVisitor class, which implements the
 * AbstractFileVisitor interface. It defines methods for visiting TextFile and ImageFile
 * objects to display their corresponding metadata.
 */

#ifndef MOCKOS_METADATADISPLAYVISITOR_H
#define MOCKOS_METADATADISPLAYVISITOR_H
#include <string>
#include <sstream>
#include "AbstractFileVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
    std::string fileType;
public:
    void visit_ImageFile(ImageFile* file);
    void visit_TextFile(TextFile* file);
    void visit_ScriptFile(ScriptFile* file);
};

#endif