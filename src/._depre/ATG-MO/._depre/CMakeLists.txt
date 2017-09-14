
find_package(LLVM REQUIRED CONFIG)

set(CMAKE_CXX_FLAGS "-std=c++11 -fno-rtti" )

#message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
#message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_library(hello  MODULE Hello.cpp)
