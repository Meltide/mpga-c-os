<div align="center">

<img src="res/logo.png" height="114px">

# MPGA C-OS
![GitHub repo size](https://img.shields.io/github/repo-size/Meltide/mpga-c-os)
![GitHub Repo stars](https://img.shields.io/github/stars/Meltide/mpga-c-os?style=flat)
![GitHub branch status](https://img.shields.io/github/checks-status/Meltide/mpga-c-os/main)
![GitHub commit activity](https://img.shields.io/github/commit-activity/t/Meltide/mpga-c-os)
![GitHub last commit](https://img.shields.io/github/last-commit/Meltide/mpga-c-os)
![GitHub Created At](https://img.shields.io/github/created-at/Meltide/mpga-c-os) 

**一个基于C++的伪操作系统**

</div>

## 使用方法

### 方法1: 自行编译

#### 对于 Linux 用户
0. 安装以下软件包: `gcc-c++`, `cmake`, `make`
1. 转到项目所在目录
2. 输入以下命令开始构建
```bash
cmake . && make
```
3. 输入 `./c-os` 来启动

#### 对于 Windows 用户
0. 安装以下软件包: `cmake`, `ninja`
1. 转到项目所在目录
2. 输入以下命令开始构建
```powershell
cmake -G Ninja .
ninja
```

### 方法2: 使用已编译文件

1. 从[Releases](https://github.com/Meltide/mpga-c-os/release)下载已编译版本
2. 转到已编译文件所在的目录
3. Linux 输入 `./c-os` 来启动，Windows 运行 `c-os.exe` 来启动

> [!WARNING]
> 必须在 `main.cpp` 所在的目录下运行 `c-os`

用户名：**root**
<br>
初始密码：**114514**

输入 `help` 获取帮助

----
注意：  
- 建议使用 **Linux环境** 运行本程序
- 请确保 **您的编译器支持 C++17 标准** ！
