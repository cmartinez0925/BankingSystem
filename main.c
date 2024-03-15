#include <stdio.h>
#include <stdlib.h>

#include "account.h"
#include "bank_utils.h"
#include "user.h"

#define FILENAME    "test.txt"

/*
THINGS TO IMPLEMENT LATER:
1 - Hash password 
2 - Back option from signInUserView() to splashView()
3 - Transfer money from user accounts
*/

typedef enum {false = 0, true = 1} bool;

int main(void) {
    int choice;
    int signInStatus;
    int userCreatedStatus;
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
                signInStatus = signInUserView(FILENAME);
                if (signInStatus == SIGN_IN_SUCCESSFUL) {
                    notSignedIn = false;
                } else if (signInStatus == INCORRECT_PASSWORD) {
                    clearInputBuffer();
                } else if (signInStatus == USER_NOT_FOUND) {
                    clearInputBuffer();
                }
                /*PROBS SHOULD HAVE A WAY TO GO BACK TO SPLASHVIEW()...LATER LINNNK PROBS*/
            }
            break;
        case CREATE_USER:
            createUserView(FILENAME);
            break;
        case EXIT:
            exit(0);
            break;
    }
    

    return EXIT_SUCCESS;
}
