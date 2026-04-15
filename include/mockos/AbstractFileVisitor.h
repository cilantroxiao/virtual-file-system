/**
* AbstractCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file outlines the abstract interface of the visitors classes used in this project.
 */

#pragma once
#ifndef MOCKOS_ABSTRACTFILEVISITOR_H
#define MOCKOS_ABSTRACTFILEVISITOR_H
#include <functional>


#include "TextFile.h"
#include "ImageFile.h"
#include "ScriptFile.h"

class AbstractFileVisitor {
    public:
    virtual ~AbstractFileVisitor() = default;
    virtual void visit_TextFile(TextFile* file) = 0;
    virtual void visit_ImageFile(ImageFile* file) = 0;
    virtual void visit_ScriptFile(ScriptFile* file) = 0;
};
#endif