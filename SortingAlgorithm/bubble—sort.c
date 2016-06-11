#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//冒泡排序
void BubbleSort(char *p)
{
	int i = 0;
	int len = strlen(p);
	int j = 0;

	for (i = 0; i < len - 1; i++)
	{

		for (j = 0; j < len - 1 - i; j++)
		{
			if (*(p + j) > *(p + j + 1))		//进行比较交换
			{
				char tmp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = tmp;

			}
		}

	}
}
//冒泡排序第一种优化方式：给标志位，不需要进行对有序的进行冒泡排序。
void BubbleSort1(char *p)
{
	int i = 0;
	int len = strlen(p);
	int j = 0;
	int flag = 0;							//给一个标志
	for (i = 0; i < len - 1; i++)
	{
		flag = 1;							//把标志置1
		for (j = 0; j < len - 1 - i; j++)
		{
			if (*(p + j) > *(p + j + 1))
			{
				char tmp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = tmp;
				flag = 0;					//冒泡了以后把标志置0
			}
		}
		if (flag)							//判断标志，如果标志为1表示后面的都为有序，所以不需要再冒泡
		{
			break;
		}
	}
}
//冒泡排序第二种优化方式：记住最后排序好的位置，然后就不需要冒泡后续的。
void BubbleSort2(char *p)
{
	int i = 0;
	int len = strlen(p);
	int j = 0;
	int k = len-1;
	int tmp = 0;
	int m = 0;								//记录你进行冒泡后最后移动到的位置
	int flag = 0;							//给一个标志
	for (i = 0; i < len - 1; i++)
	{
		flag = 1;							//把标志置1
		m = 0;
		for (j = 0; j < k; j++)				//每次进行排序的只有前一半部分
		{
			if (*(p + j) > *(p + j + 1))
			{
				char tmp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = tmp;
				flag = 0;					//冒泡了以后把标志置0
				m = j;						//记录每一次的位置
			}
		}
		if (flag)							//判断标志，如果标志为1表示后面的都为有序，所以不需要再冒泡
		{
			break;
		}
		k = m;								//记住最后排序到的位置，后面再排序就直排前面的
	}

}

int main()
{
	char p[] = "17452198";
	BubbleSort2(p);
	printf("%s\n", p);
	system("pause");
	return 0;
}



