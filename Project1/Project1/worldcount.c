#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)��
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
	printf("%s�ļ��е�", argv[1]);
	if (fp == NULL)
	{
		printf("Open Failed!\n");
		exit(1);
	}

	fseek(fp, 0, SEEK_SET);

	start = 1;  //0-���ʿ�ʼ  1-���ǿ�ͷ
	count1 = 0;
	count2 = 0;


	while (feof(fp) == 0)   //����ļ��Ƿ����
	{
		fread(&c, 1, 1, fp);  //��ȡ�ļ���ÿ�ζ�ȡһ���ַ����������ڱ���c��
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
		printf("���ʸ���%d\n", count1);

	if (*argv[2] == 'w')
	{
		printf("�ַ�����%d\n", count2);
	}





	return 1;
}