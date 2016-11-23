
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdlib>

using namespace std;



//快排的优化的方法：三位取中
//取得一个中位数，对于快排来说，可以使得时间复杂度更加接近logN
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

//另外当区间的节点数目小的时候，这个时候就可以进行优化为插入排序，
//因为这个时候已经近似有序了，这个时候插入排序就是最好的情况了
//这个时候的插入排序时间复杂度接近N


//左右指针法
template<typename T>
int portsort(T* arr, int begin, int end)
{
	assert(arr);
	int left = begin;
	int right = end;
	//利用三位取中优化效率，避免key是最小或者最大值的情况。
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
		//左边比key大的和右边比key小的进行交换
		if (arr[left]>arr[right])
		{
			swap(arr[left], arr[right]);
		}
	}
	//修正放入key
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

//挖坑法

template<typename T>
int PortSort2(T* arr, int begin, int end)
{
	assert(arr);
	int left = begin;
	int right = end;
	int mid = SelectMid(arr, begin, end);
	std::swap(arr[mid], arr[end]);
	//最后一个作为坑
	T hole = arr[end];
	while (left<right)
	{
		while (left<right&&arr[left] <= hole)
		{
			left++;
		}
		//填坑
		if (left < right)
			arr[right--] = arr[left];
		while (left < right&&arr[right] >= hole)
		{
			right--;
		}
		//填坑
		if (left < right)
			arr[left++] = arr[right];
	}
	//最后位置为坑初始元素
	arr[left] = hole;
	return left;
}
template<typename T>
void QuickSort2(T* arr, int begin, int end)
{
	assert(arr);
	if (end - begin>13)
	{
		//进行第一次单趟排序
		int div = PortSort2(arr, begin, end);
		//递归子问题，划分区间
		QuickSort2(arr, begin, div - 1);
		//递归子问题
		QuickSort2(arr, div + 1, end);
	}
	else
	{
		InsertSort(arr+begin, end - begin + 1);
	}
}

//第三种方法：前后指针方法，一个cur，一个prev，这个时候prev初始化为begin-1，
//然后我们就是cur找一个比key小的，找到以后prev++，然后把arr[prev]和arr[end]进行交换
//其实达到的效果就是把小的放到前面，放到前面。最后把key放到prev+1的位置就好了。

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
		//进行第一次单趟排序
		int div = PortSort3(arr, begin, end);
		//递归子问题，划分区间
		QuickSort3(arr, begin, div - 1);
		//递归子问题
		QuickSort3(arr, div + 1, end);
	}
	else
	{
		InsertSort(arr+begin, end - begin + 1);
	}
}


//非递归的快速排序
//非递归的解决方式就是利用栈进行解决
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
