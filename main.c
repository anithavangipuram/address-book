/*
File Name   : main.c
Date        : 12-12-2025
Author      : Anitha Vangipuram
Description :This is the main file of the Address Book project.
Program execution starts from this file.
It shows the menu to the user.
It calls create, search, edit, delete, and list functions.
*/

//function declarations are defined in header files
#include <stdio.h>//system header file 
#include "contact.h"//user defined header file,add the content of contact.h file
#include "file.h"//it will add the content of file.h file.

int main() //execution starts from main function
{
    AddressBook addressBook;//here Adressbook is datatype and address book is a variable.
    initialize(&addressBook);//function call and intializes the address book.
    
    int choice;//it is used for based on user chioce.
    while(1) //while(1) is  always true it is a super loop.
    {
        // Print menu only once per loop
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Save contacts\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);//reading the choice

        switch(choice) {
            case 1:
                createContact(&addressBook);//fun call for creating new contact
                break;
            case 2:
                searchContact(&addressBook);//fun call for search contact
                break;
            case 3:
                editContact(&addressBook);//fun call for edit contact
                break;
            case 4:
                deleteContact(&addressBook);//fun call for delete contact
                break;
            case 5:
                listContacts(&addressBook, 0); // 0 = default sort,fun call for list contact
                break;
            case 6:
                saveContactsToFile(&addressBook);//fun call for save contacts to file
                break;
            case 7:
                printf("Exiting program.\n");//used for exit the program
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
