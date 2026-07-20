/*
File Name   : file.c
Date        : 12-12-2025
Description :This file is used to save contacts into a file.
It is also used to load contacts from a file.
*/
#include<stdlib.h>
#include <stdio.h>//system header file,it contain fun declarations.
#include <string.h>//system header file,it contain fun declaractions related to strings.
#include "file.h"//it will add the content of file.h.

void saveContactsToFile(AddressBook *addressBook) //fun def
{
    FILE *fp =NULL;
    fp=fopen("contact.csv", "w");//file opening write mode
    if (fp == NULL)
    {
        printf("Error: File not opened\n");
        exit(1);//exit is used to immediately turminating the program,exit(1) means program contain error,because of that error terminate the program.
    }
    fprintf(fp, "#contactcount = %d\n", addressBook->contactCount);//printing the contactcount and strong in file pointer

    for (int i = 0; i < addressBook->contactCount; i++)
    //printing the file
    {
        fprintf(fp, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);//closing the file
    printf("Contacts saved successfully.\n");
}
void loadContactsFromFile(AddressBook *addressBook)//def
{
    FILE *fp=NULL;
    //whenever we call fopen() fun automatically it will file type variable in that we have pointer,it will return address that address is stored in fp.
    fp= fopen("contact.csv", "r");//file opening in read mode
    if (fp == NULL)
    {
        printf("Error");
        exit(1);   
    }

    fscanf(fp, "#contactcount %d\n", &addressBook->contactCount);//reading the contact count and storing in file pointer
    for (int i = 0; i < addressBook->contactCount; i++)//loop will run contact count times
    //reading the file
    {
        fscanf(fp, "%[^,],%[^,],%[^\n]\n",
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }

    fclose(fp);//closing the file
}
