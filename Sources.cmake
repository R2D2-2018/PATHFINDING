# Libraries:

link_libraries (gcc)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
	src/main.cpp
	src/libc-stub.cpp
    src/best_first_search.cpp
    src/breadth_first_search.cpp
    src/graph.cpp
    src/node.cpp
    src/path.cpp
    src/pathfinding.cpp
	src/wrap-hwlib.cpp
	src/vector.cpp
)