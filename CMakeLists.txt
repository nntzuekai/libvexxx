cmake_minimum_required(VERSION 3.13)

project(vexxx_so)
project(vexxx_a)

set(CMAKE_CXX_STANDARD 17)

include_directories(/home/jerry/.virtualenvs/angr/lib/python3.6/site-packages/pyvex/include)

aux_source_directory(./ libvexxx_src)

add_library(vexxx_so SHARED ${libvexxx_src})
add_library(vexxx_a STATIC ${libvexxx_src})

SET_TARGET_PROPERTIES(vexxx_so PROPERTIES OUTPUT_NAME "vexxx")
SET_TARGET_PROPERTIES(vexxx_a PROPERTIES OUTPUT_NAME "vexxx")

SET_TARGET_PROPERTIES (vexxx_so PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES (vexxx_a PROPERTIES CLEAN_DIRECT_OUTPUT 1)

