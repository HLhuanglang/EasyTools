#!/bin/bash
function usage {
    echo -e "use this command line to compile:\033[31m ./build.sh [release|debug] [x86|x64] \033[0m"
}

if [ $# -lt 2 ];then
    usage
    exit -1
fi

project_dir=$(cd `dirname $0`;pwd)
output_dir=${project_dir}/../../output
lib_dir=${output_dir}/lib
inc_dir=${output_dir}/include

if [ ! -d ${output_dir} ];then
    mkdir -p ${output_dir}
    mkdir -p ${lib_dir}
    mkdir -p ${inc_dir}
fi

#编译
make -f ${project_dir}/makefile mode=$1 platform=$2