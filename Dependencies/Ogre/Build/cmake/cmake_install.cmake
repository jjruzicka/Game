# Install script for directory: C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/CMake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/sdk")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/CMake" TYPE FILE FILES
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/CMake/Utils/FindPkgMacros.cmake"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/CMake/Utils/MacroLogFeature.cmake"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/CMake/Utils/PreprocessorUtils.cmake"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/CMake/Utils/PrecompiledHeader.cmake"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/CMake/Utils/OgreAddTargets.cmake"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/CMake/Utils/OgreConfigTargets.cmake"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/CMake/Utils/OgreGetVersion.cmake"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/CMake/Utils/OgreFindFrameworks.cmake"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/CMake/Templates/VisualStudioUserFile.vcproj.user.in"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/CMake/Templates/VisualStudioUserFile.vcxproj.user.in"
    )
endif()

