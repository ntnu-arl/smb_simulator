cmake_minimum_required(VERSION 2.8.3)
project(smb_gazebo)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  controller_manager
  gazebo_ros
  xacro
  nav_msgs
  geometry_msgs
  sensor_msgs
  topic_tools
  twist_mux
  interactive_marker_twist_server
)

catkin_package()
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(message_to_tf src/message_to_tf.cpp)

target_link_libraries(message_to_tf ${catkin_LIBRARIES})
