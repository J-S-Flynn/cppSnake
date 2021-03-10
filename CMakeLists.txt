cmake_minimum_required(VERSION 3.5)

project(snake)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(intro snake.cpp)

include_directories(/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/curses.h/include)

target_link_libraries(intro ncurses)

target_compile_definitions(intro PRIVATE)

