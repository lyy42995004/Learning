#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct PeoInfo
{
    char name[15];
    char sex[3];
    int age;
    char tele[12];
    char addr[15];
}PeoInfo;

typedef struct Contact
{
    PeoInfo *data;
    int size;
    int capacity;
}Contact;

void Init_Contact(Contact * pc);
void Destory_Contact(Contact * pc);
void Add_Contact(Contact * pc);
void Show_Contact(const Contact * pc);
void Del_Contact(Contact * pc);
void Search_Contact(const Contact * pc);
void Modify_Contact(Contact * pc);
void Save_Contact(const Contact * pc);
void Load_Contact(Contact * pc);