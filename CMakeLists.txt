cmake_minimum_required(VERSION 3.27.7)
project(cserve VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")


add_subdirectory(dependencies/drogon)
link_directories(/usr/local/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/drogon/lib/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(cserve src/main.cc src/todos.cc)

target_link_libraries(cserve pthread)
target_link_libraries(cserve drogon)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)