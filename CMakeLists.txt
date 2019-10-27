cmake_minimum_required(VERSION 3.15)
project(orderbookdemo)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)
add_executable(orderbookdemo ${SOURCE_FILES})

include_directories(orderbook)

add_subdirectory(orderbook)
add_subdirectory(orderbooktests)

target_link_libraries(orderbookdemo orderbook)