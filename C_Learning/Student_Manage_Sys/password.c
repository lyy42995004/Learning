#include "password.h"

void password_menu()
{
    printf("------------------------------\n");
    printf("        1.注册\n");
    printf("        2.登录\n");
    printf("        3.忘记密码\n");
    printf("        0.退出\n");
    printf("------------------------------\n");
}

void Register()
{
    FILE *pfRead = fopen("./../Users.dat", "rb");
    if (!pfRead)
    {
        perror("register pfread fopen");
        return;
    }
    Users new = {0};
    Users past = {0};
    printf("请输入用户名:");
    scanf("%s", new.id);
    fread(&past, sizeof(Users), 1, pfRead);
    while (1)
    {
        if (strcmp(new.id, past.id) == 0)
        {
            printf("用户名重复, 请重新注册\n");
            return;
        }
        else
        {
            if (!feof(pfRead))
                fread(&past, sizeof(Users), 1, pfRead);
            else
                break;
        }
    }
    fclose(pfRead);
    pfRead = NULL;
    char temp[20] = {0};
    while (1)
    {
        printf("请输入密码:");
        scanf("%s", new.password);
        printf("请再次输入密码:");
        scanf("%s", temp);
        if (strcmp(temp, new.password) != 0)
            printf("两次密码不同, 请重新输入\n");
        else
        {
            FILE *pfWrite = fopen("./../Users.dat", "ab");
            if (!pfWrite)
            {
                perror("reigster pfwrite fopen");
                return;
            }
            fwrite(&new, sizeof(Users), 1, pfWrite);
            fclose(pfWrite);
            pfWrite = NULL;
            printf("注册成功\n");
            return;
        }
    }
}

int Login()
{
    FILE *pfRead = fopen("./../Users.dat", "rb");
    if (!pfRead)
    {
        perror("login fopen");
        return 0;
    }
    Users input = {0};
    Users past = {0};
    fread(&past, sizeof(Users), 1, pfRead);
    printf("请输入用户名:");
    scanf("%s", input.id);
    while (1)
    {
        if (strcmp(input.id, past.id) == 0)
            break;
        else
        {
            if (!feof(pfRead))
                fread(&past, sizeof(Users), 1, pfRead);
            else
            {
                printf("用户名输入错误, 请重新登录\n");
                fclose(pfRead);
                pfRead = NULL;
                return 0;
            }
        }
    }
    printf("请输入密码:");
    scanf("%s", input.password);
    if (strcmp(input.password, past.password) == 0)
    {
        printf("登录成功\n");
        fclose(pfRead);
        pfRead = NULL;
        return 1;
    }
    else
    {
        printf("密码错误, 请重新登录\n");
        fclose(pfRead);
        pfRead = NULL;
        return 0;
    }
}

void Reback()
{
    FILE *pfModify = fopen("./../Users.dat", "rb+");
    if (!pfModify)
    {
        perror("reback fopen");
        return;
    }
    Users input = {0};
    Users past = {0};
    fread(&past, sizeof(Users), 1, pfModify);
    printf("请输入用户名:");
    scanf("%s", input.id);
    while (1)
    {
        if (strcmp(input.id, past.id) == 0)
            break;
        else
        {
            if (!feof(pfModify))
                fread(&past, sizeof(Users), 1, pfModify);
            else
            {
                printf("用户名输入错误, 请重新输入\n");
                return;
            }
        }
    } 
    printf("输入:woshizhu\n");
    while(1)
    {
        char temp[20] = {0};
        scanf("%s", temp);
        if(strcmp(temp, "woshizhu") == 0)
            break;
        else
            printf("请重新输入\n");
    }
    char new_password[20];
    char cmp_password[20];
    while(1)
    {
        printf("请输入新的密码:");
        scanf("%s", new_password);
        printf("请输入新的密码:");
        scanf("%s", cmp_password);
        if(strcmp(new_password, cmp_password) == 0)
            break;
        else
            printf("两次密码输入不同, 请重新输入\n");
    }
    fseek(pfModify, -sizeof(input.password), SEEK_CUR);
    fwrite(&new_password, sizeof(input.password), 1, pfModify);
    fclose(pfModify);
    pfModify = NULL;
    printf("密码修改成功\n");
}

int Password()
{
    int input;
    int flag = 0;
    do
    {
        password_menu();
        printf("请选择:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            Register();
            break;
        case 2:
            flag = Login();
            if (flag)
                return flag;
            else
                break;
        case 3:
            Reback();
            break;
        case 0:
            printf("退出\n");
            break;
        default:
            printf("选择错误, 请重新选择\n");
            break;
        }
    } while (input);
    return flag;
}