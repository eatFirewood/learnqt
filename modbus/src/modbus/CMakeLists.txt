

qt_add_library(modbus STATIC
    modbus.cpp
    modbus.h
    modbus.ui
)

target_link_libraries(modbus PRIVATE Qt6::Widgets)
target_link_libraries(modbus PUBLIC Qt6::SerialBus )
target_include_directories(modbus INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
#/home/wt/Qt/6.6.1/gcc_64/include/QtSerialBus/
)
