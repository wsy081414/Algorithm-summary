#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdlib>
#include<cassert>
using namespace std;

//��������
//ԭ�����ù�ϣ��ķ�ʽ����ӦԪ�أ�Ȼ�󽫶�ӦԪ�ض�Ӧ���������棬Ȼ���ո�����ԭ�����������У����õ��ľ�����������С�
template<typename T>
void CountSort(T* arr, int n)
{
	assert(arr);
	//Ѱ��������С��Ԫ�أ��õ���Χ����������Ĺ�ϣ��Ĵ�����
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

	//��ΧҪ+1	
	int range = max - min + 1;

	//����һ����ʱ�ռ�
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


