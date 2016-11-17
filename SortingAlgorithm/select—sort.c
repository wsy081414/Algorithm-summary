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
		min = i + 1;						//首先默认无序第一个为最小的
		for (j = i + 1; j < len - 1; j++)
		{
			if (str[min]>str[j])			
			{
				min = j;					//进行无序序列中的比较，得到最小的下标
			}
		}
		if (min != i)						//把无序序列中最小的元素与有序的元素进行替换
		{
			char tmp = str[i];
			str[i] = str[min];
			str[min] = tmp;
		}
	}
}

//Cpp版本
template<typename T>
void SelectSort(T* arr,int n)
{
	int max = 0;
	for (int index = 0; index < n-1; index++)
	{
		max = index ;
		int pos = index + 1;
		//找出最值
		while (pos<n)
		{
			if (arr[pos]>arr[max])
			{
				max = pos;				
			}
			pos++;
		}
		//交换
		std::swap(arr[index], arr[max]);
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
