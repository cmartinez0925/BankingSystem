#include <stdio.h>
#include <string.h>

#include "user.h"

struct User createUser(char* firstName,
                       char* lastName,
                       char* address,
                       char* email,
                       char* password,
                       char* phoneNumber,
                       char* userName
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

    return user;
}


int appendUserToFile(struct User* user, char* filename) {
    FILE* file = fopen(filename, "a+");
    if (!file) {
        perror("Failed to open file for appending");
        return FAIL;
    }

    fprintf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n---\n", 
            user->firstName,
            user->lastName,
            user->address,
            user->email,
            user->password,
            user->phoneNummber,
            user->userName
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

int createUserView(char* filename) {
    char firstName[NAME_LENGTH];
    char lastName[NAME_LENGTH];
    char address[ADDRESS_LENGTH];
    char email[EMAIL_LENGTH];
    char password[PASSWORD_LENGTH];
    char passVerify[PASSWORD_LENGTH];
    char phoneNumber[PHONE_NUM_LENGTH];
    char userName[USERNAME_LENGTH];

    int passwordDoesNotMatch = 1;
    struct User user;


    clearView();
     /*Title Section*/
    setCursorPosition(2, 34);
    printf("CREATE ACCOUNT");
    setCursorPosition(5, 7);
    printAsterisks(69);

    /*Create User Section*/
    setCursorPosition(10, 35);
    printf("==== ENTER INFO ===");
    setCursorPosition(12, 10);
    printf("FIRST NAME: ");
    setCursorPosition(12, 28);
    fgets(firstName, NAME_LENGTH, stdin);
    firstName[strcspn(firstName, NEW_LINE_STR)] = NULL_TERMINATOR;

    setCursorPosition(13, 10);
    printf("LAST NAME: ");
    setCursorPosition(13, 28);
    fgets(lastName, NAME_LENGTH, stdin);
    lastName[strcspn(lastName, NEW_LINE_STR)] = NULL_TERMINATOR;

    setCursorPosition(14, 10);
    printf("ADDRESS: ");
    setCursorPosition(14, 28);
    fgets(address, ADDRESS_LENGTH, stdin);
    address[strcspn(address, NEW_LINE_STR)] = NULL_TERMINATOR;

    setCursorPosition(15, 10);
    printf("EMAIL: ");
    setCursorPosition(15, 28);
    fgets(email, EMAIL_LENGTH, stdin);
    email[strcspn(email, NEW_LINE_STR)] = NULL_TERMINATOR;

    setCursorPosition(16, 10);
    printf("PHONE NUMBER: ");
    setCursorPosition(16, 28);
    fgets(phoneNumber, PHONE_NUM_LENGTH, stdin);
    phoneNumber[strcspn(phoneNumber, NEW_LINE_STR)] = NULL_TERMINATOR;

    setCursorPosition(17, 10);
    printf("USERNAME: ");
    setCursorPosition(17, 28);
    fgets(userName, USERNAME_LENGTH, stdin);
    userName[strcspn(userName, NEW_LINE_STR)] = NULL_TERMINATOR;

    /* THIS IS STILL FUNKY AS WELL... BUT IT MOSTLY WORKS*/
    while (passwordDoesNotMatch) {
        setCursorPosition(18, 10);
        printf("PASSWORD:                               "); /*Clear line with spaces*/
        setCursorPosition(18, 28);
        getPassword(password, PASSWORD_LENGTH);

        setCursorPosition(19, 10);
        printf("VERIFY PASSWORD:                               "); /*Clear line with spaces*/
        setCursorPosition(19, 28);
        getPassword(passVerify, PASSWORD_LENGTH);

        if (strncmp(password, passVerify, PASSWORD_LENGTH) == 0) {
            passwordDoesNotMatch = 0;
        } else {
            setCursorPosition(20, 10);
            printf("Passwords do not match. Press enter to try again...");
            getchar(); /*Wait for enter to be press*/

            /*Clear the prompt line*/
            setCursorPosition(20, 10);
            printf("                                                         ");

            /*Clear previously set passwords*/
            memset(password, 0, PASSWORD_LENGTH);
            memset(passVerify, 0, PASSWORD_LENGTH);
        }
    }

    setCursorPosition(22, 10);
    printf("Please wait as we create the account: ");
    printCountDown(COUNTDOWN);
    user  = createUser(firstName, lastName, address, email, password, phoneNumber, userName);
 
    setCursorPosition(23, 10);
    if (findUserByUsername(userName, filename, &user) == 0) {
        printf("USER ALREADY EXISTS.");
        return USER_ALREADY_EXIST;
    } else {
        if (appendUserToFile(&user, filename) == 0) {
            printf("USER HAS BEEN CREATED!\n");
            return USER_CREATED;
        };
        return UNABLE_CREATE_USER;
    }
}

int findUserByUsername(char* userName, char* filename, struct User* user) {
    struct User tempUser;
    char delimiter[4]; /*"---\n"*/
    char formatStr[256];
    FILE* file = fopen(filename, "r");

    snprintf(formatStr, sizeof(formatStr), 
             "%%%d[^\n]\n%%%d[^\n]\n%%%d[^\n]\n%%%d[^\n]\n%%%d[^\n]\n%%%d[^\n]\n%%%d[^\n]\n",
             NAME_LENGTH, NAME_LENGTH, ADDRESS_LENGTH , EMAIL_LENGTH, PASSWORD_LENGTH, PHONE_NUM_LENGTH, USERNAME_LENGTH);

    if (!file) {
        perror("Failed to open file for reading");
        return FAIL;
    }

    while (fscanf(file, formatStr, tempUser.firstName, tempUser.lastName, tempUser.address, 
                tempUser.email, tempUser.password, tempUser.phoneNummber, tempUser.userName) == 7) {
        fgets(delimiter, sizeof(delimiter), file); /*Attempt to consume the delimiter line*/

        if (strncmp(tempUser.userName, userName, USERNAME_LENGTH) == 0) {
            *user = tempUser;
            fclose(file);
            return USER_LOCATED; /*User found*/
        }
    }

    /* If the loop exits without finding a user, then the user was not found. */
    fclose(file);
    return USER_NOT_FOUND; /*User not found or end of file reached*/
}

/*
This is still a bit funky, since it takes input from other keys and prints multiple asterisks... need to
research or ask chatgpt how to fix this issue, because whatever I do doesn't seem to work.
*/
void getPassword(char* password, int maxLength) {
    struct termios oldt, newt;
    int character, index = 0;

    /* Get the current terminal settings */
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    /* Disable echoing of characters and line buffering */
    newt.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    /* Read characters one at a time */
    while (index < maxLength - 1 && (character = getchar()) != NEW_LINE && character != EOF) {
        if ((character == BACKSPACE || character == ASCII_DELETE) && index > 0) {  /* Handle backspace */
            index--;
            printf("\b \b");  /* Move back, print space to erase, and move back again */
            fflush(stdout);
        } else if (character != BACKSPACE && character != ASCII_DELETE && isprint(character)) {
            password[index++] = character;
            printf("*");  /* Echo asterisk for each character input */
            fflush(stdout);
        }
    }
    password[index] = NULL_TERMINATOR;  /* Null-terminate the password */

    /* Restore the old terminal settings */
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    printf(NEW_LINE_STR);  /* Move to a new line after password input is complete */
}

int signInUserView(char* filename) {
    char userName[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    struct User user;
    
    /*Title Section*/
    setCursorPosition(2, 34);
    printf("ACCOUNT LOG-IN");
    setCursorPosition(5, 7);
    printAsterisks(69);

    /*Log-In Section*/
    setCursorPosition(10, 35);
    printf("==== LOG IN ===");
    setCursorPosition(12, 35);
    printf("Username: ");
    if (fgets(userName, USERNAME_LENGTH, stdin) == NULL) {
        perror("Error reading username from user.\n");
        EXIT_FAILURE;
    }
    userName[strcspn(userName, NEW_LINE_STR)] = NULL_TERMINATOR; /*Remove Newline*/
    setCursorPosition(14, 35);
    printf("Password: ");
    getPassword(password, PASSWORD_LENGTH);    

    /*Verify the username and password to sign in*/
    setCursorPosition(16, 35);
    if (findUserByUsername(userName, filename, &user) == USER_LOCATED) {
        if (strncmp(user.password, password, PASSWORD_LENGTH) == 0) {
            printf("SIGN-IN SUCCESSFUL.\n");
            return SIGN_IN_SUCCESSFUL;
        } else {
            printf("INCORRECT PASSWORD.\n");
            return INCORRECT_PASSWORD;
        }
    } else {
        printf("USER NOT FOUND.\n");
        return USER_NOT_FOUND;
    }
}
