/**
 * ImageFile.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the ImageFile class, which inherits from the AbstractFile interface.
 * The class represents a square grid image file and allows reading, writing, and cloning to the
 * file but does not allow appending.
 */

#ifndef MOCKOS_IMAGEFILE_H
#define MOCKOS_IMAGEFILE_H

#include "AbstractFile.h"

class ImageFile: public AbstractFile {
    int getIndex(int x, int y);
    std::string fileName;
    std::vector<char> imageData;
    int imageSize;

public:
    ImageFile(std::string name);
    unsigned int getSize();
    std::string getName();
    int write(std::vector<char> fileCopy);
    int append(std::vector<char> data);
    std::vector<char> read();
    void accept(AbstractFileVisitor *visitor);
    unsigned int getDimensions();
    AbstractFile* clone(std::string newName) override;
};
#endif
