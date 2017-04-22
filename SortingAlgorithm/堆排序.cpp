#include<iostream>
#include<cassert>
#include<cstdlib>

using namespace std;

//当你需要降序的时候，你需要小堆，当你需要升序的时候，你需要大堆
//时间复杂度：N*logN
//建堆加上调整的：
//N*logN+N*logN=2N*logN

template<typename T>
void AdjustDown(T* arr, size_t root,size_t count)
{
	assert(arr);
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (paren < count)
	{
		//找出两个孩子当中最大的下标
		if (child + 1 < count&&arr[child + 1]<arr[child])
		{
			++child;
		}
		//中出以后把孩子和父亲进行交换，然后向下进行调整。
		if (child<count&&arr[child] < arr[parent])
		{
			std::swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else 
		{
			break;
		}
	}

}


template<typename T>
void HeapSort(T* arr, size_t size)
{
	assert(arr);
	
	//建堆
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, i,size);
	}
	
	//然后把大堆上面的最大的和最后一个交换，然后从其中进行向下调整，找出最大的。
	size_t end = size - 1;
	
	//
	while (end > 0)
	{
		swap(arr[0], arr[end]);
		AdjustDown(arr, 0, end);
		end--;
	}

}

void test1()
{
	int arr[] = { 1,2,3,4,5,6 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
}

int main()
{
	test1();
	system("pause");
	return 0;
}