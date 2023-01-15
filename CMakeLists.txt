cmake_minimum_required(VERSION 3.20)
project(sources_analyzer)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(Boost_USE_STATIC_LIBS ON)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp")

find_package(Boost COMPONENTS program_options filesystem)
include_directories( ${Boost_INCLUDE_DIR} )

message("boost lib: ${Boost_LIBRARIES}")
message ("boost lib dir: ${Boost_LIBRARY_DIRS}")
message("boost inc: ${Boost_INCLUDE_DIR}")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} Boost::program_options
                                    Boost::filesystem)
