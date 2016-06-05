#define _CRT_SECURE_NO_WARNINGS 1





#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
void SelectSort(char *str)
{
	assert(str);
	int i = 0;
	int min = 0;
	int j = 0;
	int len = strlen(str);
	for (i = 1; i < len - 1; i++)
	{
		min = i + 1;						//����Ĭ�������һ��Ϊ��С��
		for (j = i + 1; j < len - 1; j++)
		{
			if (str[min]>str[j])			
			{
				min = j;					//�������������еıȽϣ��õ���С���±�
			}
		}
		if (min != i)						//��������������С��Ԫ���������Ԫ�ؽ����滻
		{
			char tmp = str[i];
			str[i] = str[min];
			str[min] = tmp;
		}
	}
}

int main()
{
	char str[] = "17452198";
	SelectSort(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}
