cmake_minimum_required(VERSION 3.10)

# set the project name
project(MyProject)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Crow CONFIG REQUIRED)



# add the executable
add_executable(main main.cpp)

# link the libraries to the executable
target_link_libraries(main PRIVATE Crow::Crow)