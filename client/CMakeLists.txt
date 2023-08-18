cmake_minimum_required(VERSION 3.5)
project(engine)

# Set the C++11 standard for the entire project
set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED)
find_package(Protobuf REQUIRED)

set(Protobuf_INCLUDE_DIRS /usr/local/include)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ../protobuf/orders.proto)
 
# Add the executable target 
add_executable(client main.cpp ${PROTO_SRCS} ${PROTO_HDRS})

#target_include_directories(client PRIVATE "${CMAKE_BINARY_DIR}/proto")
target_include_directories(client PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(client ${Protobuf_LIBRARIES})