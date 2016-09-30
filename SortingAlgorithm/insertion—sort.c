#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void InsertionSort(char *p)
{
	assert(p);
	int len = strlen(p);
	int i = 0;
	int j = 0;
	for (i = 1; i < len - 1; i++)
	{
		char tmp = p[i];				//在这里保存有序序列后的一个元素
		for (j = i - 1; j >= 0; j--)	//进行和有序序列中的元素进行比较
		{
			if (tmp < p[j])				//比较判断
			{
				p[j + 1] = p[j];		//进行有序序列元素的移动
			}
			else
			{
				break;					
			}
		}
		p[j+1] = tmp;					//进行元素插入
	}
	
}

 
 
int main()
{
	char str[] = "17452198";
	InsertionSort(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}
