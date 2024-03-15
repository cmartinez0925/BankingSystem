#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdio.h>
#include "user.h"

struct Account {
    int accountNumber;
    double accountBalance;
    struct User user;
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
