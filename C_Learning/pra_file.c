#include <stdio.h>

struct Stu
{
	char name[20];
	int age;
	float score;
};

int main()
{
	struct Stu s = {"zhangsan", 20, 90.5};

	FILE* pf = fopen("./SelfLearning/Learn_C/file.txt", "wb");
	if (pf == NULL)
	{
		return 1;
	}
	//二进制的形式写文件
	fwrite(&s, sizeof(s), 1, pf);
	
	fclose(pf);
	pf = NULL;

	return 0;
}

// int main()
// {
//     FILE *pf;
//     pf = fopen("./SelfLearning/Learn_C/file.txt", "wb");
//     if (!pf)
//     {
//         perror("fopen");
//         return 1;
//     }
//     for(int i = 0; i < 26; i++)
//     {
//         fputc('a' + i, pf); 
//     }
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }