/**
 * PasswordProxy.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file declares the PasswordProxy class, which implements the AbstractFile interface.
 * It defines the methods that will ask user for a password before proceeding to the following operations
 * (read, write, append, etc.)
 */

#ifndef MOCKOS_PASSWORDPROXY_H
#define MOCKOS_PASSWORDPROXY_H
#include "AbstractFile.h"

class PasswordProxy : public AbstractFile{
    AbstractFile * protectedFile;
    std::string password;
public:
    PasswordProxy(AbstractFile * protectedFile, std::string password);
    ~PasswordProxy();
    std::vector<char> read();
    int write(std::vector<char>);
    int append(std::vector<char>);
    unsigned int getSize();
    std::string getName();
    void accept(AbstractFileVisitor *visitor);
    AbstractFile* clone(std::string newName) override;

protected:
    std::string passwordPrompt();
    bool verifyPassword();
};
#endif