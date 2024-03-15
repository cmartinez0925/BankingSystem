#include "bank_utils.h"

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != NEW_LINE && c != EOF) {/* Discard Characters */};
}
    
void clearView(void) {
    printf("\033[2J\033[H");
    fflush(stdout);
}

int splashView(void) {
    char buffer[BUFFER_SIZE];
    char* errorPtr;
    long int choice = 0;
    int userChoice = 0;

    /* Title Portion */
    setCursorPosition(3, 22);
    printf("WELCOME TO BANK OF LINNNK\n\n");
    setCursorPosition(5, 18);
    printAsterisks(34);
    setCursorPosition(7, 25);
    printf("DEVELOPER - LiNNNk");

    /* Options Listing*/
    setCursorPosition(10, 20);
    printf("1... SIGN IN");
    setCursorPosition(12, 20);
    printf("2... NOT A USER? CREATE USER HERE");
    setCursorPosition(14, 20);
    printf("3... EXIT\n\n");

    /* User input section*/
    printf("\n\nENTER YOUR CHOICE.. ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        perror("Error reading choice from user.\n");
        return EXIT_FAILURE;
    }
    
    choice = strtol(buffer, &errorPtr, BASE_10);
    /* Error checking user input */
    if (*errorPtr != NEW_LINE && *errorPtr != NULL_TERMINATOR) {
        choice = -1;
    }
    /* Safe to convert long int to int */
    userChoice = (int)choice;
    return userChoice;
}

void menuView(void) {
    /*NEED IMPLEMENTATION*/

}

void printAsterisks(int count) {
    int i = 0;
    for (i = 0; i < count; i++) {
        printf("*");
    }
}

void printCountDown(int count) {
    struct timespec timer;
    int i = 0;

    timer.tv_sec = 0;
    timer.tv_nsec = 50000000; /*50 milliseconds to nanoseconds*/

    for (i = 0; i < count; i++) {
       printf("*");
       fflush(stdout);
       nanosleep(&timer, NULL);
    }
}

void setCursorPosition(int row, int column) {
    printf("\033[%d;%dH", row, column);
    fflush(stdout);
}
