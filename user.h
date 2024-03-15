#ifndef USER_H
#define USER_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "bank_utils.h"

#define ASCII_DELETE        '\177'
#define ADDRESS_LENGTH      75
#define BACKSPACE           '\b'
#define EMAIL_LENGTH        75
#define FAIL                -1
#define INCORRECT_PASSWORD  -1
#define NAME_LENGTH         20
#define NEW_LINE_STR        "\n"
#define NULL_TERMINATOR     '\0'
#define PASSWORD_LENGTH     30
#define PHONE_NUM_LENGTH    30
#define SIGN_IN_SUCCESSFUL  0
#define SUCCESSFUL          0
#define UNABLE_CREATE_USER  -1
#define USER_ALREADY_EXIST  1
#define USER_CREATED        0
#define USER_LOCATED        0
#define USER_NOT_FOUND      1
#define USERNAME_LENGTH     30


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
    char* userName
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

/*
Author: Chris Martinez
Description: Displays the create new user screen
Date: March 6, 2024
Return: USER_CREATED, USER_ALREADY_EXIST, UNABLE_CREATE_USER
*/
int createUserView(char* filename);

/*
Author: Chris Martinez
Description: Find the user via userName
Return: USER_LOCATED, USER_NOT_FOUND, FAIL
Date: March 8, 2024
*/
int findUserByUsername(char* userName, char* filename, struct User* user);

/*
Author: Chris Martinez
Description: Gets the user's passwords
Return: Void
Date: March 9, 2024
*/
void getPassword(char* password, int maxLength);

/*
Author: Chris Martinez
Description: Attempt to have the user sign-in
Return: USER_LOCATED, INCORRECT_PASSWORD, USER_NOT_FOUND
Date: March 8, 2024
*/
int signInUserView(char* filename);

#endif
