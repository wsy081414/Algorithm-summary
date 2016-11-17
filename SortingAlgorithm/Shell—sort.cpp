#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdlib>

using namespace std;

//ϣ��������Ϊ�˽��ֱ�Ӳ��������������������ֱ�Ӳ���������������ǽ�������������������ϣ��������ǰ���������ýӽ�����
//ϣ���������黮��Ϊ�����飬Ȼ��Զ�Ӧ�Ŀ���±�������ͬ��Ԫ�ؽ��������ܹ����ٴﵽ�Ѵ�ķ�ǰ�棬С�ķź��棨����������෴����


template<typename T>
void ShellSort(T *arr, int size)
{
	
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		int pos = 0;
  		for (int index = pos + gap; index < size; index++)
		{
			pos = index - gap;
			T tmp = arr[index];
			while (pos >= 0&&arr[pos] < tmp)
			{
				//ע��ÿһ������������ǰһ������ô�ڴ������У�����ǰgapλ�õģ�ֱ�Ӳ������ǰ1����
				arr[pos+gap] = arr[pos];
				pos -= gap;
			}
			arr[pos+gap] = tmp;
		}
	
	}
}

void test1()
{
	int arr[] = { 1,2,3,46,5,6,7,54,9 };
	ShellSort(arr, sizeof(arr) / sizeof(arr[0]));

}

int main()
{
	test1();
	system("pause");
	return 0;
}