/*
File Name   : validation.c
Date        : 12-12-2025
Description :This file contains validation logic for Name,phone number,mail.
*/
#include "validation.h"//it will add the content of validation.h file
#include "contact.h"   //it will add the content of contact.h file
#include <string.h>
#include <stdio.h>
#include <ctype.h>//character type to check characters like letters and digits.
/* ---------------- NAME ---------------- */
int validateName(char *name)//fun def
{
    for(int i=0; name[i]!=0; i++)
    {
        if(!isalpha(name[i]) && name[i] != ' ')//isaplha is a bulitin fun,it checks lowercase and uppercase alphabets
            return 0;//false
    }
    return 1;//true
}
/* ---------------- PHONE NUMBER ---------------- */
int validatePhone(char *phone)//fun def
{
    if(strlen(phone)!=10) //strlen s a built in function,it give string length excluding null character
    return 0;//false
    if(phone[0]=='0')
    return 0;//false
    int same=1;// variable to check if all digits are same

    for(int i=1;i<10;i++)
    {
        if(phone[i]!=phone[0])// compares each digit with first digit
         same=0;// makes same = 0 if any digit is different
    }
    if(same==1) // checks if all digits are same
    return 0;//false
    for(int i=0;i<10;i++)
    {
        if(phone[i]<'0' || phone[i]>'9') 
        return 0;//not valid
    }
    return 1;//valid
}
/* ---------------- MAIL-ID ---------------- */
int validateEmail(char *email)//fun def
{
    
    int len = strlen(email);//strlen is a built in fun,it give string length exclude null character

    // Minimum length "a@gmail.com"
    if (len < 10) 
        return 0;

    // end with "@gmail.com"
    if (strcmp(email + len - 10, "@gmail.com") != 0)
        return 0;

    // Must start with lowercase letter
    if (!(email[0] >= 'a' && email[0] <= 'z'))
        return 0;

    // Check all characters before '@'
    for (int i = 0; i < len - 10; i++)
    {
        //islower is a built in fun check lowercase letters(a to z)
        //isdigit is a built in fun checks only digits
        if (!(islower(email[i]) || isdigit(email[i]) || email[i] == '.' || email[i] == '_'))
        {
            return 0; // notvalid 
        }
    }

    return 1; // valid 
}

/* ---------------- UNIQUE PHONE ---------------- */
int isPhoneUnique(AddressBook *addressBook, char *phone)//fun def
{
    for(int i = 0; i < addressBook->contactCount; i++)
        if(strcmp(addressBook->contacts[i].phone, phone) == 0)//strcmp==0 means duplicate phone found
            return 0;//false
    return 1;//true
}
/* ---------------- UNIQUE MAIL ---------------- */
int isEmailUnique(AddressBook *addressBook, char *email)//fun def
{
    for(int i = 0; i < addressBook->contactCount; i++)
        if(strcmp(addressBook->contacts[i].email, email) == 0)//strcmp==0 means duplicate mail found.
            return 0;//false
    return 1;//true
}