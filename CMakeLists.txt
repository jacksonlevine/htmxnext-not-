cmake_minimum_required(VERSION 3.10)

# set the project name
project(MyProject)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Crow CONFIG REQUIRED)
find_package(SOCI CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)


# add the executable
add_executable(main main.cpp)

# link the libraries to the executable
target_link_libraries(main PRIVATE Crow::Crow)
target_link_libraries(main PRIVATE SOCI::soci_core SOCI::soci_empty)
target_link_libraries(main PRIVATE unofficial::sqlite3::sqlite3)