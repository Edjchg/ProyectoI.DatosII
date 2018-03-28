cmake_minimum_required(VERSION 3.9)

project(Proyecto1)

set(CMAKE_CXX_STANDARD 11)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp parser.cpp parser.h ListaSimple.h NodoSimple.h SingletonMemory.cpp SingletonMemory.h)



find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})



add_executable(Proyecto1 ${SOURCE_FILES})

target_link_libraries(Proyecto1 ${GTK3_LIBRARIES})