# qt
rubbish
hahaha

存档放在默认路径下的saves文件夹

单人模式(singlemode)文件名 .single

无尽模式(endlessmode)文件名 .endless

双人模式(pairmode)文件名 .pair

endlessmode类新增成员const int mode=1,singlemode类新增成员const int mode=2，pairmode类mode设定为(const int)3

pause类构造函数新增参数mode，不同模式构建pause时传入自己的参数。读写文件时先读写mode值

readfile类构造函数新增参数mode，不同模式构建readfile时传入自己的mode参数。开始界面构建readfile时，mode为缺省值0，读写文件时先读写mode值

board新增reset_size函数，endlessmode,singlemode类的draw函数下加入调整size的模块

<img width="475" alt="247744916410681543" src="https://user-images.githubusercontent.com/103051656/176330321-29775bc2-f53f-4b7d-8164-5dd343d407b2.png">

新增单人模式出口-2
