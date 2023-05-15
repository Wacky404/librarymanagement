cmake_minimum_required(VERSION 3.25)
project(CYOAclassheaders)

set(CMAKE_CXX_STANDARD 23)

add_executable(CYOAclassheaders Library.cpp Library.h Wishlist.h Release.h Wishlist.cpp Release.cpp main.cpp)
