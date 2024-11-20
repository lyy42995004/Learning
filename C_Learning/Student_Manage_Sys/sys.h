#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Student
{
    char num[10];
    char name[15];
    char class[10];
    int math;
    int english;
    int c_language;
    double average;
}Student;

typedef struct LinkList
{
    Student data; 
    struct LinkList *next;//不能直接用LinkList
}LinkList;

void Add_LinkList(LinkList ** ppHead);
void Show_LinkList(const LinkList ** ppHead);
int Search_LinkList(const LinkList ** ppHead);
void Del_LinkList(LinkList ** ppHead);
void Modify_LinkList(LinkList ** ppHead);
void Sort_LinkList(LinkList ** ppHead);
void Count_LinkList(const LinkList ** ppHead);
void Destory_LinkList(LinkList ** ppHead);
void Save_LinkList(const LinkList ** ppHead);
void Load_LinkList(LinkList ** ppHead);