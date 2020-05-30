cmake_minimum_required(VERSION 3.17)
project(Moenis)
# ##############################################################################
# PROJECT
# ##############################################################################
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
file(STRINGS "VERSION" MOENIS_VERSION)
project(MOENIS VERSION "${MOENIS_VERSION}" LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_VERBOSE_MAKEFILE OFF)
message(STATUS "Project: ${PROJECT_NAME}")

# ##############################################################################
# GIT REVISION
# ##############################################################################
execute_process(COMMAND git rev-parse HEAD OUTPUT_VARIABLE PROJECT_VERSION_COMMIT_LONG OUTPUT_STRIP_TRAILING_WHITESPACE)
string(SUBSTRING ${PROJECT_VERSION_COMMIT_LONG} 0 7 PROJECT_VERSION_COMMIT)
message(STATUS "Version: ${PROJECT_VERSION} (${PROJECT_VERSION_COMMIT})")

# ##############################################################################
# BUILD TYPE
# ##############################################################################
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE
      "Debug"
      CACHE STRING "Build Mode" FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
                                               "MinSizeRel" "RelWithDebInfo")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(BUILD_TYPE_DEBUG ON)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(BUILD_TYPE_RELEASE ON)
elseif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
  set(BUILD_TYPE_MIN_SIZE_REL ON)
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
  set(BUILD_TYPE_REL_WITH_DEB_INFO ON)
endif()

# ##############################################################################
# OPTIONS
# ##############################################################################
option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors" TRUE)

option(ENABLE_PCH "Enable Precompiled Headers" ON)
option(ENABLE_IPO "Enable Interporcedural Optimization, aka Link Time Optimization (LTO)" ON)

option(STATIC_ANALYSIS "Use static analysis tools" ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL
                                           "Clang")
  option(ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" FALSE)
  option(ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" FALSE)
  option(ENALBE_SANITIZER_UNDEFINED_BEHAVIOR
         "Enable undefined behavior sanitizer" FALSE)
  option(ENABLE_SANITIZER_THREAD "Enable thread sanitizer" FALSE)

  if(ENABLE_SANITIZER_ADDRESS
     OR ENABLE_SANITIZER_MEMORY
     OR ENALBE_SANITIZER_UNDEFINED_BEHAVIOR
     OR ENABLE_SANITIZER_THREAD)
    set(ENABLE_SANITIZERS)
  endif()
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  option(BUILD_SHARED_LIBS "Compile shared libraries" FALSE)
  option(BUILD_STATIC_LIBS "Compile static libraries" TRUE)
else()
  option(BUILD_STATIC_LIBS "Compile static libraries" FALSE)
  option(BUILD_SHARED_LIBS "Compile shared libraries" TRUE)
endif()

if(STATIC_ANALYSIS)
  option(ENABLE_CPPCHECK "Enable cppcheck" TRUE)
  option(ENABLE_CLANG_TIDY "Enable clang-tidy" TRUE)
  option(ENABLE_FIXER "Apply available static analysis fixes" FALSE)
endif()

# ##############################################################################
# CCACHE
# ##############################################################################
find_program(CCACHE ccache)
if(CCACHE)
  message(STATUS "using ccache")
  set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE})
else()
  message(STATUS "ccache not found cannot use")
endif()

# ##############################################################################
# IPO
# ##############################################################################
if(ENABLE_IPO)
  include(CheckIPOSupported)
  check_ipo_supported(RESULT IPO_SUPPORT OUTPUT IPO_SUPPORT_MSG)
  if(IPO_SUPPORT)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
  else()
    message(SEND_ERROR "IPO is not supported: ${IPO_SUPPORT_MSG}")
  endif()
endif()

# ##############################################################################
# CONFIG TARGETS
# ##############################################################################
add_library(moenis-options INTERFACE)
add_library(moenis::options ALIAS moenis-options)
target_compile_features(moenis-options INTERFACE cxx_std_17)
add_library(moenis-warnings INTERFACE)
add_library(moenis::warnings ALIAS moenis-warnings)

# ##############################################################################
# COMPILE COMMANDS
# ##############################################################################
if(BUILD_TYPE_DEBUG OR BUILD_TYPE_REL_WITH_DEB_INFO)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  if(EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
    execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json)
  endif()
endif()

# ##############################################################################
# SANITIZERS
# ##############################################################################
if(ENABLE_SANITIZERS)
  set(SANITIZERS "")
  if(ENABLE_SANITIZER_ADDRESS)
    list(APPEND SANITIZERS "address")
  endif()
  if(ENABLE_SANITIZER_MEMORY)
    list(APPEND SANITIZERS "memory")
  endif()
  if(ENABLE_SANITIZER_UNDEFINED_BEHAVIOR)
    list(APPEND SANITIZERS "undefined")
  endif()
  if(ENABLE_SANITIZER_THREAD)
    list(APPEND SANITIZERS "thread")
  endif()
  list(JOIN SANITIZERS "," SANITIZERS)
  if(NOT "${SANITIZERS}" STREQUAL "")
    target_compile_options(moenis-options INTERFACE -fsanitize=${SANITIZERS})
    target_link_libraries(moenis-options INTERFACE -fsanitize=${SANITIZERS})
  endif()
endif()

# ##############################################################################
# WARNINGS
# ##############################################################################
set(MSVC_WARNINGS /W4 /w14242 /w14254 /w14263 /w14265 /w14287 /we4289 /w14296 /w14311 /w14545 /w14546 /w14547 /w14549 /w14555 /w14619 /w14640 /w14826 /w14905 /w14906 /w14928)
set(CLANG_WARNINGS -Wall -Wextra -Wno-shadow -Wnon-virtual-dtor -Wno-old-style-cast -Wno-cast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wno-implicit-int-conversion -Wno-sign-conversion -Wno-sign-compare -Wnull-dereference -Wno-double-promotion -Wno-implicit-float-conversion -Wno-shorten-64-to-32 -Wno-float-conversion -Wno-unused-parameter -Wno-macro-redefined -Wformat=2)
if(WARNINGS_AS_ERRORS)
  set(CLANG_WARNINGS ${CLANG_WARNINGS} -Werror)
  set(MSVC_WARNIGNS ${MSVC_WARNINGS} /Wx)
endif()
set(GCC_WARNINGS ${CLANG_WARNINGS} -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast)
if(MSVC)
  target_compile_options(moenis-warnings INTERFACE ${MSVC_WARNINGS})
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(moenis-warnings INTERFACE ${GCC_WARNINGS})
else()
  target_compile_options(moenis-warnings INTERFACE ${CLANG_WARNINGS})
endif()

# ##############################################################################
# STATIC ANALYSIS
# ##############################################################################
if(STATIC_ANALYSIS)
  if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE "clang-tidy")
    if(CLANG_TIDY_EXE)
      message(STATUS "Found clang-tidy ${CLANG_TIDY_EXE}")
      set(CLANG_TIDY_CMD "${CLANG_TIDY_EXE}"
                         "--checks=*,-modernize-use-trailing-return-type")
      if(FIX)
        list(APPEND CLANG_TIDY_CMD "--fix")
      endif()
    else()
      message(STATUS "Could not find clang-tidy")
    endif()
  endif()
  if(ENABLE_CPPCHECK)
    find_program(CPPCHECK_EXE "cppcheck")
    if(CPPCHECK_EXE)
      message(STATUS "Found cppcheck ${CPPCHECK_EXE}")
      set(CPPCHECK_CMD "${CPPCHECK_EXE}" "--suppress=missingInclude"
                       "--enable=all" "--inconclusive")
    else()
      message(STATUS "Could not find cppcheck")
    endif()
  endif()
endif()

# ##############################################################################
# PCH
# ##############################################################################
if(ENABLE_PCH)
  target_precompile_headers(
    moenis-options
    INTERFACE
    <string>
    <cmath>)
endif()

# ##############################################################################
# TARGETS
# ##############################################################################
# DEPENDENCIES
add_subdirectory(external)
add_library(moenis-dependencies INTERFACE)
add_library(moenis::dependencies ALIAS moenis-dependencies)

# COMPILER DETECTION
include(WriteCompilerDetectionHeader)
set(MOENIS_COMPILERS MSVC GNU Clang Intel AppleClang)
write_compiler_detection_header(
  FILE ${CMAKE_CURRENT_SOURCE_DIR}/include/compiler.hpp
  PREFIX "CXX"
  COMPILERS ${MOENIS_COMPILERS}
  FEATURES
  cxx_constexpr
  cxx_deleted_functions
  cxx_final
  cxx_noexcept
  cxx_override
  cxx_alignas
  cxx_alignof
  cxx_nullptr
  cxx_static_assert
  cxx_attribute_deprecated
  cxx_thread_local)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/include/version.hpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/include/version.hpp")

add_executable(Moenis src/main.cpp)
target_include_directories(Moenis PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(Moenis PROPERTIES CXX_CLANG_TIDY "${CLANGTIDY_CMD}" CXX_CPPCHECK "${CPPCHECK_CMD}")
target_link_libraries(Moenis PUBLIC moenis::dependencies moenis::options moenis::warnings)
install(TARGETS Moenis RUNTIME DESTINATION bin)

# ##############################################################################
# REPORTING
# ##############################################################################
message(STATUS "CMAKE_BINARY_DIR:      ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_SOURCE_DIR:      ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_VERSION:         ${CMAKE_VERSION}")
message(STATUS "CMAKE_GENERATOR:       ${CMAKE_GENERATOR}")
message(STATUS "CMAKE_C_COMPILER_ID:   ${CMAKE_C_COMPILER_ID}")
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_BUILD_TYPE:      ${CMAKE_BUILD_TYPE}")

# ##############################################################################
# PACKAGING
# ##############################################################################
if(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(CPACK_GENERATOR "TGZ;ZIP")
  set(CPACK_PACKAGE_VENDOR "LuxAter")
  set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
  set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
  set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
  set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
  set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md)
  set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE)
  set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${CMAKE_SYSTEM_NAME}")
  set(CPACK_MONOLITHIC_INSTALL TRUE)
  include(CPack)
endif()
