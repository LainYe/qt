# qt
rubbish
hahaha

readfile.cpp 里面有一行是带文件路径的，要改成自己的路径。  // 改成了saves\\\\路径

存档放在默认路径下的saves文件夹

单人模式文件名 .single

endlessmode类新增成员mode=1,singlemode类新增成员mode=2，twoplayermode类mode设定为3
pause类构造函数新增参数mode，不同模式按p构建pause传入自己的参数。
读写文件时先读写mode值，readfile中按照mode值构建选择三种模式中的一种构建。
