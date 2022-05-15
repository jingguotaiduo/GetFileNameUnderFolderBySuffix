using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GetFileNameWithSpecificSuffix
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                string path = "", suffix_name = "";//所要查找的文件夹、要搜索的文件后缀名
                Console.WriteLine("************获取文件夹下特定类型文件的文件名*************(Enter键退出）！");
                Console.Write("请输入要搜索的文件目录（如 D:\\test)：");
                path = Console.ReadLine();
                Console.Write("请输入要搜索的文件后缀名（如*.txt)：");
                suffix_name = Console.ReadLine();
                if (path != "" && Directory.Exists(path))//文件目录不为空且文件夹存在
                {
                    DirectoryInfo folder = new DirectoryInfo(path);
                    if (suffix_name == "")
                    {
                        foreach (FileInfo file in folder.GetFiles())
                        {
                            Console.WriteLine(file.Name);
                        }
                    }
                    else
                    {
                        foreach (FileInfo file in folder.GetFiles(suffix_name))
                        {
                            Console.WriteLine(file.Name);
                        }
                    }
                }
                else
                {
                    Console.WriteLine("文件目录不存在，退出！");
                    break;//退出程序
                }
            }
        }
    }
}
