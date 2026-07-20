/*
File Name   : contact.h
Date        : 12-12-2025
Description :This header file contains structure definitions.
It also contains function declarations for contact operations.
It is used to share data between different files.
*/
//this macros used for conditional compilation.ifnedf is used to check CONTACT_H is not defined and define macro defines the CONTACT_H.
#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100 //it is a macro and storing 100 contacts,wherever max_contacts '100' will be replaced in preprocessor stage.
//structures declarion
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;//data type

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;//data type

//fun declarations
void initialize(AddressBook *addressBook);
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void saveContactsToFile(AddressBook *addressBook);

#endif   //end of condition
