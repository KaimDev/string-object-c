cmake_minimum_required(VERSION 3.24)

project(StringObject C)

add_executable(program String.c)

target_compile_features(program PUBLIC c_std_17)