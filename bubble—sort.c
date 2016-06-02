#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//ð������
void BubbleSort(char *p)
{
	int i = 0;
	int len = strlen(p);
	int j = 0;

	for (i = 0; i < len - 1; i++)
	{

		for (j = 0; j < len - 1 - i; j++)
		{
			if (*(p + j) > *(p + j + 1))		//���бȽϽ���
			{
				char tmp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = tmp;

			}
		}

	}
}
//ð�������һ���Ż���ʽ������־λ������Ҫ���ж�����Ľ���ð������
void BubbleSort1(char *p)
{
	int i = 0;
	int len = strlen(p);
	int j = 0;
	int flag = 0;							//��һ����־
	for (i = 0; i < len - 1; i++)
	{
		flag = 1;							//�ѱ�־��1
		for (j = 0; j < len - 1 - i; j++)
		{
			if (*(p + j) > *(p + j + 1))
			{
				char tmp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = tmp;
				flag = 0;					//ð�����Ժ�ѱ�־��0
			}
		}
		if (flag)							//�жϱ�־�������־Ϊ1��ʾ����Ķ�Ϊ�������Բ���Ҫ��ð��
		{
			break;
		}
	}
}
//ð������ڶ����Ż���ʽ����ס�������õ�λ�ã�Ȼ��Ͳ���Ҫð�ݺ����ġ�
void BubbleSort2(char *p)
{
	int i = 0;
	int len = strlen(p);
	int j = 0;
	int k = len-1;
	int tmp = 0;
	int m = 0;								//��¼�����ð�ݺ�����ƶ�����λ��
	int flag = 0;							//��һ����־
	for (i = 0; i < len - 1; i++)
	{
		flag = 1;							//�ѱ�־��1
		m = 0;
		for (j = 0; j < k; j++)				//ÿ�ν��������ֻ��ǰһ�벿��
		{
			if (*(p + j) > *(p + j + 1))
			{
				char tmp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = tmp;
				flag = 0;					//ð�����Ժ�ѱ�־��0
				m = j;						//��¼ÿһ�ε�λ��
			}
		}
		if (flag)							//�жϱ�־�������־Ϊ1��ʾ����Ķ�Ϊ�������Բ���Ҫ��ð��
		{
			break;
		}
		k = m;								//��ס������򵽵�λ�ã������������ֱ��ǰ���
	}

}

int main()
{
	char p[] = "17452198";
	BubbleSort2(p);
	printf("%s\n", p);
	system("pause");
	return 0;
}



