#pragma once

#include <stdio.h>
#include <string.h>

typedef struct Users
{
    char id[20];
    char password[20];
}Users;

int Password();
void Register();
int Login();
void Reback();