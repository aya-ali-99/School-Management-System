#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct birth{
    int day;
    int month;
    int year;
}birth;

typedef struct student{
    char name[50];
    char address[50];
    char phoneNo[13];
    int score;
    int ID;
    birth birthday;
}Student;

typedef struct listnode{
    Student entry;
    struct listnode *next, *pre;
}lstNode;

typedef struct lst{
    lstNode *top;
    int siz;
}lst;
void CreateList(lst *);
void MAIN_MENU();
void NEW_STUDENT(lst *);
void DELETE_STUDENT(lst *);
void STUDENT_LIST(lst *);
void STUDENT_EDIT(lst *);
void RANK_STUDENT(lst *);
void STUDENT_SCORE(lst *);
char ListEmpty(lst *);
char ListFull(lst *);
void SwapN(lst *Pl, lstNode *tmp, lstNode *tmp2);

#endif // HEADER_H_INCLUDED
