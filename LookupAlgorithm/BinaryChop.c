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
		if (arr[mid] >= arr[left]) //mid���������
		{
			if (arr[left] > key || arr[mid] < key)
				left = mid + 1;    //x���ұ�����
			else
				right = mid - 1;   //x���������
		}
		else					   //mid���ұ�����
		{
			if (arr[right] < key || arr[mid] > key)
				right = mid - 1;   //x���������
			else
				left = mid + 1;    //x���ұ�����
		}
	}
	return -1;

	}
int main()
{


	char arr[] = "123456789";
	char ch = 0;
	int ret = 0;
	printf("�������������ҵ��ַ���\n");
	scanf("%c", &ch);
	fflush(stdin);
	ret=BinarySearch2(arr,ch);
	printf("%d", ret);
	system("pause");
	return 0;
}