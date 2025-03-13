cmake_minimum_required(VERSION 3.16)

project(QtQmlControllerExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

add_executable(QtQmlControllerExample
    src/main.cpp
    src/Controller.cpp
    src/Controller.h
)

qt_add_resources(RESOURCES resources.qrc)

target_link_libraries(QtQmlControllerExample PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

# Resources:
set(QtQmlControllerExample_resource_files
    "qml/main.qml"
)

qt_add_resources(QtQmlControllerExample "QtQmlControllerExample"
    FILES
        ${QtQmlControllerExample_resource_files}
)


