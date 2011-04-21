cmake_minimum_required(VERSION 2.6)

project(InkMLtk)

file( GLOB InkMLtk_SRCS  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )
file( GLOB InkMLtk_HEADS "${CMAKE_CURRENT_SOURCE_DIR}/include/inkmllib/*.h" )

set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})

# Include
set( System_INC /usr/include/)
set( INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include/inkmllib" )

# include_directories( SYSTEM ${System_INC} )
include_directories( ${INCLUDE} )

INSTALL( FILES ${InkMLtk_HEADS} DESTINATION include/ )

# Shared
add_library( inkmltk SHARED ${InkMLtk_SRCS} )
INSTALL( FILES ${CMAKE_CURRENT_BINARY_DIR}/lib/libinkmltk.so DESTINATION lib/ )

# Static
# add_library( inkmltk ${InkMLtk_SRCS} )
# INSTALL( FILES ${CMAKE_CURRENT_BINARY_DIR}/lib/libinkmltk.a DESTINATION lib/ )



# SET_TARGET_PROPERTIES( inkmltk PROPERTIES DEFINE_SYMBOL "EXPORT" )


# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/CMake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/CMake/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/CMake/cmake_uninstall.cmake)
