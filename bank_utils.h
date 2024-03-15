#ifndef BANK_UTILS_H
#define BANK_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASE_10             10
#define BUFFER_SIZE         100
#define COUNTDOWN           20
#define NEW_LINE            '\n'
#define NULL_TERMINATOR     '\0'

#define SIGN_IN             1
#define CREATE_USER         2
#define EXIT                3

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
Description: Displays the log-in screen
Date: March 6, 2024
*/
int splashView(void);

/*
Author: Chris Martinez
Description: Displays the user menu screen
Date: March 6, 2024
*/
void menuView(void);

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

#endif
