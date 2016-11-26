#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdlib>
#include<cassert>
using namespace std;

//计数排序
//原理：采用哈希表的方式，对应元素，然后将对应元素对应到个数上面，然后按照个数还原出来整个序列，所得到的就是有序的序列。
template<typename T>
void CountSort(T* arr, int n)
{
	assert(arr);
	//寻找最大和最小的元素，得到范围，方便后续的哈希表的创建。
	T min = arr[0];
	T max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	//范围要+1	
	int range = max - min + 1;

	//创建一个零时空间
	T *tmp = new T[range];

	memset(tmp, 0, sizeof(T)*range);

	for (int i = 0; i < n; i++)
	{
		tmp[arr[i] - min]++;
	}


	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (tmp[i]--)
		{
			arr[index++] = i + min;

		}
	}


}


