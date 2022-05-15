import java.io.File

object TestGetFileNameBySuffix
{
  def main(args: Array[String]): Unit =
  {
    val dir : String = "D:\\test";
    var suffixname_list = Array(".jpg", ".json", ".md", ".pdf", ".xlsx", ".pptx", ".vsdx", ".docx", ".mp4", ".bat", ".txt");
    val file: File = new File(dir);
    val files = file.listFiles(_.isFile());//仅搜索文件，不搜索文件夹
    var i = -1;
    for(i <- 0 to (suffixname_list.length-1) )
    {
      println("************"+dir + "文件夹下后缀名为" + suffixname_list(i) + "的文件************");
      var suffixname : String= suffixname_list(i);
      var j = -1;
      for(j <- 0 to (files.length-1) )
      {
        var filename:String = files(j).getName();
        if (filename.endsWith(suffixname))
        {
          println(filename);
        }
      }
    }
  }
}
