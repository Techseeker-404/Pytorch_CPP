cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(sample)
find_package(Torch REQUIRED)
find_package(OpenCV 4.1.0 REQUIRED) # OpenCV 4.1.0 REQUIRED
add_executable(sample sample.cpp)
target_link_libraries(sample "${TORCH_LIBRARIES}")
target_link_libraries(sample "${OpenCV_LIBS}")
set_property(TARGET sample PROPERTY CXX_STANDARD 14)
