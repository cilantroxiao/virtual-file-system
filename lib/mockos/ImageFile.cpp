/**
 * ImageFile.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the ImageFile class, which represents a nxn image file containing
 * characters ('X' or ' '). It implements the AbstractFile interface and supports reading,
 * writing, and cloning via the prototype pattern. However, appending to an image file is
 * not allowed.
 */

#include "mockos/ImageFile.h"
#include <iostream>
#include "mockos/AbstractFile.h"
#include "mockos/AbstractFileVisitor.h"
#include "mockos/Constants.h"

using namespace std;

ImageFile::ImageFile(std::string name): fileName(name), imageSize(0) {
}

unsigned int ImageFile::getSize() {
    return imageData.size();
}

unsigned int ImageFile::getDimensions() {
    return imageSize;
}

std::string ImageFile::getName() {
    return fileName;
}

int ImageFile::write(std::vector<char> fileCopy) {
    //grab last char
    char sizeChar = fileCopy.back();
    if (sizeChar == '\n') {
        fileCopy.pop_back();
        sizeChar = fileCopy.back();
    }
    //convert char to integer
    int n = sizeChar - '0';
    int expectedSize = n * n;

    //check content before copying
    for (int i = 0; i < expectedSize; ++i) {
        if (fileCopy[i] != 'X' && fileCopy[i] != ' ') {
            imageData.clear();
            imageSize = 0;
            return INVALID_FILE_CONTENT;
        }
    }
    std::copy(fileCopy.begin(), fileCopy.begin() + expectedSize, std::back_inserter(imageData));
    imageSize = n;

    return SUCCESS;
}

int ImageFile::append(std::vector<char> data) {
    cout << "Cannot append to an image file." << endl;
    return APPEND_NOT_ALLOWED;
}

int ImageFile::getIndex(int x, int y) {
    return y * imageSize + x;
}

vector<char> ImageFile::read() {
    //print from top to bottom, left to right
    vector<char> img;
    for (int i = imageSize - 1; i >= 0; i--) {
        for (int j = 0; j < imageSize; j++) {
            int index = getIndex(j, i);
            img.push_back(imageData[index]);
        }
    }
    return img;
}

void ImageFile::accept(AbstractFileVisitor *visitor) {
    visitor->visit_ImageFile(this);
}

AbstractFile *ImageFile::clone(std::string newName) {
    ImageFile *newFile = new ImageFile(newName);
    std::vector<char> data = imageData;
    data.push_back(static_cast<char>(imageSize + '0'));
    newFile->write(data);
    return newFile;
}
