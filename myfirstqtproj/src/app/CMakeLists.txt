qt_add_executable(count
    main.cpp)
target_link_libraries(count PRIVATE Qt6::SerialPort Qt6::Widgets modbus)
