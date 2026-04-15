/**
* BasicDisplayVisitor.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the BasicDisplayVisitor class, which implements the
 * AbstractFileVisitor interface. It provides visit methods for displaying the contents
 * of TextFile and ImageFile objects.
 */

#pragma once
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "ScriptFile.h"
#ifndef MOCKOS_BASICDISPLAYVISITOR_H
#define MOCKOS_BASICDISPLAYVISITOR_H

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
    void visit_TextFile(TextFile *file) override;
    void visit_ImageFile(ImageFile *file) override;
    void visit_ScriptFile(ScriptFile *file) override;
};

#endif
