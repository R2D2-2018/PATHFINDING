# Libraries:

link_libraries (gcc)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    src/libc-stub.cpp
    src/a_star.cpp
    src/best_first_search.cpp
    src/graph.cpp
    src/library_interface.cpp
    src/node.cpp
    src/serial_interface.cpp
)
