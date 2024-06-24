
## 安装 ROS2
安装教程：https://ms-iot.github.io/ROSOnWindows/index.html
```powershell
# install choco
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

# 安装 ros-foxy
mkdir c:\opt\chocolatey
Set-Variable PYTHONNOUSERSITE=1
Set-Variable ChocolateyInstall=c:\opt\chocolatey
choco source add -n=ros-win -s="https://aka.ms/ros/public" --priority=1
choco upgrade ros-foxy-desktop -y --execution-timeout=0

# 测试
call C:\opt\ros\foxy\x64\local_setup.bat # 一个窗口中运行
ros2 run turtlesim turtlesim_node

call C:\opt\ros\foxy\x64\local_setup.bat # 另一个窗口中运行
ros2 run turtlesim turtle_teleop_key
```

## 创建 c++ package
```shell
    # c++
    ros2 pkg create publish --build-type ament_cmake --dependencies rclcpp std_msgs

    # python
    ros2 pkg create subscribe --build-type ament_python --node-name subscriber
```

```shell
    # 初始化环境
    cd workspace/src
    call install/local_setup.bat

    # 编译包
    # colcon build --merge-install
    colcon build --packages-select publish
    ros2 run publish publisher
    ros2 run subscribe subscriber
```

## 创建 py package
```shell
    # python
    ros2 pkg create subscribe --build-type ament_python --node-name subscriber
    cd workspace/src
    colcon build
```

```shell
    # 初始化环境
    call install/local_setup.bat

    # 编译包
    ros2 run subscribe subscriber
```
