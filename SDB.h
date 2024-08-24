#ifndef SDB_H          //header guard
#define SDB_H

#include "STD.h"

#define MAX_STUDENTS 10      //macro max student = 10 

typedef struct SimpleDb      //struct simpledb and defined by student
{
uint32 Student_ID;
uint32 Student_year;
uint32 Course1_ID;
uint32 Course1_grade;
uint32 Course2_ID;
uint32 Course2_grade;
uint32 Course3_ID;
uint32 Course3_grade;
} student;

//functions decleration 
Bool SDB_IsFull ();
uint8 SDB_GetUsedSize();
Bool SDB_AddEntry();
void SDB_DeleteEntry (uint32 id);
Bool SDB_ReadEntry (uint32 id);
void SDB_GetList (uint8 * count, uint32 * list);
Bool SDB_IsIdExist (uint32 id);
#endif