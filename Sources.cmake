# Libraries:

link_libraries (gcc)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)
add_definitions (-DBMPTK_TARGET_arduino_due
                 -DBMPTK_TARGET=arduino_due
                 -DBMPTK_BAUDRATE=19200)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    src/wrap-hwlib.cpp
    src/libc-stub.cpp
    src/main.cpp
)
