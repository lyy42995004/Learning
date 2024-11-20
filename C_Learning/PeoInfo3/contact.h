#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    PeoInfo data; 
    struct Contact *next;//不能直接用Contact
}Contact;

void Add_Contact(Contact ** ppHead);
void Show_Contact(const Contact ** ppHead);
void Del_Contact(Contact ** ppHead);
void Search_Contact(const Contact ** ppHead);
void Modify_Contact(Contact ** ppHead);
void Sort_Contact(Contact ** ppHead);
void Destory_Contact(Contact ** ppHead);
void Save_Contact(const Contact ** ppHead);
void Load_Contact(Contact ** ppHead);