#include <stdio.h>
#include "STD.h"
#include "SDB.h"

void SDB_Action(uint8 choice) {  
    uint32 id;                         //defining local variable id
    uint8 count;                       //defining local variable count
    uint32 list[MAX_STUDENTS];         //defining local variable list 

    switch (choice) {                        //switch case 
        case 1:                             // first case if 1 
            if (SDB_AddEntry()) {           //if the function add entry returned true(1) 
                printf("Student added successfully.\n");    //will print this statement 
            } else {                                         //if the function add entry returned false(0) this meamn there is error entering data  
                printf("Failed to add student.\n");         //will print this statement 
            }
            break;                                          //break statement to prevent switching to the next case 
        case 2:                                             //second case if case 2 
            printf("Number of students in the database: %u\n", SDB_GetUsedSize());  //will call function get used size and send it to the user in the message
            break;                                          //break statement to prevent switching to the next case
        case 3:
            printf("Enter Student ID to read: ");           //ask user to enter id to read 
            scanf("%u", &id);                               //store input in the variable id
            SDB_ReadEntry(id);                              //call function read entry anf give it id the user entered
            break;                                         //break statement to prevent switching to the next case
        case 4:
            SDB_GetList(&count, list);                     //call function get list and give it addres of count variable and array list
            printf("List of student IDs:\n");             //will print this statement 
            for (uint8 i = 0; i < count; ++i) {            //loop to print ids stored in list array
                printf("%u\n", list[i]);
            }
            break;                                         //break statement to prevent switching to the next case
        case 5:
            printf("Enter Student ID to check existence: ");   //ask user to enter id of the student to check if exist
            scanf("%u", &id);                                  //store value entered in id
            if (SDB_IsIdExist(id)) {                          //call function if exist to check if exist
                printf("Student ID %u exists.\n", id);         //will print this statement 
            } else {
                printf("Student ID %u does not exist.\n", id);  //will print this statement 
            }
            break;                                         //break statement to prevent switching to the next case
        case 6:
            printf("Enter Student ID to delete: ");        //ask user to enter id of the student to delete
            scanf("%u", &id);                              //store value entered in id
            SDB_DeleteEntry(id);                           //call delete function and give to it the id entered 
            break;                                         //break statement to prevent switching to the next case
        case 7:
            if (SDB_IsFull()) {                            //calling function is full if returned true 
                printf("Database is full.\n");             //will print this statement  
            } else {
                printf("Database is not full.\n");         //will print this statement 
            }
            break;                                         //break statement to prevent switching to the next case
        case 0:
            printf("Exiting...\n");                        //messege before exit
            break;                                         //break statement to prevent switching to the next case
        default:
            printf("Invalid choice.\n");                   //will print this statement if any other choice
            break;                                        //break statement to prevent switching to the next case
    }
}

void SDB_APP() {             //function to start the app by calling it 
    uint8 choice;            //defining new varaible choice
    do {
        //some choices for the user to see what he want from the data base 
        printf("1. To add entry, enter 1\n");                       //1 to add entry
        printf("2. To get used size in database, enter 2\n");       //2 to display hoe many users in the data base 
        printf("3. To read student data, enter 3\n");               //3 to read studen data 
        printf("4. To get the list of all student IDs, enter 4\n"); //4 to get list of all ids 
        printf("5. To check if ID exists, enter 5\n");              //5 to check if id exist
        printf("6. To delete student data, enter 6\n");             //6 to delete student data 
        printf("7. To check if database is full, enter 7\n");       //7 to check if data base is full 
        printf("0. To exit, enter 0\n");                            //0 to exist
        printf("Enter your choice: ");                              //to make user enter his choice
        scanf("%u", &choice);                                       //take choice and store it in choice variable
        SDB_Action(choice);                                         //call function SDB action and give it the choice the user choiced  
    } while (choice != 0);
}
