cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
find_package(Protobuf REQUIRED)

set(PROTOBUF_IMPORT_DIRS)
foreach(ITR ${GAZEBO_INCLUDE_DIRS})
  if(ITR MATCHES ".*gazebo-[0-9.]+$")
    set(PROTOBUF_IMPORT_DIRS "${ITR}/gazebo/msgs/proto")
  endif()
endforeach()

set (msgs
  reset_world_request.proto
)
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${msgs})
add_library(reset_world_request_msgs SHARED ${PROTO_SRCS})
target_link_libraries(reset_world_request_msgs ${PROTOBUF_LIBRARY})
#install(TARGETS reset_world_request_msgs DESTINATION ${GAZEBO_PLUGIN_PATH})