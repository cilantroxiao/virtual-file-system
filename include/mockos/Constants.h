/**
* Constants.h
 * CSE 332S
 * Lab Num: 5
 * Author: Nicole Dai, Sandro Xiao
 *
 * This header file defines all the constants used in Lab 5, including return error codes and
 * other magic numbers used throughout the project.
 */

#ifndef MOCKOS_CONSTANTS_H
#define MOCKOS_CONSTANTS_H

enum ERROR_CODE {
    SUCCESS = 0,
    FILE_DOES_NOT_EXIST = -1,
    FILE_OPEN_FAIL = -2,
    FAIL_TO_INSERT_COMMAND = -3,
    USER_QUIT = -4,
    INVALID_INPUT = -5,
    APPEND_NOT_ALLOWED = -6,
    INVALID_FILE_CONTENT = -7,
    LS_COMMAND_FAILED = -8,
    NO_STRATEGY = -9,
    COMMANDS_INPUT_MISMATCH = -10,
    INVALID_PASSWORD = -11,
    REMOVE_FAIL = -12,
    DUPLICATE_FILE = -13,
    NULL_PTR = -14,
    INVALID_FILE_EXTENSION = -15,
    FILE_NOT_OPENED = -16,
    FILE_ALREADY_OPENED = -17,
    FILE_CREATE_FAIL = -18,
    FILE_ADD_FAIL = -19,
    INVALID_FLAG = -20
};

enum CONSTANTS {
    NAME_LENGTH = 20,
    EVEN = 2,
};

#endif