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

//�ڿӷ�

template<typename T>
int PortSort2(T* arr, int begin, int end)
{
	assert(arr);
	int left = begin;
	int right = end;
	//���һ����Ϊ��
	int hole = arr[end];
	while (left<right)
	{
		while (left<right&&arr[left]<=hole)
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
	if (begin < end)
	{
		//���е�һ�ε�������
		int div = PortSort2(arr, begin, end);
		//�ݹ������⣬��������
		QuickSort2(arr, begin, div - 1);
		//�ݹ�������
		QuickSort2(arr, div + 1, end);
	}
}