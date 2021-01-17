cmake_minimum_required(VERSION 3.16.3)
project(coffee)

option(WARN_ERROR "Turn all warnings into errors" OFF)


if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug")
endif (NOT CMAKE_BUILD_TYPE)

if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL Release)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
endif()

if (WARN_ERROR)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")
endif ()

include_directories(${CMAKE_SOURCE_DIR})

if (${CMAKE_PROJECT_NAME} STREQUAL coffee)
	include(CTest)
endif()

set(coffee_src
    coffee_manager.cpp
    coffee_system.cpp
)

set(coffee_inc
    coffee.h
    coffee_system.h
    coffee_guest.h
    coffee_manager.h
)

add_library(coffee STATIC ${coffee_src})