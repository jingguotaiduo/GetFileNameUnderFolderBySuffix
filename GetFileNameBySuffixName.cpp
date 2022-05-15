#include <iostream>
#include <io.h>
using namespace std;

#define MAX_FILENAME_LENGTH 500
#define MAX_SUFFIX_LENGTH 6

void getFiles(char *path, char *suffixname)
{
	__int64  hFile = 0;
	struct _finddata_t singlefileinfo;
	const char* str_add = "\\*";
	size_t len3 = strlen(str_add),len_path = strlen(path);
	for (size_t i = 0; i <len3; i++)
	{
		path[i + len_path] = str_add[i];
	}
	if ((hFile = _findfirst(path, &singlefileinfo)) != -1)	//string p; p.assign(path).append("\\*").c_str() 替代此行的path
	{
		do
		{
			if ((singlefileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(singlefileinfo.name, ".") != 0 && strcmp(singlefileinfo.name, "..") != 0)
					continue;
			}
			else
			{
				size_t length = strlen(singlefileinfo.name);
				char *filename = singlefileinfo.name;
				size_t pos_lastdot = -1;
				for (size_t j = length - 1; j>0; j--)
					if (filename[j] == '.')
					{
						pos_lastdot = j;
						break;
					}
				if (pos_lastdot != -1)
				{
					size_t actualsuffix_len = length - pos_lastdot;
					if (actualsuffix_len == strlen(suffixname))
					{
						char actualsuffix[MAX_SUFFIX_LENGTH];
						memcpy(actualsuffix, filename + pos_lastdot, actualsuffix_len);
						int flag = 1;
						for (int k = 0; k<actualsuffix_len; k++)
							if (actualsuffix[k] != suffixname[k])
							{
								flag = -1; break;
							}
						if (flag == 1)
							cout<< filename<< endl;
					}
				}
			}
		} while (_findnext(hFile, &singlefileinfo) == 0);
		_findclose(hFile);
	}
}

int main(int argc, char **argv)
{
	while (true)
	{
		char path[MAX_FILENAME_LENGTH], suffixname[MAX_SUFFIX_LENGTH];
		printf("*************查找指定文件夹下具有特定扩展名的所有文件***************\n");
		cout << "请输入要搜索的文件夹（如D:\\test）:";
		cin >> path;
		cout << "请输入文件后缀名（如.jpg、.json、.md、.pdf、.xlsx、.pptx、.vsdx、.docx、.mp4、.bat、.txt）:";
		cin >> suffixname;
		if (strlen(path) < 4 || strlen(suffixname) < 3)
			break;
		getFiles(path, suffixname);
	}
	return 0;
}
