# -*- cmake -*- -----------------------------------------------------------
# @@COPYRIGHT@@
#*-------------------------------------------------------------------------

if(MSVC AND NOT BUILD_SHARED_LIBS)
  set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>)
endif()

# Put test binraries into a convenient directory, if not already set:
if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

# Need the test macros:
include(CMLTestMacros)

# Catch-based test runner:
add_subdirectory(main)

# Common functionality tests:
add_subdirectory(common)

# Storage tests:
add_subdirectory(storage)

# cml::vector<> tests:
add_subdirectory(vector)

# cml::matrix<> tests:
add_subdirectory(matrix)

# cml::quaternion<> tests:
add_subdirectory(quaternion)

# mathlib tests:
add_subdirectory(mathlib)

# util tests:
add_subdirectory(util)

#if(CML_BUILD_TIMING)
  add_subdirectory(timing)
#endif()