cmake_minimum_required(VERSION 3.18.1)

add_library(playerlib SHARED ./Player.cpp ./AudioTrackRenderer.cpp)

#Oboe
#include(FetchContent)
#
#FetchContent_Declare(oboe
#        GIT_REPOSITORY https://github.com/shiva1422/oboe.git
#        GIT_TAG srconly
#        )
#
#FetchContent_GetProperties(oboe)
#if(NOT oboe)
#    # Fetch the content using previously declared details
#    FetchContent_Populate(oboe)
#
#    # Set custom variables, policies, etc.
#    # ...
#
#    include_directories({oboe_SOURCE_DIR}/include)
#    # Bring the populated content into the build
#    add_subdirectory(${oboe_SOURCE_DIR} ${CMAKE_BINARY_DIR}/oboe)
#endif()

find_library(log-lib log )

target_link_libraries(playerlib ${log-lib} )