file(GLOB SRC_LIST "*.cpp")
file(GLOB HEADER_FILE "*.h")

set(VISA_PATH "$ENV{VXIPNPPATH64}/Win64")
set (LIB_PATH ${VISA_PATH}/Lib_x64/msc)
include_directories(${VISA_PATH}/Include)
link_directories(${LIB_PATH})
link_libraries(${LIB_PATH}/visa64.lib)
include_directories(${CMAKE_SOURCE_DIR}/build/Include)

add_executable(example1 ${SRC_LIST} ${HEADER_FILE})
target_link_libraries(example1 libDevice libViException)

install (TARGETS example1 DESTINATION example)
