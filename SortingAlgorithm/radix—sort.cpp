#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdlib>

using namespace std;

//�õ�����λ����
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


//�������򣺴Ӹ�λ�Ƚ�������Ȼ�����ν���ʮλ��Ȼ��������ǰ��
template<typename T>
void RadixSort(T* arr, int n)
{
	assert(arr);
	
	//�õ����λ��
	int base = 1;
	int digit = GetMaxDigit(arr, n);
	int count[10] = { 0 };
	int position[10] = { 0 };
	T* tmp = new T[n];


	while (digit--)
	{
		memset(count, 0, sizeof(T)* 10);
		//ͳ�����λ��0-9�ĸ���
		for (int i = 0; i < n; i++)
		{
			//��Ӧ��tmp���λ
			count[(arr[i] / base) % 10]++;
		}
		//�����Ӧ��λ��������ʼλ��
		position[0] = 0;
		for (int i = 1; i < 10; i++)
		{
			position[i] = position[i - 1] + count[i - 1];
		}
		//��������tmp�е�����
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