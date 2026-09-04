# CMakeList.txt : CMake project for Basic Program Framework, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 4.3)

set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD 451f2fe2-a8a2-47c3-bc32-94786d8fc91b)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("Basic Program Framework")

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

if(VCPKG_TOOLCHAIN)
    message(STATUS "[VCPKG] Installed packages path: '${VCPKG_INSTALLED_DIR}'")

endif()
#need SDL3 and SDL image
find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)

add_library (BPF STATIC src/core.cpp src/window.cpp src/render.cpp)
target_include_directories(BPF PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(BPF PUBLIC SDL3::SDL3)
target_link_libraries(BPF PUBLIC SDL3_image::SDL3_image)

add_executable (test test.cpp)
target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test BPF)