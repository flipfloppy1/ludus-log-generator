
cmake_minimum_required(VERSION 3.11)
project("LLG")

add_library(LLG "Log.h")

set_property(TARGET LLG PROPERTY LINKER_LANGUAGE CXX)
