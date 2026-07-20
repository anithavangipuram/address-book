/*
File Name   : file.h
Date        : 12-12-2025

Description :
This header file contains file handling function declarations.
It is used to save and load contacts.
*/
#ifndef FILE_H//FILE_H is not defined.
#define FILE_H//FILE_H is defined.
//user defined header file
#include "contact.h"//it will add the content of contact.h file.
//fun declarations
void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);

#endif //end of condition.
