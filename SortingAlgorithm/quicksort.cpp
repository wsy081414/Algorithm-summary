
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdlib>

using namespace std;



//���ŵ��Ż��ķ�������λȡ��
//ȡ��һ����λ�������ڿ�����˵������ʹ��ʱ�临�Ӷȸ��ӽӽ�logN
template<typename T>
int SelectMid(T* arr, int begin, int end)
{
	int left = begin;
	int right = end;

	//(begin+end)>>1;
	int mid = begin + ((end - begin) >> 1);

	if (arr[left]<arr[mid])
	{
		if (arr[right]>arr[mid])
			return mid;
		if (arr[left] < arr[right])
			return right;
		else
			return left;
	}
	else
	{
		if (arr[right] < arr[mid])
			return mid;
		if (arr[right]>arr[left])
			return left;
		else
			return right;
	}
}

//���⵱����Ľڵ���ĿС��ʱ�����ʱ��Ϳ��Խ����Ż�Ϊ��������
//��Ϊ���ʱ���Ѿ����������ˣ����ʱ��������������õ������
//���ʱ��Ĳ�������ʱ�临�ӶȽӽ�N


//����ָ�뷨
template<typename T>
int portsort(T* arr, int begin, int end)
{
	assert(arr);
	int left = begin;
	int right = end;
	//������λȡ���Ż�Ч�ʣ�����key����С�������ֵ�������
	int mid = SelectMid(arr, begin, end);
	std::swap(arr[mid], arr[end]);
	T key = arr[end];
	while (left<right)
	{
		while (left<right&&arr[left] <= key)
		{
			left++;
		}

		while (left<right&&arr[right] >= key)
		{
			right--;
		}
		//��߱�key��ĺ��ұ߱�keyС�Ľ��н���
		if (arr[left]>arr[right])
		{
			swap(arr[left], arr[right]);
		}
	}
	//��������key
	swap(arr[left], arr[end]);

	return left;
}

template<typename T>
void QuickSort1(T* arr, int begin, int end)
{
	assert(arr);
	if (end-begin > 13)
	{
		int div = portsort(arr, begin, end);
		QuickSort1(arr, begin, div - 1);
		QuickSort1(arr, div + 1, end);
	}
	else
	{
		InsertSort(arr+begin, (end - begin + 1) );
	}

}

//�ڿӷ�

template<typename T>
int PortSort2(T* arr, int begin, int end)
{
	assert(arr);
	int left = begin;
	int right = end;
	int mid = SelectMid(arr, begin, end);
	std::swap(arr[mid], arr[end]);
	//���һ����Ϊ��
	T hole = arr[end];
	while (left<right)
	{
		while (left<right&&arr[left] <= hole)
		{
			left++;
		}
		//���
		if (left < right)
			arr[right--] = arr[left];
		while (left < right&&arr[right] >= hole)
		{
			right--;
		}
		//���
		if (left < right)
			arr[left++] = arr[right];
	}
	//���λ��Ϊ�ӳ�ʼԪ��
	arr[left] = hole;
	return left;
}
template<typename T>
void QuickSort2(T* arr, int begin, int end)
{
	assert(arr);
	if (end - begin>13)
	{
		//���е�һ�ε�������
		int div = PortSort2(arr, begin, end);
		//�ݹ������⣬��������
		QuickSort2(arr, begin, div - 1);
		//�ݹ�������
		QuickSort2(arr, div + 1, end);
	}
	else
	{
		InsertSort(arr+begin, end - begin + 1);
	}
}

//�����ַ�����ǰ��ָ�뷽����һ��cur��һ��prev�����ʱ��prev��ʼ��Ϊbegin-1��
//Ȼ�����Ǿ���cur��һ����keyС�ģ��ҵ��Ժ�prev++��Ȼ���arr[prev]��arr[end]���н���
//��ʵ�ﵽ��Ч�����ǰ�С�ķŵ�ǰ�棬�ŵ�ǰ�档����key�ŵ�prev+1��λ�þͺ��ˡ�

template<typename T>
int PortSort3(T* arr, int begin, int end)
{
	assert(arr);
	int prev = -1;
	int cur = 0;
	int pos = SelectMid(arr, begin, end);
	std::swap(arr[pos], arr[end]);
	T key = arr[end];
	while (cur < end)
	{
		if (arr[cur]<key&&++prev != cur)
		{
			std::swap(arr[cur], arr[prev]);
		}
		cur++;
	}
	std::swap(arr[++prev], arr[end]);
	return prev;
}
template<typename T>
void QuickSort3(T* arr, int begin, int end)
{
	assert(arr);
	if (end - begin>13)
	{
		//���е�һ�ε�������
		int div = PortSort3(arr, begin, end);
		//�ݹ������⣬��������
		QuickSort3(arr, begin, div - 1);
		//�ݹ�������
		QuickSort3(arr, div + 1, end);
	}
	else
	{
		InsertSort(arr+begin, end - begin + 1);
	}
}


//�ǵݹ�Ŀ�������
//�ǵݹ�Ľ����ʽ��������ջ���н��
template<typename T>
void QuickSort4(T* arr, int begin, int end)
{
	assert(arr);
	std::stack<int> q;
	q.push(begin);
	q.push(end);
	while (!q.empty())
	{
		int right = q.top();
		q.pop();
		int left = q.top();
		q.pop();
		if (right > left)
		{
			int div = PortSort2(arr, left, right);

			q.push(left);
			q.push(div - 1);

			q.push(div + 1);
			q.push(right);
		}
	}
}
