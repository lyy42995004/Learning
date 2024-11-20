#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 100

typedef struct PeoInfo
{
    char name[20];
    char sex[3];
    int age;
    char tele[12];
    char addr[20];
}PeoInfo;

typedef struct Contact
{
    PeoInfo data[MAX];
    int count;
}Contact;

void Init_PeoInfo(Contact *pc);
void Add_Contact(Contact *pc);
void Show_Contact(const Contact *pc);
void Del_Contact(Contact *pc);
void Serach_Contact(const Contact *pc);
void Modify_Contact(Contact *pc);
void Sort_Contact(Contact *pc);