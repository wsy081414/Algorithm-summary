#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int  BinarySearch1(const char *arr,int key)
{
	int len = strlen(arr);
	int mid = 0;
	int left =0;
	int right = len-1;
	while (left <= right)
	{
		mid = (left + right) >> 1;
		if (key > arr[mid])
			left = mid + 1;
		else if (key < arr[mid])
			right = mid - 1;
		else
			return mid;
	}
	return 0;

}
int BinarySearch2(const char *arr, int key)
{
	int len = strlen(arr);
	int mid = 0;
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		mid = (left + right) >> 1;
		if (arr[mid] == key)
		{
			return mid;
		}
		if (arr[mid] >= arr[left]) //mid在左边序列
		{
			if (arr[left] > key || arr[mid] < key)
				left = mid + 1;    //x在右边序列
			else
				right = mid - 1;   //x在左边序列
		}
		else					   //mid在右边序列
		{
			if (arr[right] < key || arr[mid] > key)
				right = mid - 1;   //x在左边序列
			else
				left = mid + 1;    //x在右边序列
		}
	}
	return -1;

	}
	int BinarySearch3(char *arr,size_t left,size_t right, int key)
{
	if (left > right)
		return -1;
	size_t mid = left + right / 2;
	if (arr[mid > key])
	{
		return BinarySearch3(arr, mid + 1, right, key);
	}
	else
	{
		return BinarySearch3(arr, left, mid - 1, key);
	}
	return mid;
}
int main()
{


	char arr[] = "123456789";
	char ch = 0;
	int ret = 0;
	printf("请输入你所查找的字符：\n");
	scanf("%c", &ch);
	fflush(stdin);
	ret=BinarySearch2(arr,ch);
	printf("%d", ret);
	system("pause");
	return 0;
}