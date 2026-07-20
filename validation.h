/*
File Name   : validation.h
Date        : 12-12-2025
Description :This header file contains validation function declarations.
It is used to validate name, phone, and email.
*/
#ifndef VALIDATION_H //not define the validation.h file
#define VALIDATION_H  //define the validation.h file
//used defined header file
#include "contact.h"//it will add the contents of contact.h
//fun declarations
int validateName(char *name);
int validatePhone(char *phone);
int validateEmail(char *email);
int isPhoneUnique(AddressBook *addressBook, char *phone);
int isEmailUnique(AddressBook *addressBook, char *email);

#endif  //end of condition
