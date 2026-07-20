/*
File Name   : contact.c
Date        : 12-12-2025
Description :This file contains all contact functions.
It includes:
- create contact
- search contact
- edit contact
- delete contact
- list contacts
It also initializes the address book.
*/
#include<stdlib.h>//give functions for memory, numbers, and process control.
#include <stdio.h>//it contain input/output declarations
#include <string.h>//it contain fun declarations related to strings
#include "contact.h"//it will add the content of contact.h file
#include "validation.h" //it will add the content of validation.h file
#include "file.h"//it will add the content of file.h file
#include "populate.h"//it will add the content of populate.h file

void initialize(AddressBook *addressBook) //fun def
{
    addressBook->contactCount = 0;//intialize the conatact count=0
    //populateAddressBook(addressBook);
        // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);//fun call
}
void saveAndExit(AddressBook *addressBook)//fun def
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void createContact(AddressBook *addressBook)//fun def
{
    if (addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("Address Book is Full!\n");
        return;//here we are not return anything because datatype is void.
    }

   char name[50], phone[20], email[50];//here name,phone,mail are character arrays.
    int result;

    // Name → duplicates allowed
    do 
    {
        printf("Enter Name: ");//printing the name
        scanf(" %[^\n]", name);//reading the name
        result = validateName(name);//fun call and result is used for collecting the output.
        if(result == 0)
            printf("Invalid Name! Only letters and spaces allowed.\n");
    } while(result == 0);

    // Phone → must be unique
    do 
    {
        printf("Enter Phone: ");//printing the phone
        scanf(" %[^\n]", phone);//reading the phone
        result = validatePhone(phone);//fun call
        if(result == 0)
            printf("Invalid Phone! Must be 10 digits.\n");
        else if(!isPhoneUnique(addressBook, phone))//conditon inside fun call will happened.
        {
            printf("Phone already exists! Enter another phone.\n");
            result = 0;
        }
    } while(result == 0);

    // Email → must be unique
    do 
    {
        printf("Enter Email: ");//printing the mail 
        scanf(" %[^\n]", email);//reading the mail
        result = validateEmail(email);//fun call
        if(result == 0)
            printf("Invalid Email! Must start with lowercase and end with @gmail.com\n");
        else if(!isEmailUnique(addressBook, email))//condition inside fun call will happen
        {
            printf("Email already exists! Enter another email.\n");
            result = 0;
        }
    } while(result == 0);
   //storing data(name,phone number and mail-id) in structure.
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);
    addressBook->contactCount++;//increment the contact count

    printf("Contact added successfully.\n");
}

void searchContact(AddressBook *addressBook)//fun def
{
    int choice, found = 0;
    char key[50];

    listContacts(addressBook,0);//fun call
//printing  the menu
    printf("\nSearch Menu:\n1. Name\n2. Phone\n3. Email\n4. Exit\nEnter choice: ");
    scanf("%d", &choice);//reading the choice
    if(choice == 4) //exit
    return;

    printf("Enter value to search: ");
    scanf(" %[^\n]", key);//reading the search

    for(int i = 0; i < addressBook->contactCount; i++)//loop will run contactcount times 
    {
        int match = 0;
        if(choice == 1 && strcmp(addressBook->contacts[i].name, key) == 0)
         match = 1;
        if(choice == 2 && strcmp(addressBook->contacts[i].phone, key) == 0) 
        match = 1;
        if(choice == 3 && strcmp(addressBook->contacts[i].email, key) == 0) 
        match = 1;
        if(match)
        {
            found = 1;//contact found
            printf("\nContact Found:\nName: %s\nPhone: %s\nEmail: %s\n---------------------\n",
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
            if(choice == 2 || choice == 3)
            break;//break is used for exit from the loop
        }
    }

    if(!found)
    printf("No contact found\n");
}


void editContact(AddressBook *addressBook)//fun def
{
    char edit[50];//created the character array name called edit.
    printf("Enter name to edit: ");//printing the name to edit
    scanf(" %[^\n]", edit);//reading the edit 

    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].name,edit)==0)//strcmp==0 means equal(contact found)
        {
            printf("New Phone: ");
            scanf(" %[^\n]", addressBook->contacts[i].phone);//reading the phone number
            printf("New Email: ");
            scanf(" %[^\n]", addressBook->contacts[i].email);//reading the mail
            printf("Updated.\n");
            return;
        }
    }

    printf("Not found.\n");
}
void deleteContact(AddressBook *addressBook)//fun def
{
    char delete[50];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", delete);//reading the delete 

    for(int i=0; i<addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].name,delete)==0)//string compare==0 means name is found
        {
            for(int j=i; j<addressBook->contactCount-1; j++)
                addressBook->contacts[j] = addressBook->contacts[j+1];//shifting the contacts to left
            addressBook->contactCount--;//decrement the contact count
            printf("Deleted.\n");
            return;
        }
    }
    printf("Not found.\n");
}
void listContacts(AddressBook *addressBook, int sortCriteria)//fun def
{
    if (addressBook->contactCount == 0) 
    {
        printf("\nNo contacts.\n");
        return;
    }

    printf("\n%-5s %-20s %-15s %-30s\n", "S.No", "Name", "Phone", "Email");//used for proper alignment and we can show in table format
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%-5d %-20s %-15s %-30s\n",
               i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }
    printf("---------------------------------------------------------------------\n");
}


