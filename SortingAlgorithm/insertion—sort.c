#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void InsertionSort(char *p)
{
	assert(p);
	int len = strlen(p);
	int i = 0;
	int j = 0;
	for (i = 1; i < len - 1; i++)
	{
		char tmp = p[i];				//�����ﱣ���������к��һ��Ԫ��
		for (j = i - 1; j >= 0; j--)	//���к����������е�Ԫ�ؽ��бȽ�
		{
			if (tmp < p[j])				//�Ƚ��ж�
			{
				p[j + 1] = p[j];		//������������Ԫ�ص��ƶ�
			}
			else
			{
				break;					
			}
		}
		p[j+1] = tmp;					//����Ԫ�ز���
	}
	
}

//CPP�汾��
template<typename T>
void InsertSort(T* arr, int size)
{
	int pos = 0;
	for (int index = pos + 1; index < size; index++)
	{
		pos = index - 1;
		T tmp = arr[index];
		while (pos >= 0 && arr[pos] < tmp)
		{
			arr[pos + 1] = arr[pos];
			pos -= 1;
		}
		arr[pos + 1] = tmp;
	}

}
 
 
int main()
{
	char str[] = "17452198";
	InsertionSort(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}
