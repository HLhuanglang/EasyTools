mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
project_dir :=${mkfile_dir}..

build:
#编译时指定了动态库路径但是程序实际运行时仍然找不到?
#linux下加载动态库的路径：
#	1. 编译目标代码时指定的动态库搜索路径；
#	2. 环境变量 LD_LIBRARY_PATH 指定的动态库搜索路径；
#	3. 配置文件 /etc/ld.so.conf.d/ 中指定的动态库搜索路径；
#	4. 默认的动态库搜索路径 /lib ；
#	5. 默认的动态库搜索路径 /usr/lib
#
#为了避免影响其他程序,所以将libet.so拷贝到test目录,然后再通过-Wl,-rpath来指定程序运行时加载动态库路径
	cp ${project_dir}/output/lib/libet.so ${project_dir}/test
	g++ -g -std=c++11 ${project_dir}/test/*.cpp -I${project_dir}/output/include -I${project_dir}/test -L${project_dir}/test -Wl,-rpath=${project_dir}/test -let -o ${project_dir}/test/main -pthread
	
run:
	./main

clean:
	rm -rf main libet.so

.PHONY:
	test clear