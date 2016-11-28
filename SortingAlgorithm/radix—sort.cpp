#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdlib>

using namespace std;

//得到最大的位数。
template<typename T>
size_t GetMaxDigit(T *arr, int n)
{
	int base = 10;
	int digit = 1;
	int i = 0;
	for (int i = 0; i< n; ++i)
	{
		while (arr[i] >= base)
		{
			digit++;
			base *= 10;
		}
	}
	return digit;
}


//基数排序：从个位先进行排序，然后依次进行十位，然后依次向前。
template<typename T>
void RadixSort(T* arr, int n)
{
	assert(arr);
	
	//得到最大位数
	int base = 1;
	int digit = GetMaxDigit(arr, n);
	int count[10] = { 0 };
	int position[10] = { 0 };
	T* tmp = new T[n];


	while (digit--)
	{
		memset(count, 0, sizeof(T)* 10);
		//统计最低位从0-9的个数
		for (int i = 0; i < n; i++)
		{
			//对应的tmp最低位
			count[(arr[i] / base) % 10]++;
		}
		//计算对应低位的所在起始位置
		position[0] = 0;
		for (int i = 1; i < 10; i++)
		{
			position[i] = position[i - 1] + count[i - 1];
		}
		//进行设置tmp中的数。
		for (int i = 0; i < n; i++)
		{
			int num = (arr[i] / base) % 10;
			tmp[position[num]++] = arr[i];
			count[num]--;
		}
		for (int i = 0; i < n; i++)
		{
			arr[i] = tmp[i];
		}
		base *= 10;
	}

	delete[] tmp;

}