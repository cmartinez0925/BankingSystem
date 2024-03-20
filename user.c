#include <stdio.h>
#include <string.h>

#include "user.h"

struct User createUser(char* firstName,
                       char* lastName,
                       char* address,
                       char* email,
                       char* password,
                       char* phoneNumber,
                       char* userName,
                       char* checkingBalance,
                       char* savingsBalance
                       ) {
    struct User user;
    strncpy(user.firstName, firstName, NAME_LENGTH - 1);
    user.firstName[NAME_LENGTH - 1] = NULL_TERMINATOR;

    strncpy(user.lastName, lastName, NAME_LENGTH - 1);
    user.lastName[NAME_LENGTH - 1] = NULL_TERMINATOR;

    strncpy(user.address, address, ADDRESS_LENGTH - 1);
    user.address[ADDRESS_LENGTH - 1] = NULL_TERMINATOR;

    strncpy(user.email, email, EMAIL_LENGTH - 1);
    user.email[EMAIL_LENGTH - 1] = NULL_TERMINATOR;

    strncpy(user.password, password, PASSWORD_LENGTH - 1);
    user.password[PASSWORD_LENGTH - 1] = NULL_TERMINATOR;

    strncpy(user.phoneNummber, phoneNumber, PHONE_NUM_LENGTH - 1);
    user.phoneNummber[PHONE_NUM_LENGTH - 1] = NULL_TERMINATOR;

    strncpy(user.userName, userName, USERNAME_LENGTH - 1);
    user.userName[USERNAME_LENGTH - 1] = NULL_TERMINATOR;

    /*Set account types and balances*/
    user.Checking.accountType = CHECKING;
    strncpy(user.Checking.accountBalance, checkingBalance, BALANCE_LENGTH);

    user.Savings.accountType = SAVINGS;
    strncpy(user.Savings.accountBalance, savingsBalance, BALANCE_LENGTH);

    return user;
}

int appendUserToFile(struct User* user, char* filename) {
    FILE* file = fopen(filename, "a+");
    if (!file) {
        perror("Failed to open file for appending");
        return FAIL;
    }

    fprintf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n---\n", 
            user->firstName,
            user->lastName,
            user->address,
            user->email,
            user->password,
            user->phoneNummber,
            user->userName,
            user->Checking.accountBalance,
            user->Savings.accountBalance
    );
    
    fclose(file);
    return SUCCESSFUL;
}

int changeFirstName(char newFirstName[NAME_LENGTH], struct User* user) {
    if (user != NULL && newFirstName != NULL) {
        strncpy(user->firstName, newFirstName, sizeof(user->firstName) - 1);
        user->firstName[sizeof(user->firstName) - 1] = NULL_TERMINATOR;
        return SUCCESSFUL;
    }
    return FAIL;
}

int changeLastName(char newLastName[NAME_LENGTH], struct User* user) {
    if (user != NULL && newLastName != NULL) {
        strncpy(user->lastName, newLastName, sizeof(user->lastName) - 1);
        user->lastName[sizeof(user->lastName) - 1] = NULL_TERMINATOR;
        return SUCCESSFUL;
    }
    return FAIL;
}

int changeAddress(char newAddress[ADDRESS_LENGTH], struct User* user) {
    if (user != NULL && newAddress != NULL) {
        strncpy(user->address, newAddress, sizeof(user->address) - 1);
        user->address[sizeof(user->address) - 1] = NULL_TERMINATOR;
        return SUCCESSFUL;
    }
    return FAIL;
}
