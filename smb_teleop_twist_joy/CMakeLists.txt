cmake_minimum_required(VERSION 2.8.3)
project(smb_teleop_twist_joy)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  sensor_msgs
  roscpp
  joy
)

catkin_package(
  CATKIN_DEPENDS geometry_msgs sensor_msgs roscpp joy
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(smb_teleop_twist_joy_node src/smb_teleop_twist_joy_node.cpp)
add_dependencies(smb_teleop_twist_joy_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(smb_teleop_twist_joy_node ${catkin_LIBRARIES})

add_executable(joy_republisher src/joy_republisher.cpp)
add_dependencies(joy_republisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(joy_republisher ${catkin_LIBRARIES})