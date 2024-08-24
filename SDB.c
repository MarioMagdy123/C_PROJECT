#include <stdio.h>
#include "SDB.h"

static student database[MAX_STUDENTS];      //database declaration by making array of structs  
static uint8 num_students = 0;              //global variable to count number of students and intialized by 0

Bool SDB_IsFull() {
    return num_students >= MAX_STUDENTS;    //condition if number of students more than max number of students in data base (10) return 1 else return 0 
}

uint8 SDB_GetUsedSize() {
    return num_students;       //return global variable number of students
}

Bool SDB_AddEntry() {
    if (SDB_IsFull()) {     //call function is full to check there is place in the data base or not before add entry 
        printf("Database is full. Cannot add more students.\n");  //if full print this messege
        return False;                                             //and end function by returning 0
    }

    student new_student;                     //create new student from the data type (struct student)
    printf("Enter Student ID: ");            //ask user to enter id
    scanf("%u", &new_student.Student_ID);    //take id and put it in the struct student id attribute
    if (SDB_IsIdExist(new_student.Student_ID)) {  //check if the id is repeated
        printf("Student ID already exists.\n");   //if id is pepeated this message will be printed
        return False;                             //function will be finshed by returning 0 
    }

    printf("Enter Student Year: ");             //ask user to enter Student Year 
    scanf("%u", &new_student.Student_year);     //take Student Year and put it in the struct student Student Year attribute
    printf("Enter Course1 ID: ");               //ask user to enter Course 1 ID
    scanf("%u", &new_student.Course1_ID);       //take Course 1 ID and put it in the struct student Course 1 ID attribute
    printf("Enter Course1 Grade: ");            //ask user to enter Course 1 Grade
    scanf("%u", &new_student.Course1_grade);    //take Course 1 GRADE and put it in the struct student Course 1 GRADE attribute
    printf("Enter Course2 ID: ");               //ask user to enter Course 2 ID
    scanf("%u", &new_student.Course2_ID);       //take Course 2 ID and put it in the struct student Course 2 ID attribute
    printf("Enter Course2 Grade: ");            //ask user to enter Course 2 Grade
    scanf("%u", &new_student.Course2_grade);    //take Course 2 GRADE and put it in the struct student Course 2 GRADE attribute
    printf("Enter Course3 ID: ");               //ask user to enter Course 3 ID
    scanf("%u", &new_student.Course3_ID);       //take Course 3 ID and put it in the struct student Course 3 ID attribute
    printf("Enter Course3 Grade: ");            //ask user to enter Course 3 Grade
    scanf("%u", &new_student.Course3_grade);    //take Course 3 GRADE and put it in the struct student Course 3 GRADE attribute

    database[num_students++] = new_student;     //copy all data from new student to the data base of index number of students and increment number of students
    return True;                                //return 1 and finsh function 
}

void SDB_DeleteEntry(uint32 id) {               //delete student by taking his id this function didn't return any thing so its void
    for (uint8 i = 0; i < num_students; ++i) {  //loop on all students saved on data base
        if (database[i].Student_ID == id) {     //loop on all id in struct student  
            for (uint8 j = i; j < num_students - 1; ++j) {  //loop to rearrange the data base 
                database[j] = database[j + 1];              //decrement the index after the deleted entry and delet the entry
            }
            --num_students;                                //decrement num of students 
            printf("Student ID %u deleted.\n", id);        //print delete done 
            return;
        }
    }
    printf("Student ID %u not found.\n", id);              //print if id not exist in the data base
}

Bool SDB_ReadEntry(uint32 id) {                         // print student data by taking id of student and retern boolean true or false 
    for (uint8 i = 0; i < num_students; ++i) {          // loop on all elements in the data base
        if (database[i].Student_ID == id) {             //check on id if found 
            printf("Student ID: %u\n", database[i].Student_ID);                   //print student id 
            printf("Student Year: %u\n", database[i].Student_year);               //print student year
            printf("Course1 ID: %u, Grade: %u\n", database[i].Course1_ID, database[i].Course1_grade); //print couse 1 id and grade 
            printf("Course2 ID: %u, Grade: %u\n", database[i].Course2_ID, database[i].Course2_grade); //print couse 2 id and grade
            printf("Course3 ID: %u, Grade: %u\n", database[i].Course3_ID, database[i].Course3_grade); //print couse 3 id and grade
            return True;
        }
    }
    printf("Student ID %u not found.\n", id);    //print if id not exist in the data base
    return False;
}

void SDB_GetList(uint8 *count, uint32 *list) {    //function to list id of all students take pointer to number of students and pointer to list and return void
    *count = num_students;                        //buffer 
    for (uint8 i = 0; i < num_students; ++i) {    // loop on all elements in the data base
        list[i] = database[i].Student_ID;         //store all id of students in list array
    }
}

Bool SDB_IsIdExist (uint32 id) {                   //check if exist function check by using student id and return boolean true or false 
    for (uint8 i = 0; i < num_students; ++i) {     // loop on all elements in the data base
        if (database[i].Student_ID == id) {        //check on studen id if exist 
            return True;                           //if exist will return true 
        }
    }
    return False;                                  //else return false 
}
