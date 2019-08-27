cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set (CMAKE_AUTOMOC ON)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Core REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gazebo REQUIRED)

include_directories(
  SYSTEM 
  ${GAZEBO_INCLUDE_DIRS} 
  ${Qt5Core_INCLUDE_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}/msgs
  )
link_directories(
  ${GAZEBO_LIBRARY_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}/msgs
  )
add_subdirectory(msgs)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

# add_library(gui_example_spawn_widget SHARED ${headers_MOC}
#   GUIExampleSpawnWidget.cc)
# target_link_libraries(gui_example_spawn_widget ${GAZEBO_LIBRARIES}
#     ${Qt5Core_LIBRARIES}
#     ${Qt5Widgets_LIBRARIES}
#     ${PROTOBUF_LIBRARIES})
# install(TARGETS gui_example_spawn_widget DESTINATION ${GAZEBO_PLUGIN_PATH})

add_library(gui_resetworld SHARED ${headers_MOC}
  GUI_ResetWorld.cc)
target_link_libraries(gui_resetworld 
  reset_world_request_msgs
  ${GAZEBO_LIBRARIES}
  ${Qt5Core_LIBRARIES}
  ${Qt5Widgets_LIBRARIES}
  ${PROTOBUF_LIBRARIES}
  )
add_dependencies(gui_resetworld reset_world_request_msgs)
install(TARGETS gui_resetworld DESTINATION ${GAZEBO_PLUGIN_PATH})