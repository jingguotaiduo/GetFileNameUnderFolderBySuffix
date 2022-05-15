#include <stdio.h>
#include<io.h>
#define MAX_FILENAME_LENGTH 500

void getFiles(char *path, char *suffixname)
{
	long   hFile = 0;
	struct _finddata_t singlefileinfo;
	strcat(path, "\\*");
	if ((hFile = _findfirst(path, &singlefileinfo)) != -1)
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
				int length = strlen(singlefileinfo.name);
				char *filename = singlefileinfo.name;
				int pos_lastdot = -1;
				for(int j=length-1;j>0;j--)
                    if(filename[j] == '.')
                    {
                        pos_lastdot = j;
                        break;
                    }
                if (pos_lastdot != -1)
                {
                    int actualsuffix_len = length - pos_lastdot;
                    char actualsuffix[actualsuffix_len];
                    if (actualsuffix_len == strlen(suffixname))
                    {
                        memcpy(actualsuffix,filename + pos_lastdot,actualsuffix_len);
                        int flag = 1;
                        for(int k=0;k<actualsuffix_len;k++)
                            if(actualsuffix[k] != suffixname[k])
                            {
                                flag = -1;break;
                            }
                        if(flag == 1)
                            printf("%s\n",filename);
                    }
                }
			}
		} while (_findnext(hFile, &singlefileinfo) == 0);
		_findclose(hFile);
	}
}

int main()
{
    while(1)
    {
        printf("*************查找指定文件夹下具有特定扩展名的所有文件***************\n");
        printf("请输入要搜索的文件夹（如D:\\test）:");
        char path[MAX_FILENAME_LENGTH];
//        scanf("%s",path);
        char *str1 = gets(path);
        char suffixname[6];
        printf("请输入文件后缀名（如.jpg、.json、.md、.pdf、.xlsx、.pptx、.vsdx、.docx、.mp4、.bat、.txt）:");
//        scanf("%s",suffixname);
        char *str2 = gets(suffixname);
        if(strlen(str1) < 4 || strlen(str2) < 3)
            break;
        getFiles(path,suffixname);
    }
    return 0;
}
