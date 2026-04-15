/**
* BasicDisplayVisitor.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the BasicDisplayVisitor class and its visit methods for displaying the
 * contents of TextFile and ImageFile objects. The TextFile is printed as plain text, while the
 * ImageFile is rendered in a nxn grid format based on its dimensions.
 */

#include "mockos/BasicDisplayVisitor.h"
#include <iostream>
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"

using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile *file) {
    vector<char> text = file->read();
    for (unsigned int i = 0; i < text.size(); i++) {
        cout << text[i];
    }
    cout << endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile *file) {
    vector<char> img = file->read();
    unsigned int imageSize = file->getDimensions();

    for (unsigned int i = 0; i < imageSize; ++i) {
        for (unsigned int j = 0; j < imageSize; ++j) {
            int index = i * imageSize + j;
            cout << img[index];
        }
        cout << endl;
    }
}
void BasicDisplayVisitor::visit_ScriptFile(ScriptFile *file) {
    vector<char> text = file->read();
    for (unsigned int i = 0; i < text.size(); i++) {
        cout << text[i];
    }
    cout << endl;
}
