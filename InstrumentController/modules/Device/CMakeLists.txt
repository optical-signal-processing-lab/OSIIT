﻿file(GLOB DEVICE_SRC_LIST "*.cpp")
file(GLOB HEADER_FILE "*.h")

add_library(libDevice STATIC ${DEVICE_SRC_LIST} ${HEADER_FILE})

install (TARGETS libDevice DESTINATION lib)
file (COPY ${HEADER_FILE} DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
