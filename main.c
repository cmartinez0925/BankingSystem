#include <stdio.h>
#include <stdlib.h>

#include "bank_utils.h"

#define SIGN_IN             1
#define CREATE_USER         2
#define EXIT                3

#define FILENAME            "test.txt"

/*
THINGS TO IMPLEMENT LATER:
1 - Hash password 
2 - Back option from signInUserView() to splashView()
3 - Transfer money from user accounts
*/


int main(void) {
    int choice;
    int signInStatus;
    struct User currentUser;
    bool invalidChoice = true;
    bool notSignedIn = true;

    /* Print log-in screen and handle incorrect input from user */
    while (invalidChoice) {
        clearView();
        choice = splashView();
        if (choice == SIGN_IN || choice == CREATE_USER || choice == EXIT) {
            invalidChoice = false;
        }
    }

    clearView();

    switch (choice) {
        case SIGN_IN:
            while (notSignedIn) {
                clearView();
                signInStatus = signInUserView(FILENAME, &currentUser);
                if (signInStatus == SIGN_IN_SUCCESSFUL) {
                    notSignedIn = false;
                } else if (signInStatus == INCORRECT_PASSWORD) {
                    clearInputBuffer();
                } else if (signInStatus == USER_NOT_FOUND) {
                    clearInputBuffer();
                }
                /*PROBS SHOULD HAVE A WAY TO GO BACK TO SPLASHVIEW()...LATER LINNNK PROBS*/
            }

            userMenuView();
            break;
        case CREATE_USER:
            createUserView(FILENAME);
            /*PROBS SHOULD HAVE A WAY TO GO BACK TO SPLASHVIEW()...LATER LINNNK PROBS*/
            break;
        case EXIT:
            exit(0);
            break;
    }
    

    return EXIT_SUCCESS;
}
