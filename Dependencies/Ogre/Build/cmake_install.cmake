# Install script for directory: C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE DIRECTORY FILES "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/Dependencies/bin/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE" TYPE FILE FILES "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/include/OgreBuildSettings.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES
      "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/inst/bin/debug/resources_d.cfg"
      "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/inst/bin/debug/plugins_d.cfg"
      "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/inst/bin/debug/samples_d.cfg"
      "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/inst/bin/debug/tests_d.cfg"
      "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/inst/bin/debug/quakemap_d.cfg"
      )
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll]|[Nn][Oo][Nn][Ee]|)$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES
      "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/inst/bin/release/resources.cfg"
      "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/inst/bin/release/plugins.cfg"
      "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/inst/bin/release/samples.cfg"
      "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/inst/bin/release/tests.cfg"
      "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/inst/bin/release/quakemap.cfg"
      )
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll]|[Nn][Oo][Nn][Ee]|)$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/CMake" TYPE FILE FILES
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/cmake/OGREConfig.cmake"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/cmake/OGREConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/OgreMain/cmake_install.cmake")
  include("C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/RenderSystems/cmake_install.cmake")
  include("C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/PlugIns/cmake_install.cmake")
  include("C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/Components/cmake_install.cmake")
  include("C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/Samples/cmake_install.cmake")
  include("C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/Tools/cmake_install.cmake")
  include("C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/Docs/cmake_install.cmake")
  include("C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/cmake/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
