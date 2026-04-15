#include "mockos/TextFile.h"
#include <iostream>
#include "mockos/AbstractFileSystem.h"
#include "mockos/ImageFile.h"
#include "mockos/SimpleFileSystem.h"

int main(int argc, char *argv[]) {
    ImageFile imgFile("testImage");
    std::cout << "Testing getName(): " << imgFile.getName() << std::endl;

    std::vector<char> validInput = {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'};
    int writeResult = imgFile.write(validInput);
    std::cout << "Writing with a valid input : " << writeResult << " (Expected: 0)" << std::endl;

    std::cout << "Reading contents of image: " <<std::endl;
    imgFile.read();
    std::cout << std::endl;

    std::vector<char> invalidInput = {'X', 'Y', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'};
    writeResult = imgFile.write(invalidInput);
    std::cout << "Writing with an invalid input : " << writeResult << " (Expected: -2)" << std::endl;


    std::cout << std::endl;

    int appendResult = imgFile.append(validInput);
    std::cout << "Trying to append... " << appendResult << " (Expected: -1)" <<std::endl;

    std::cout << "Size of image is: " << imgFile.getSize() << std::endl;

    SimpleFileSystem fileSystem;

    AbstractFile* file1 = new TextFile("file1.txt");
    AbstractFile* file2 = new ImageFile("file2.img");
    AbstractFile* file3 = new TextFile("file3.txt");

    //Add file
    int addFileResult1 = fileSystem.addFile("file1.txt", file1);
    std::cout << "file1.txt result is: " << addFileResult1 << std::endl;
    int addFileResult2 = fileSystem.addFile("file1.img", file2);
    std::cout << "file2.txt result is: " << addFileResult2 << std::endl;
    int addFileResult3 = fileSystem.addFile("file3.txt", file3);
    std::cout << "file3.txt result is: " << addFileResult3 << std::endl;

    //Create file
    int createFileResult1 = fileSystem.createFile("file4.txt");
    std::cout << "file1.txt result is: " << addFileResult1 << std::endl;
    int createFileResult2 = fileSystem.createFile("file5.img");
    std::cout << "file2.txt result is: " << addFileResult2 << std::endl;

    //Open file
    AbstractFile* openedFile = fileSystem.openFile("file1.txt");
    if (openedFile != nullptr) {
        std::cout << "File 'file1.txt' opened successfully." << std::endl;
    } else {
        std::cout << "File 'file1.txt' failed to open successfully" << std::endl;
    }

    //Write to file
    std::vector<char> writeContent = {'H', 'e', 'l', 'l', 'o'};
    writeResult = openedFile->write(writeContent);
    std::cout << "Writing to file1.txt result: " << writeResult << std::endl;

    //Read to file
    std::cout << "Reading from file1.txt: ";
    openedFile->read();
    std::cout << std::endl;

    //Delete files
    int deleteFileResult = fileSystem.deleteFile("file3.txt");
    std::cout << "Delete file result (file3.txt): " << deleteFileResult << std::endl;
    int deleteFileResult2 = fileSystem.deleteFile("fake.txt");
    std::cout << "Delete file result (fake.txt): " << deleteFileResult2 << std::endl;

    //Close file
    int closeFileResult = fileSystem.closeFile(openedFile);
    std::cout << "Close file result: " << closeFileResult << std::endl;
    delete file1;
    delete file2;
    delete file3;
    return 0;
}
