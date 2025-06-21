cmake_minimum_required(VERSION 3.15)
project(video_stream LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_PREFIX_PATH "/opt/homebrew/bin/ffmpeg")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/generators")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Add include/ as header search path
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find packages
find_package(OpenCV REQUIRED CONFIG)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Add subdirectory for sources
add_subdirectory(src)