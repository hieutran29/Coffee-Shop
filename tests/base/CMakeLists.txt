add_library(ut_base STATIC gb.cpp   )

add_executable(print_all_ut print_all.cpp)

target_link_libraries(print_all_ut ut_base coffee)