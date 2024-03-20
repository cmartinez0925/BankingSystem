#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BALANCE_LENGTH      12
#define NULL_TERMINATOR     '\0'

#define FAIL                -1
#define SUCCESSFUL          0

typedef enum {CHECKING = 0, SAVINGS = 1} AccountType;

struct Account {
    AccountType accountType;
    char accountBalance[BALANCE_LENGTH];
};

/*FUNCTIONS*/

/*
Author: Chris Martinez
Description: Deposits money into specified account
Returns: 0 - Successful, -1 - Unsuccessful
Date: March 6, 2024
*/
int deposit(double amount, struct Account* account);

/*
Author: Chris Martinez
Description: Prints balance of specified account
Date: March 6, 2024
*/
void printBalance(struct Account* account);

/*
Author: Chris Martinez
Description: Withdraws money into specified account
Returns: 0 - Successful, -1 - Unsuccessful
Date: March 6, 2024
*/
int withdraw(double amount, struct Account* account);



#endif
