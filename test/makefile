mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
project_dir :=${mkfile_dir}..
output_dir :=${project_dir}/output
lib_dir :=${output_dir}/lib
inc_dir :=${output_dir}/include

build:
	g++ -g -std=c++11 ${mkfile_dir}*.cpp -I${inc_dir} -I${mkfile_dir} -L${lib_dir} -let -o main -pthread
	
run:
	./main

clean:
	rm -rf main

.PHONY:
	test clear