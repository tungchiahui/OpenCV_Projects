cmake_minimum_required(VERSION 3.8)
project(demo3_1_color_space)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)

add_executable(SplitAndMerge src/SplitAndMerge.cpp)
add_executable(CvColor src/CvColor.cpp)

target_include_directories(CvColor PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_compile_features(CvColor PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

ament_target_dependencies(
  CvColor
  "rclcpp"
  "OpenCV"
  "sensor_msgs"
  "cv_bridge"
  "image_transport"
)

ament_target_dependencies(
  SplitAndMerge
  "rclcpp"
  "OpenCV"
  "sensor_msgs"
  "cv_bridge"
  "image_transport"
)

install(TARGETS   CvColor
  DESTINATION lib/${PROJECT_NAME})
install(TARGETS SplitAndMerge
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
