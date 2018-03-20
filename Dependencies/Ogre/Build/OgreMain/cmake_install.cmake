# Install script for directory: C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain

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
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/Release/OgreMain.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Release/OgreMain.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/RelWithDebInfo/OgreMain.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/RelWithDebInfo/OgreMain.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/MinSizeRel/OgreMain.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/MinSizeRel/OgreMain.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/lib/Debug/OgreMain_d.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Debug/OgreMain_d.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/Debug/OgreMain_d.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/bin/RelWithDebInfo/OgreMain.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE" TYPE FILE FILES
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Ogre.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreASTCCodec.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreAlignedAllocator.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreAnimable.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreAnimation.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreAnimationState.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreAnimationTrack.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreAny.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreArchive.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreArchiveFactory.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreArchiveManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreAtomicObject.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreAtomicScalar.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreAutoParamDataSource.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreAxisAlignedBox.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreBillboard.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreBillboardChain.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreBillboardParticleRenderer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreBillboardSet.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreBitwise.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreBlendMode.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreBone.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreCamera.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreCodec.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreColourValue.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreCommon.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreCompositionPass.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreCompositionTargetPass.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreCompositionTechnique.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreCompositor.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreCompositorChain.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreCompositorInstance.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreCompositorLogic.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreCompositorManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreConfig.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreConfigDialog.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreConfigFile.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreConfigOptionMap.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreController.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreControllerManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreConvexBody.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreCustomCompositionPass.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreDataStream.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreDefaultHardwareBufferManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreDeflate.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreDepthBuffer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreDistanceLodStrategy.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreDualQuaternion.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreDynLib.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreDynLibManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreEdgeListBuilder.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreEntity.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreErrorDialog.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreException.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreExternalTextureSource.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreExternalTextureSourceManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreFactoryObj.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreFileSystem.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreFileSystemLayer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreFrameListener.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreFrustum.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreGpuProgram.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreGpuProgramManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreGpuProgramParams.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreGpuProgramUsage.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreHardwareBuffer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreHardwareBufferManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreHardwareCounterBuffer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreHardwareIndexBuffer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreHardwareOcclusionQuery.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreHardwarePixelBuffer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreHardwareUniformBuffer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreHardwareVertexBuffer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreHeaderPrefix.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreHeaderSuffix.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreHighLevelGpuProgram.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreHighLevelGpuProgramManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreId.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreIdString.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreImage.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreImageCodec.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreInstanceBatch.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreInstanceBatchHW.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreInstanceBatchHW_VTF.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreInstanceBatchShader.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreInstanceBatchVTF.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreInstanceManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreInstancedEntity.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreInstancedGeometry.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreIteratorRange.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreIteratorWrapper.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreIteratorWrappers.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreKeyFrame.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreLight.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreLodListener.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreLodStrategy.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreLodStrategyManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreLog.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreLogManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreManualObject.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMaterial.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMaterialManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMaterialSerializer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMath.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMatrix3.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMatrix4.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMemoryAllocatedObject.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMemoryAllocatorConfig.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMemoryNedAlloc.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMemoryNedPooling.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMemorySTLAllocator.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMemoryStdAlloc.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMemoryTracker.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMesh.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMeshFileFormat.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMeshManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMeshSerializer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMeshSerializerImpl.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMovableObject.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMovablePlane.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreMurmurHash3.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreNameGenerator.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreNode.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreNumerics.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreOptimisedUtil.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreParticle.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreParticleAffector.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreParticleAffectorFactory.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreParticleEmitter.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreParticleEmitterCommands.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreParticleEmitterFactory.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreParticleIterator.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreParticleSystem.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreParticleSystemManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreParticleSystemRenderer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePass.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePatchMesh.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePatchSurface.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePixelCountLodStrategy.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePixelFormat.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePlane.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePlaneBoundedVolume.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePlatform.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePlatformInformation.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePlugin.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePolygon.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePose.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePredefinedControllers.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePrefabFactory.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgrePrerequisites.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreProfiler.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreQuaternion.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRadixSort.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRay.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRectangle2D.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderObjectListener.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderOperation.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderQueue.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderQueueInvocation.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderQueueListener.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderQueueSortingGrouping.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderSystem.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderSystemCapabilities.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderSystemCapabilitiesManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderSystemCapabilitiesSerializer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderTarget.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderTargetListener.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderTexture.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderToVertexBuffer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderWindow.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRenderable.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreResource.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreResourceBackgroundQueue.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreResourceGroupManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreResourceManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRibbonTrail.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRoot.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreRotationalSpline.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSceneManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSceneManagerEnumerator.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSceneNode.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSceneQuery.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreScriptCompiler.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreScriptLexer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreScriptLoader.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreScriptParser.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreScriptTranslator.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSearchOps.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSerializer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreShadowCameraSetup.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreShadowCameraSetupFocused.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreShadowCameraSetupLiSPSM.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreShadowCameraSetupPSSM.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreShadowCameraSetupPlaneOptimal.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreShadowCaster.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreShadowTextureManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreShadowVolumeExtrudeProgram.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSharedPtr.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSimpleRenderable.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSimpleSpline.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSingleton.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSkeleton.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSkeletonFileFormat.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSkeletonInstance.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSkeletonManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSkeletonSerializer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSphere.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSpotShadowFadePng.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreStableHeaders.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreStaticFaceGroup.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreStaticGeometry.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreStdHeaders.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreStreamSerialiser.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreString.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreStringConverter.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreStringInterface.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreStringVector.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSubEntity.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSubMesh.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreTagPoint.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreTangentSpaceCalc.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreTechnique.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreTexture.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreTextureManager.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreTextureUnitState.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreTimer.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreUTFString.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreUnifiedHighLevelGpuProgram.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreUserObjectBindings.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreVector2.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreVector3.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreVector4.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreVertexBoneAssignment.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreVertexIndexData.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreViewport.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreWindowEventUtilities.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreWireBoundingBox.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreWorkQueue.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/include/OgreBuildSettings.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/Build/include/OgreExports.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/src/OgreImageResampler.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/src/OgrePixelConversions.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/src/OgreSIMDHelper.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreads.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreBarrier.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreLightweightMutex.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreBarrier.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreDefaultWorkQueue.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreDefaultWorkQueueStandard.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreDefaultWorkQueueTBB.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreLightweightMutex.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefines.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefinesBoost.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefinesNone.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefinesPoco.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefinesSTD.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefinesTBB.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadHeaders.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadHeadersBoost.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadHeadersPoco.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadHeadersSTD.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadHeadersTBB.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreads.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefinesNone.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreDefaultWorkQueueStandard.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreSTBICodec.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreDDSCodec.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreETCCodec.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/OgreZip.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/WIN32" TYPE FILE FILES
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/WIN32/OgreErrorDialogImp.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/WIN32/OgreTimerImp.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/WIN32/OgreMinGWSupport.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/WIN32/OgreComPtr.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/Threading" TYPE FILE FILES
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreBarrier.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreDefaultWorkQueue.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreDefaultWorkQueueStandard.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreDefaultWorkQueueTBB.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreLightweightMutex.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefines.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefinesBoost.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefinesNone.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefinesPoco.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefinesSTD.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefinesTBB.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadHeaders.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadHeadersBoost.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadHeadersPoco.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadHeadersSTD.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadHeadersTBB.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreads.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreThreadDefinesNone.h"
    "C:/hlocal/P3/ProyectoBasico/Dependencies/Ogre/OgreMain/include/Threading/OgreDefaultWorkQueueStandard.h"
    )
endif()

