#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

//��鲢����
//��Ҫ�����ⲿ�鲢����
//����Ҫ���ǽ��д��ļ��з�С�ļ���
//Ȼ��С�ļ��ٴν��й鲢������ļ������չ鲢�����Ĵ��ļ����������Ľ����


class ExternalMergeSort
{
public:
	ExternalMergeSort(const string & s)
		:_filename(s)
	{}
	//�з��ļ�
	void SplitFile(const string& a,size_t line)
	{
		string str;
		FILE* fin = fopen(a.c_str(), "r");
		assert(fin);
		string count="0";
		int countline=0;
		while (ReadLine(fin, str))
		{
			
			string CutFileName = a;
			int pos = a.rfind('.');
			CutFileName = CutFileName.substr(0, pos);
			CutFileName += count+".txt";
			_file.push_back(CutFileName);
			FILE* fout = fopen(CutFileName.c_str(), "w");
			string num;
			//���ж�ȡ���ʣ�Ȼ������
			std::vector<int >s;
			int i = 0;
			char ch = str[i++];
			num += ch;
			while (i<str.size()&&ch != '\n')
			{
				if (ch == ' ')
				{
					s.push_back(atoi(num.c_str()));
					num.clear();
				}
				ch = str[i++];
				num += ch;
			}
			s.push_back(atoi(num.c_str()));
			num.clear();

			sort(s.begin(), s.end());
			
			std::vector<int>::iterator it = s.begin();
			char buf[33];
			while (it!=s.end())
			{
				_itoa(*it, buf, 10);
				fprintf(fout, buf);
				fputc(' ', fout);
				it++;
			}
			fclose(fout);
			
			str.clear();
			char countbuf[4];
			int index = atoi(count.c_str())+1;
			_itoa(index, countbuf, 10);
			count.clear();
			count += countbuf;
			countline++;
			//count++;
		}
		fclose(fin);
	}
	//���й鲢��
	void Mergefile()
	{
		string count = "1";
		while (_file.size()>1)
		{

			std::vector<string> newfile;
			int index = 0;

			
			while (index < _file.size() && index + 1 < _file.size())
			{
				
				string newfilename ="merge"+count+".txt";
				
				char countbuf[5];
				int num = atoi(count.c_str()) + 1;
				_itoa(num, countbuf, 10);
				count.clear();
				count += countbuf;

				newfile.push_back(newfilename);
				FILE* fout = fopen(newfilename.c_str(), "w");

				string file1 = _file[index++];
				string file2 = _file[index++];

				FILE* fin1 = fopen(file1.c_str(), "r");
				assert(fin1);
				FILE* fin2 = fopen(file2.c_str(), "r");
				assert(fin2);
				
				int tmp1 = 0;
				int tmp2 = 0;
				fscanf(fin1, "%d", &tmp1);
				fscanf(fin2, "%d", &tmp2);
				while (!feof(fin1)&& !feof(fin2))
				{
					while (!feof(fin1) && !feof(fin2) && tmp1 <= tmp2)
					{
						fprintf(fout, "%d", tmp1);
						fputc(' ', fout);
						fscanf(fin1, "%d", &tmp1);
					}
					while (!feof(fin1) && !feof(fin2) && tmp1 >= tmp2)
					{
						fprintf(fout, "%d", tmp2);
						fputc(' ', fout);
						fscanf(fin2, "%d", &tmp2);
					}
				}
				while (!feof(fin1))
				{
					fprintf(fout, "%d", tmp1);
					fputc(' ', fout);
					fscanf(fin1, "%d", &tmp1);
				}
				while (!feof(fin2))
				{
					fprintf(fout, "%d", tmp2);
					fputc(' ', fout);
					fscanf(fin2, "%d", &tmp2);
				}

				fclose(fout);
				fclose(fin1);
				fclose(fin2);


				remove(file1.c_str());
				remove(file2.c_str());

			
			}
			while (index < _file.size())
			{
				newfile.push_back(_file[index++]);
			}
			_file = newfile;
		}

		int pos = _filename.rfind('.');
		string SortFileName = _filename.substr(0, pos);
		SortFileName +="external_merge_sort .txt";
		rename(_file[0].c_str(), SortFileName.c_str());

	}

protected:
	//��ȡ�ļ��е�һ�С�
	bool ReadLine(FILE*& fconfigout, string & str)
	{
		//�������ļ�����һ���ַ�
		int ch = fgetc(fconfigout);
		if (ch == EOF)
		{
			return false;
		}
		while (ch != EOF&&ch != '\n')
		{
			str += ch;
			ch = fgetc(fconfigout);

		}
		//while��������������str��¼����һ�г���\n������ַ������ⲿ�����\n��ӡ�
		return true;
	}
protected:
	std::vector<string> _file;
	string _filename;
};

void init_data( FILE* fin, size_t line)
{
	assert(fin);
	srand(time(NULL));
	for (size_t i = 0; i < line; i++)
	{
		for (size_t i = 0; i < 99; i++)
		{
			int randnum = rand();
			char buf[33];
			_itoa(randnum, buf, 10);
			fprintf(fin, buf);
			fputc(' ', fin);
		}
		fputc('\n', fin);
	}
}
void CreateRandamNum(const string& a,size_t lines)
{
	FILE* fin = fopen(a.c_str(), "w");
	assert(fin);
	init_data(fin, lines);
	fclose(fin);
}
void test1()
{
	size_t lines = 4;
	string a = "sort.txt";
	CreateRandamNum(a, lines);

	
	ExternalMergeSort b(a);
	b.SplitFile(a, lines);
	b.Mergefile();
}

int main()
{
	test1();
	system("pause");
	return 0;
}