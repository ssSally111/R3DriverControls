# R3DriverControls

> 测试环境：vm win10 ltsc

1. 加载运行驱动：

```shell
C:\Users\ab\Desktop>DriverLoading.exe 1 C:\Users\ab\Desktop\DriverTest.sys DriverTest1
[DriverLoading] Successful

C:\Users\ab\Desktop>DriverLoading.exe 2 DriverTest1
[DriverActivate] Successful
```

2.读取

```shell
C:\Users\ab\Desktop>R3DriverControls.exe
read length:10
c c c c c c c c c c
```

