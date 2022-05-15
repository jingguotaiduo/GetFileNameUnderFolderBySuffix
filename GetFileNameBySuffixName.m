folder = 'D:\test';
suffixnamelist = {'.jpg', '.json', '.md', '.pdf', '.xlsx', '.pptx', '.vsdx', '.docx', '.mp4', '.bat', '.txt'};
filelist = dir(folder);
for i=1:1:length(suffixnamelist)
    suffixname = suffixnamelist{1,i};
    fprintf(['**************',folder,'文件夹下后缀名为',suffixname,'的文件**************','\n']);
    for j=1:1:length(filelist)
      if filelist(j).isdir == 0 && isSuffix(filelist(j).name,suffixname)
          fprintf([filelist(j).name,'\n'])
      end
    end
end

function [flag] = isSuffix(filename, suffix)%判断字符串以某个字符串结尾
    flag = 0;
    len1 = strlength(filename);
    len2 = strlength(suffix);
    suf_filename = filename(len1-len2+1:len1);
    if strcmpi(suf_filename,suffix)
        flag = 1;
    end
end
