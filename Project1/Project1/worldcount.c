#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)；
int main(int argc, char *argv[])
{

	int count2, count1, start;
	FILE *fp;
	char c;
	if (argc != 3)
	{
		printf("Usage:./a.out Filename\n");
		exit(1);
	}
	fp = fopen(argv[1], "r");
	printf("%s文件中的", argv[1]);
	if (fp == NULL)
	{
		printf("Open Failed!\n");
		exit(1);
	}

	fseek(fp, 0, SEEK_SET);

	start = 1;  //0-单词开始  1-不是开头
	count1 = 0;
	count2 = 0;


	while (feof(fp) == 0)   //检测文件是否结束
	{
		fread(&c, 1, 1, fp);  //读取文件，每次读取一个字符串并保存在变量c中
		if ((c == ' ' || c == '\t' || c == '\n') && start == 1)			//
		{
			start = 1;
			count2++;
		}
		else if ((c != ' ' && c != '\t' && c != '\n') && start == 1)
		{
			start = 0;
			count1++;
		}
		else if ((c == ' ' || c == '\t' || c == '\n') && start == 0)
		{
			start = 1;
			count2++;
		}

	}
	if (*argv[2] == 'c')
		printf("单词个数%d\n", count1);

	if (*argv[2] == 'w')
	{
		printf("字符个数%d\n", count2);
	}





	return 1;
}