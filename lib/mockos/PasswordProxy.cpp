/**
 * PasswordProxy.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This cpp file defines the PasswordProxy class, which restricts access to the Abstract File
 * by requiring the user to enter a password before they can read, write, append, etc.
 */

#include "mockos/PasswordProxy.h"
#include "mockos/TextFile.h"
#include <iostream>
#include "mockos/Constants.h"

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile * protectedFile, string password) : password(password), protectedFile(protectedFile) {
    //empty af
}
PasswordProxy::~PasswordProxy() {
    if (protectedFile != nullptr) {
        delete protectedFile;
    }
}

string PasswordProxy::passwordPrompt() {
    string password;
    cout << "Input your password for file " << getName() <<  endl;
    getline(cin >> ws, password);
    return password;
}

bool PasswordProxy::verifyPassword() {
    string inputString = passwordPrompt();
    if (inputString == password) {
        return true;
    }
    return false;
}

vector<char> PasswordProxy::read() {
    if (verifyPassword()) {
        return protectedFile->read();
    }
    else {
        return vector<char>();
    }
}

int PasswordProxy::write(vector<char> contents) {
    if (verifyPassword()) {
        return protectedFile->write(contents);
    }
    else {
        return INVALID_PASSWORD;
    }
}

int PasswordProxy::append(vector<char> contents) {
    if (verifyPassword()) {
        return protectedFile->append(contents);
    }
    else {
        return INVALID_PASSWORD;
    }
}

unsigned int PasswordProxy::getSize() {
    return protectedFile->getSize();
}

string PasswordProxy::getName() {
    return protectedFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor *visitor) {
    if (verifyPassword()) {
        protectedFile->accept(visitor);
    }
}

AbstractFile* PasswordProxy::clone(std::string newName) {
    AbstractFile* clonedPtr = protectedFile->clone(newName);
    return new PasswordProxy(clonedPtr, password);
}