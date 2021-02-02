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
    coffee_product.cpp
    coffee_guest.cpp
)

set(coffee_inc
    coffee.h
    coffee_system.h
    coffee_guest.h
    coffee_manager.h
    coffee_product.h
    coffee_type.h
    coffee_birth.h
)

add_library(coffee STATIC ${coffee_src})

if(${BUILD_TESTING})
    add_subdirectory(tests)
    add_test(NAME CoffeeNewAccountManager COMMAND new_account_manager_ut)
    add_test(NAME CoffeeSignInManager COMMAND sign_in_manager_ut)
    add_test(NAME AddDrink COMMAND add_drink_ut)
    add_test(NAME AddFood COMMAND add_food_ut)
    add_test(NAME CoffeeNewAccountGuest COMMAND new_account_guest_ut)
    add_test(NAME CoffeeSignInGuest COMMAND sign_in_guest_ut)
endif()

