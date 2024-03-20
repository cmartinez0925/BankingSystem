#ifndef BANK_UTILS_H
#define BANK_UTILS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#include "user.h"

#define ASCII_DELETE        '\177'
#define BACKSPACE           '\b'
#define BASE_10             10
#define BUFFER_SIZE         100
#define COUNTDOWN           20
#define DELIMITER_SIZE      5
#define NEW_LINE            '\n'
#define NEW_LINE_STR        "\n"
#define NULL_TERMINATOR     '\0'

/*Return Values*/
#define FAIL                -1
#define SUCCESSFUL          0

#define INCORRECT_PASSWORD  1
#define SIGN_IN_SUCCESSFUL  2
#define UNABLE_CREATE_USER  3
#define USER_ALREADY_EXIST  4
#define USER_CREATED        5
#define USER_LOCATED        6
#define USER_NOT_FOUND      7

typedef enum {false = 0, true = 1} bool;

/*
Author: Chris Martinez
Description: Clears the input buffer
Date: March 10, 2024
*/
void clearInputBuffer(void);

/*
Author: Chris Martinez
Description: Clears the screen and moves cursor to top-left position
Date: March 6, 2024
*/
void clearView(void);

/*
Author: Chris Martinez
Description: Displays the create new user screen
Date: March 6, 2024
Return: USER_CREATED, USER_ALREADY_EXIST, UNABLE_CREATE_USER
*/
int createUserView(char* filename);

/*
Author: Chris Martinez
Description: Find the user via userName
Return: USER_LOCATED, USER_NOT_FOUND, FAIL
Date: March 8, 2024
*/
int findUserByUsername(char* userName, char* filename, struct User* user);

/*
Author: Chris Martinez
Description: Gets the user's passwords
Return: Void
Date: March 9, 2024
*/
void getPassword(char* password, int maxLength);

/*
Author: Chris Martinez
Description: Prints a bunch of asterisks based on desired number
Date: March 6, 2024
*/
void printAsterisks(int count);

/*
Author: Chris Martinez
Description: Prints a bunch of asterisks representing a count down
Date: March 10, 2024
*/
void printCountDown(int conut);

/*
Author: Chris Martinez
Description: Set cursor position via row, column
Date: March 6, 2024
*/
void setCursorPosition(int row, int column);

/*
Author: Chris Martinez
Description: Attempt to have the user sign-in
Return: USER_LOCATED, INCORRECT_PASSWORD, USER_NOT_FOUND
Date: March 8, 2024
*/
int signInUserView(char* filename, struct User* currentUser);

/*
Author: Chris Martinez
Description: Displays the log-in screen
Date: March 6, 2024
*/
int splashView(void);

/*
Author: Chris Martinez
Description: Displays the user menu screen
Date: March 6, 2024
*/
void userMenuView(void);

#endif
