mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
project_dir :=${mkfile_dir}..

build:
	cp ${project_dir}/output/lib/libet.so ${project_dir}/test
	g++ -g -std=c++11 ${project_dir}/test/*.cpp -I${project_dir}/output/include -I${project_dir}/test -L${project_dir}/test -Wl,-rpath=${project_dir}/test -let -o ${project_dir}/test/main -pthread
	
run:
	./main

clean:
	rm -rf main libet.so

.PHONY:
	test clear