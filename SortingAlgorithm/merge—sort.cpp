

//递归解决归并排序
template<typename T>
void MergeSort1(T* arr, int n)
{
	T* tmp = new T[n];
	assert(tmp);
	for (int i = 0; i < n; i++)
	{
		tmp[i] = arr[i];
	}
	merge_sort1(arr,tmp, 0, n - 1);

}

template<typename T>
void merge_sort1(T* arr, T* tmp, int begin, int end)
{
	assert(arr);
	assert(tmp);
	if (begin == end)
		return;
	int mid = begin + ((end - begin) >> 1);
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	//递归过程	
	merge_sort1(arr , tmp, begin1, end1);
	merge_sort1(arr , tmp, begin2, end2);
	
	int t = begin;
	//进行两个区间归并
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (arr[begin1] > arr[begin2])
		{
			tmp[t++] = arr[begin2++];
		}
		else
		{
			tmp[t++] = arr[begin1++];
		}
	}

	//如果比较完后，一个有剩余
	
	while (begin1<=end1)
	{
		tmp[t++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[t++] = arr[begin2++];
	}
	//转到原来的空间上
	for (int i = 0; i <= end; i++)
	{
		arr[i] = tmp[i];
	}

	
}
