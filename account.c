#include <stdio.h>

#include "account.h"

int deposit(double amount, struct Account* account) {
    if (amount <= 0.0) {
        return -1;
    } else {
        account->accountBalance += amount;
        return 0;
    }
}

void printBalance(struct Account* account) {
    printf("Current Balance: $%.2f\n", account->accountBalance);
}

int withdraw(double amount, struct Account* account) {
    if (amount <= 0.0 || account->accountBalance <= 0.0) {
        return -1;
    } else {
        account->accountBalance -= amount;
        return 0;
    }
}
