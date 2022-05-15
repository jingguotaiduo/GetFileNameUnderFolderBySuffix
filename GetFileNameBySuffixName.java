package com;

import java.io.File;

public class GetFileNameBySuffix 
{
	public static void printFileNameBySuffix(String path,String suffixname)
	{
		System.out.println(path+"文件夹下后缀名为"+suffixname+"的文件：");
		File file = new File(path);		//获取其file对象
		File[] fs = file.listFiles();
		for(File f:fs)
		{
			String filename = f.getName();
			if(f.isFile() && filename.endsWith(suffixname))
			    System.out.println(filename);
		}
	}
	
	public static void main(String[] args)
	{
		String folder = "D:\\test";
		String[] suffixname_list = {".jpg", ".json", ".md", ".pdf", ".xlsx", ".pptx", ".vsdx", ".docx", ".mp4", ".bat", ".txt"};
		for(int i=0;i<suffixname_list.length;i++)
		{
			printFileNameBySuffix(folder, suffixname_list[i]);
		}
	}
}
