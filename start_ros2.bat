@echo off

:: 设置路径变量
set ROS_SETUP_PATH=C:\opt\ros\foxy\x64\local_setup.bat
set VS_SETUP_PATH="E:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools\VsDevCmd.bat"
set LOCAL_SETUP_PATH=%cd%\install\local_setup.bat

:: 调用路径变量
call %ROS_SETUP_PATH%
call %VS_SETUP_PATH%
call %LOCAL_SETUP_PATH%

:: 保持命令提示符窗口打开
cmd /k
