if(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")

	set(VISA_PATH "$ENV{VXIPNPPATH64}/Win64")
	set (LIB_PATH ${VISA_PATH}/Lib_x64/msc)
	include_directories(${VISA_PATH}/Include)
	link_directories(${LIB_PATH})
	link_libraries(${LIB_PATH}/visa64.lib)

elseif(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
	message(STATUS "in Linux")
endif()

file(GLOB VIEXCEPTION_SRC_LIST "*.cpp")
file(GLOB HEADER_FILE "*.h")

add_library(libViException STATIC ${VIEXCEPTION_SRC_LIST} ${HEADER_FILE})

install (TARGETS libViException DESTINATION lib)
file (COPY ${HEADER_FILE} DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
