cmake_minimum_required(VERSION 3.5)
project(rto_msgs)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(builtin_interfaces REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/AnalogReadings.msg"
  "msg/DigitalReadings.msg"
  "msg/GrapplerReadings.msg"
  "msg/MotorReadings.msg"
  "msg/PowerReadings.msg"
  "msg/SetGrapplerAxes.msg"
  "msg/BHAReadings.msg"
  "msg/EncoderReadings.msg"
  "msg/GripperState.msg"
  "msg/NorthStarReadings.msg"
  "msg/SetBHAPressures.msg"
  "msg/SetGrapplerAxis.msg"
  "srv/ResetOdometry.srv"
  "srv/SetEncoderPosition.srv"
  "srv/SetGripperState.srv"

  DEPENDENCIES builtin_interfaces
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
