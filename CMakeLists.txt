cmake_minimum_required( VERSION 2.8 )
project( videoCapture )

set(CMAKE_BUILD_TYPE "Release")
set( CMAKE_CXX_FLAGS "-std=c++11 -march=native -O3 -fopenmp" )

############### dependencies ######################
# OpenCV
# set(CMAKE_PREFIX_PATH "/usr/local/opencv-2.4.8")
# set(OpenCV_DIR "/usr/local/opencv-2.4.8")
find_package( OpenCV 2.4.8 REQUIRED )
# find_package(OpenCV 2.4.13 QUIET)
include_directories( ${OpenCV_INCLUDE_DIRS} )
# include_directories( "/usr/local/opencv-2.4.8/include" )

add_executable( videoCapture videoCapture.cpp)

add_executable( videoReader videoReader.cpp)


target_link_libraries( videoCapture ${OpenCV_LIBS})

target_link_libraries( videoReader ${OpenCV_LIBS})