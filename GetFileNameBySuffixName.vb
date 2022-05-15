Module Module1
    Sub Main()
        Dim folder As String = "D:\test"
        Dim suffixnamelist As String() = New String() {".jpg", ".json", ".md", ".pdf", ".xlsx", ".pptx", ".vsdx", ".docx", ".mp4", ".bat", ".txt"}
        Dim fso, fo, fis, fi
        fso = CreateObject("Scripting.FileSystemObject")
        fo = fso.GetFolder(folder) '输入指定目录
        fis = fo.Files
        For i = 0 To suffixnamelist.Length - 1
            Dim suffixname As String = suffixnamelist(i) '从后缀名列表中获取后缀名
            Console.WriteLine("**************" + folder + "文件夹下后缀名为" + suffixname + "的文件**************")
            For Each fi In fis
                Dim filename As String = fi.Name
                If filename.EndsWith(suffixname) Then
                    Console.WriteLine(filename)
                End If
            Next
        Next
    End Sub
End Module
