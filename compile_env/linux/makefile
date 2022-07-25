mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
project_dir :=${mkfile_dir}../..
output_dir :=${project_dir}/output
lib_dir :=${output_dir}/lib
inc_dir :=${output_dir}/include
src_dir :=${project_dir}/src

tmp_dir = $(shell find $(src_dir) -maxdepth 3 -type d)
src_cpp += $(foreach dir, $(tmp_dir), $(wildcard $(dir)/*.cpp))
src_c += $(foreach dir, $(tmp_dir), $(wildcard $(dir)/*.c))

mode=${mode}
platform=${platform}

include inc.var


build:
	g++ -fpic -shared -std=c++11 ${src_cpp} -o libet.so
	mv -f libet.so ${lib_dir}

	mkdir -p ${inc_dir}/algorithm
	cp  ${ALGO_HEADERS} ${inc_dir}/algorithm

	mkdir -p ${inc_dir}/prefix
	cp ${PREDIX_HEADERS} ${inc_dir}/prefix

	mkdir -p ${inc_dir}/log
	cp  ${LOG_HEADERS} ${inc_dir}/log

	mkdir -p ${inc_dir}/serialize/ini
	cp ${INI_HEADERS} ${inc_dir}/serialize/ini

	mkdir -p ${inc_dir}/singleton
	cp ${SINGLETON} ${inc_dir}/singleton

	mkdir -p ${inc_dir}/utils
	cp ${UTILS_HEADERS} ${inc_dir}/utils

	cp ${API_HEADERS} ${inc_dir}


clean:
	rm -rf ${output_dir}

.PHONY: 
	all clean test


