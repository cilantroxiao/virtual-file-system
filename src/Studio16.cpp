#include "mockos/TextFile.h"
#include <iostream>

int main(int argc, char *argv[]) {

    AbstractFile* file = new TextFile(argv[1]);
    std::vector<char> writeContent = {'a', 'b', 'c'};
    file->write(writeContent);
    std::cout << "Wrote to " << file->getName() << ": ";
    file->read();
    std::cout << std::endl;


    std::vector<char> appendContent = {'d', 'e', 'f', 'g', 'h'};
    file->write(appendContent);
    std::cout << "File content after appending: ";
    file->read();
    std::cout << std::endl;

    std::cout << "File size is now: " <<  file->getSize() << std::endl;

    return 0;
}
