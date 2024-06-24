
## Windows 安装 ROS2
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

## Ubuntu 安装 ROS2
```shell
sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8
```

检查Universe源
```shell
apt-cache policy | grep universe
# 如果没有执行以下命令
sudo apt install software-properties-common
sudo add-apt-repository universe
```

添加证书及仓库
```shell
sudo apt update && sudo apt install curl gnupg lsb-release
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(source /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```

安装及环境变量
```shell
sudo apt update && sudo apt upgrade
sudo apt install ros-humble-desktop

source /opt/ros/humble/setup.bash
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc 
```

测试
```shell
export ROS_DOMAIN_ID=42 # 跨设备通信需要设置这个变量
ros2 run demo_nodes_cpp talker

ros2 run demo_nodes_py listener
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
