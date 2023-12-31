cmake_minimum_required(VERSION 3.14)

project(test_server LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)

add_executable(test_server
  main.cpp
  test_server.cpp
  socket_adapter.cpp
  json_creator.cpp
)
target_link_libraries(test_server Qt${QT_VERSION_MAJOR}::Core Qt6::Network)

install(TARGETS test_server
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
