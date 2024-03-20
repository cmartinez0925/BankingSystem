#include "account.h"

int deposit(double amount, struct Account* account) {
    char* errorPtr;
    double currentAmt;

    currentAmt = strtod(account->accountBalance, &errorPtr);

    /*Check if the conversion was a success*/
    if (*errorPtr != '\0') {
        fprintf(stderr, "Must input a numerical value.\n");
        return FAIL;
    }

    if (amount <= 0.0) {
        fprintf(stderr, "Must be greater than 0.\n");
        return FAIL;
    }
  
    currentAmt += amount;
    snprintf(account->accountBalance, BALANCE_LENGTH, "%.2f", currentAmt);
    return SUCCESSFUL;
}

void printBalance(struct Account* account) {
    printf("Current Balance: $%s\n", account->accountBalance);
}

int withdraw(double amount, struct Account* account) {
    char* errorPtr;
    double currentAmt;

    currentAmt = strtod(account->accountBalance, &errorPtr);

    /*Check if the conversion was a success*/
    if (*errorPtr != '\0') {
        fprintf(stderr, "Must input a numerical value.\n");
        return FAIL;
    }

    if (amount <= 0.0) {
        fprintf(stderr, "Must be greater than 0.\n");
        return FAIL;
    }

    currentAmt -= amount;

    if (currentAmt <= 0.0) {
    fprintf(stderr, "Insufficient Funds.\n");
    return FAIL;
    }

    snprintf(account->accountBalance, BALANCE_LENGTH, "%.2f", currentAmt);
    return SUCCESSFUL;
}

