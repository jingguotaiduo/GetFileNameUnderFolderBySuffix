import os

def getsuffixoffile(filename): # 获取文件对应字符串后缀名的函数
    res = ''
    lastdot_index = -1
    for i in range(0, len(filename)):
        if filename[i] == '.':
            lastdot_index = i
    if lastdot_index != -1:
        res += filename[lastdot_index:len(filename)]
    return res

def getFileNameBySuffixname(file_dir, suffix_name): # 获取某文件夹下特定后缀名的所有文件名
    filelist = []
    for root, dirs, files in os.walk(file_dir):
        for file in files:
            if getsuffixoffile(file) == suffix_name:
                filelist.append(file)
    return filelist

def shuchu(filelist):
    for x in filelist:
        print(x)

if __name__ == "__main__":
    file_dir = 'D:\\test'
    suffixname_list = ['.jpg', '.json', '.md', '.pdf', '.xlsx', '.pptx', '.vsdx', '.docx', '.mp4', '.bat', '.txt']
    for i in range(0, len(suffixname_list)):
        suffix_name = suffixname_list[i]
        print('**************'+file_dir + '文件夹下后缀名为'+suffix_name+'的文件*******************')
        result = getFileNameBySuffixname(file_dir, suffix_name)
        shuchu(result)
