qt_add_library(modbus STATIC
                      modbus.cpp
                      modbus.h
                      modbus.ui)
target_link_libraries(modbus PRIVATE Qt6::SerialPort Qt6::Widgets)
target_include_directories(modbus INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
