project(pcd_ply_converter)

set(EXECUTABLE_OUTPUT_PATH ../bin)

cmake_minimum_required (VERSION 3.0.2 FATAL_ERROR)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
set (CMAKE_BUILD_TYPE Release)

find_package(PCL 1.6 REQUIRED)
find_package(Qt5Widgets)

include_directories (${PCL_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})
link_directories    (${PCL_LIBRARY_DIRS})
add_definitions     (${PCL_DEFINITIONS} ${Qt5Widgets_DEFINITIONS})

qt5_generate_moc(main.cpp main.moc)

add_executable (pcd_ply_converter src/main.cpp)
target_link_libraries (pcd_ply_converter ${PCL_LIBRARIES} Qt5::Widgets)
