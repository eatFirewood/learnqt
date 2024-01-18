cmake_minimum_required(VERSION 3.5)

project(modbus VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH /home/wt/Qt/6.6.1/gcc_64/lib/cmake/Qt6/)


find_package(Qt6 REQUIRED COMPONENTS Widgets SerialPort SerialBus)
qt_standard_project_setup()

add_subdirectory(src/app)
add_subdirectory(src/modbus)


