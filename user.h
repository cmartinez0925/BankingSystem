#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <string.h>

#include "account.h"


#define ADDRESS_LENGTH      75
#define EMAIL_LENGTH        75
#define NAME_LENGTH         20
#define NULL_TERMINATOR     '\0'
#define PASSWORD_LENGTH     30
#define PHONE_NUM_LENGTH    30
#define USERNAME_LENGTH     30

/*Return Values*/
#define FAIL                -1
#define SUCCESSFUL          0


/*Structs*/
/*
Author: Chris Martinez
Description: Struct for a User
Date: March 6, 2024
*/
struct User {
    char firstName[NAME_LENGTH];
    char lastName[NAME_LENGTH];
    char address[ADDRESS_LENGTH];
    char email[EMAIL_LENGTH];
    char password[PASSWORD_LENGTH];
    char phoneNummber[PHONE_NUM_LENGTH];
    char userName[USERNAME_LENGTH];
    struct Account Checking;
    struct Account Savings;
};


/*Constructors*/
/*
Author: Chris Martinez
Description: Creates a new User
Return: Struct User
Date: March 6, 2024
*/
struct User createUser(
    char* firstName,
    char* lastName,
    char* address,
    char* email,
    char* password,
    char* phoneNumber,
    char* userName,
    char* checkingBalance,
    char* savingsBalance
);

/*FUNCTIONS*/
/*
Author: Chris Martinez
Description: Append the user to the database (file)
Return: SUCCESSFUL, FAIL
Date: March 8, 2024
*/
int appendUserToFile(struct User* user, char* filename);

/*
Author: Chris Martinez
Description: Changes the first name of the user
Return: SUCCESSFUL, FAIL
Date: March 6, 2024
*/
int changeFirstName(char newFirstName[NAME_LENGTH], struct User* user);

/*
Author: Chris Martinez
Description: Changes the last name of the user
Return: SUCCESSFUL, FAIL
Date: March 6, 2024
*/
int changeLastName(char newLastName[NAME_LENGTH], struct User* user);

/*
Author: Chris Martinez
Description: Changes the address of the user
Return: SUCCESSFUL, FAIL
Date: March 6, 2024
*/
int changeAddress(char newAddress[ADDRESS_LENGTH], struct User* user);

#endif
