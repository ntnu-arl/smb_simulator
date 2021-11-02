cmake_minimum_required(VERSION 2.8.3)
project(smb_opc)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  interactive_marker_twist_server
  smb_description
  smb_teleop_twist_joy
  joy
)
catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)
