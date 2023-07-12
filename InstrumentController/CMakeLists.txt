# CMakeList.txt: InstrumentController 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("InstrumentController")
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/build")
message(STATUS "install dir = ${CMAKE_INSTALL_PREFIX}")
add_subdirectory("modules")

message(status "\n ----enable example------\n")
option(ENABLE_EXAMPLE "构建示例" ON)

if(DEFINED ENABLE_EXAMPLE)
message(STATUS "ENABLE_EXAMPLE defined")
else()
message(STATUS "ENABLE_EXAMPLE undefined")
endif()

if (ENABLE_EXAMPLE)
	message(STATUS "build example ON")
	add_subdirectory("example")
	add_dependencies(example1 libDevice libViException)
else()
	message(STATUS "build example OFF")
endif()