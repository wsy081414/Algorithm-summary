#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdlib>

using namespace std;

//希尔排序是为了解决直接插入排序的最差情况的排序，直接插入排序的最好情况是近似有序，最差情况是逆序，希尔排序就是把最差情况变得接近有序。
//希尔排序将数组划分为几个块，然后对对应的快的下标求余相同的元素进行排序，能够快速达到把大的放前面，小的放后面（如果是升序相反）。


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
				//注意每一次向有序区的前一个，那么在带增量中，就是前gap位置的，直接插入就是前1个。
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