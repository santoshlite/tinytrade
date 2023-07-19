cmake_minimum_required(VERSION 3.5)

project(tinytrade)

# Set the C++11 standard for the entire project
set(CMAKE_CXX_STANDARD 11)

# Add the executable target (your main.cpp file)
add_executable(main main.cpp)

# Find and link the Boost library
find_package(Boost REQUIRED)
target_link_libraries(main PRIVATE Boost::boost)
