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


//选择排序
//一次就选择出最小的和最大的
template<typename T>
void SelectSort2(T*arr,int n)
{
	assert(arr);
	int left = 0;
	int right = n-1;
	while (left < right)
	{
		int min = left;
		int max = right;
		for (int i = left; i <= right ; i++)
		{
			if (arr[i] < arr[min])
				min = i;
			if(arr[i] > arr[max])
				max = i;
		}
		//考虑修正的情况，最大值在最小位置，最小值在最大位置。
		swap(arr[max], arr[right]);

		if (min == right)
		{
			min = max;
		}
		swap(arr[min], arr[left]);
		left++;
		right--;
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
