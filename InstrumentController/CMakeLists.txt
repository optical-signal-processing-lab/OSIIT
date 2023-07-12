# CMakeList.txt: InstrumentController 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("InstrumentController")
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/build")

add_subdirectory("modules")

# 将源代码添加到此项目的可执行文件。
# add_executable (InstrumentController "InstrumentController.cpp" "InstrumentController.h")
