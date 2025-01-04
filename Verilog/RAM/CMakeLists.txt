cmake_minimum_required(VERSION 3.10)

project(ram)

find_package(verilator HINTS $ENV{VERILATOR_ROOT})
add_executable(Vdmux4way testbench.cpp)
verilate(Vdmux4way
	SOURCES ram.v
	TOP_MODULE dmux4way)
