cmake_minimum_required(VERSION 3.23)
include(CMakePrintHelpers)

project(QtWidgetsApplication1 LANGUAGES CXX)

# If no build type is specified, default to "Release"
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Release" FORCE)
endif()

# Global CMake options
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS}")#/ENTRY:mainCRTStartup) # /SUBSYSTEM:WINDOWS 
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets SerialBus SerialPort REQUIRED) #

# $ENV{OPENCV_DIR} must point to local OpenCV installation
# E.g.: setx -m OPENCV_DIR C:/tools/opencv/build/x64/vc15
#list(APPEND CMAKE_PREFIX_PATH "$ENV{OPENCV41_DIR}/x64/vc15/lib")
#find_package(OpenCV REQUIRED)

# Essencials
#add_subdirectory("Essencials/AutazaScience")
#add_subdirectory("Essencials/Logger")
#add_subdirectory("Essencials/License")
#add_subdirectory("Essencials/Utils")

add_subdirectory("QtWidgetsApplication1")

# Doxygen Support
#find_package(Doxygen)
#if (DOXYGEN_FOUND)
#    set(DOXYFILE_IN ${PROJECT_SOURCE_DIR}/Docs/doxyfile.in)
#    set(DOXYFILE_OUT ${PROJECT_BINARY_DIR}/Docs/doxyfile)
#    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)
#
#    add_custom_target(doc3D
#        COMMAND ${CMAKE_COMMAND} -E env TOPDIR=${PROJECT_SOURCE_DIR} OUTDIR=${PROJECT_BINARY_DIR} ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
#        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#        COMMENT "Generating API Documentation (doxygen)"
#        VERBATIM
#    )
#endif()