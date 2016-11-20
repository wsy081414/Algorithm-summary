template<typename T>
int portsort(T* arr,int begin,int end)
{
	assert(arr);
	T key = arr[end];
	int left = begin;
	int right = end;
	while (left<right)
	{
		while (left<right&&arr[left]<=key)
		{
			left++;
		}
		
		while (left<right&&arr[right]>=key)
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
void QuickSort(T* arr, int begin,int end)
{
	assert(arr);
	if (begin < end)
	{
		int div = portsort(arr, begin, end);
		QuickSort(arr, begin, div - 1);
		QuickSort(arr, div + 1, end);
	}

}

//挖坑法

template<typename T>
int PortSort2(T* arr, int begin, int end)
{
	assert(arr);
	int left = begin;
	int right = end;
	//最后一个作为坑
	int hole = arr[end];
	while (left<right)
	{
		while (left<right&&arr[left]<=hole)
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
	if (begin < end)
	{
		//进行第一次单趟排序
		int div = PortSort2(arr, begin, end);
		//递归子问题，划分区间
		QuickSort2(arr, begin, div - 1);
		//递归子问题
		QuickSort2(arr, div + 1, end);
	}
}