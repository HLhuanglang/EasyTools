# EasyTools

## 简介

**easytools**是一个c/c++语言实现的代码工具包，包含日常开发中的一些常用功能，可以集成任何你想集成的东西。

## 平台

| 平台    | 支持情况                      |
| ------- | ----------------------------- |
| Windows | :white_check_mark:            |
| Linux   | :white_check_mark:            |
| MacOS   | :negative_squared_cross_mark: |

## 项目结构

```
EasyTools
├─.vs								#通过vs2022打开工程后自动生成的
├─.vscode							#vscode配置文件
├─bin								#vs2022编译的中间文件以及测试程序运行的根目录
│  └─obj
│      ├─easy_tools.tlog
│      └─easy_tools_utest.tlog
├─compile_env						#编译环境：windows使用vs2022,linux使用vscode远程连接
│  ├─linux
│  └─windows
│      ├─easy_tools
│      └─easy_tools_utest
├─docs								#模块说明文档(原理,模块使用)
├─output							#EasyTools编译生成后的头文件和动态库
│  ├─include
│  │  ├─algorithm
│  │  ├─log
│  │  ├─prefix
│  │  ├─serialize
│  │  │  └─ini
│  │  ├─singleton
│  │  └─utils
│  └─lib
│      ├─x64
│      └─x86
├─src								#源码
│  ├─algorithm
│  ├─crypto
│  ├─log
│  ├─prefix
│  ├─serialize
│  │  └─ini
│  ├─singleton
│  └─utils
└─test								#测试程序源码
    └─test_data
```

## 编译运行

首先下载代码：git clone https://github.com/HLhuanglang/EasyTools.git

### windows

windows下使用vs2022进行开发，下载项目后进入compile_env/windows，打开msvc.sln即可运行调试。想调试什么功能模块直接在easy_tool_utest中编写测试代码，然后调试就行。

![image-20220726005818732](https://hl1998-1255562705.cos.ap-shanghai.myqcloud.com/Img/image-20220726005818732.png)

### linux

linux下开发的方式有两种：

#### 命令行

- 下载代码后，进入compile_env/linux，执行build.sh脚本，在项目根目录下会生成一个output，里面有头文件和动态库
- 进入test目录，执行make build可以编译测试程序
- 使用gdb进行调试

#### 使用vscode远程连接linux

一台云服务或|wls2|本地虚拟机，vscode安装远程插件。使用vscode开发主要配置文件：

- **c_cpp_properties.json**：配置c/c++的语言标准，linux上面头文件路径，编译器路径等等。

  - 安装g++、g++multilib、gcc、gcc-multilib、gdb

  - 执行`echo 'main(){}'|gcc -E -v -`查看当前一些标准库头文件在哪儿，然后填入"includePath"

  - ubuntu下使用whereis g++就可以找到g++安装的位置了

  - ```JSON
    {
        "configurations": [
            {
                "name": "Linux",
                "includePath": [
                    "${workspaceFolder}/**",
                    "/usr/lib/gcc/x86_64-linux-gnu/9/include",
                    "/usr/local/include",
                    "/usr/include/x86_64-linux-gnu",
                    "/usr/include"
                ],
                "defines": [],
                "compilerPath": "/usr/bin/g++",
                "cStandard": "c11",
                "cppStandard": "c++11",
                "intelliSenseMode": "linux-gcc-x64",
                "configurationProvider": "ms-vscode.makefile-tools",
                "mergeConfigurations": true
            }
        ],
        "version": 4
    }
    ```

- **task.json**：

  - 编写makefile时需要注意使用绝对地址，使用相对地址会出问题

  - ```json
    {
        "tasks": [
            {
                "label": "compile_libet.so",
                "type": "shell",
                "command": "${workspaceFolder}/compile_env/linux/build.sh debug x64",
                "group": {
                    "kind": "build",
                    "isDefault": true
                },
            },
            {
                "label": "compile_testdemo",
                "type": "shell",
                "command": "make -f ${workspaceFolder}/test/makefile build",
                "group": "test"
            }
        ],
        "version": "2.0.0"
    }
    ```

- **lanuch.json**：调试文件

  - `program`，这个路径是编译出来测试程序的路径

  - EasyTools编译出来的库是libet.so，目标vscode的preLaunchTask功能并不支持执行多个任务，所以在使用vscode调试前，请前手动编译出libet.so。需要注意一点，测试程序默认是编译成64位的，所以libet.so也需要编译成64位。

  - ```json
    {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "gdb",
                "type": "cppdbg",
                "request": "launch",
                "program": "${workspaceFolder}/test/main",
                "args": [],
                "stopAtEntry": false,
                "cwd": "${fileDirname}",
                "environment": [],
                "externalConsole": false,
                "MIMode": "gdb",
                "setupCommands": [
                    {
                        "description": "为 gdb 启用整齐打印",
                        "text": "-enable-pretty-printing",
                        "ignoreFailures": true
                    },
                    {
                        "description": "将反汇编风格设置为 Intel",
                        "text": "-gdb-set disassembly-flavor intel",
                        "ignoreFailures": true
                    }
                ],
                "preLaunchTask": "compile_testdemo"
            }
        ]
    }
    ```

![image-20220726190324275](https://hl1998-1255562705.cos.ap-shanghai.myqcloud.com/Img/image-20220726190324275.png)
