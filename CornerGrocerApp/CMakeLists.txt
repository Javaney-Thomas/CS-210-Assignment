cmake_minimum_required(VERSION 3.10)

project(CornerGrocerApp)

# Setting C++ standard
set(CMAKE_CXX_STANDARD 14)

# Adding source files
set(SOURCE_FILES
    src/CornerGrocerApp.cpp
    main.cpp
)

# Adding executable
add_executable(CornerGrocerApp ${SOURCE_FILES})

# Including directories
target_include_directories(CornerGrocerApp PRIVATE include)
