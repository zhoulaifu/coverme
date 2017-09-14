
#//TODO Understanding those commands

#add_library(foo_expected foo_expected.c)
#message(STATUS "-------------${CMAKE_CURRENT_SOURCE_DIR}")
#message(STATUS "${CMAKE_CURRENT_BINARY_DIR}")
#add_custom_command(
#  OUTPUT foo.bc 
#  COMMAND clang ${CMAKE_CURRENT_SOURCE_DIR}/foo.c -emit-llvm -c -o ${CMAKE_CURRENT_SOURCE_DIR}/foo.bc
  
#  COMMAND opt -load ${CMAKE_CURRENT_BINARY_DIR}/ATG-MO/libhello.so < ${CMAKE_CURRENT_SOURCE_DIR}/foo.bc > /dev/null -o ${CMAKE_CURRENT_SOURCE_DIR}/foo_.bc

#COMMAND clang -c ${CMAKE_CURRENT_SOURCE_DIR}/foo_.bc -o ${CMAKE_CURRENT_SOURCE_DIR}/foo_.o 
#)

execute_process(COMMAND clang ${CMAKE_CURRENT_SOURCE_DIR}/foo.c -emit-llvm -c -o ${CMAKE_CURRENT_SOURCE_DIR}/foo.bc)
 message(STATUS "++++ ${CMAKE_BINARY_DIR}")

 execute_process(COMMAND  opt -load ${CMAKE_BINARY_DIR}/ATG-MO/libhello.so -hello2 < ${CMAKE_CURRENT_SOURCE_DIR}/foo.bc -o ${CMAKE_CURRENT_SOURCE_DIR}/foo_.bc
 OUTPUT_QUIET  ERROR_QUIET )
# execute_process(COMMAND  opt ../../BVA/ress/foo.bc -load ATG-MO/libhello.so -hello2  -o ../../BVA/ress/foo_.bc OUTPUT_QUIET  ERROR_QUIET)

#execute_process(COMMAND clang -c ${CMAKE_CURRENT_SOURCE_DIR}/foo_.bc -o ${CMAKE_CURRENT_SOURCE_DIR}/foo_.o )


#add_custom_comman
#  OUTPUT foo_.bc
#  COMMAND opt -load ../mo/libhello.so < foo.bc > /dev/null -o foo_.bc
#)
#add_custom_command(
#  OUTPUT foo_.o
#  COMMAND clang -c foo_.bc -o foo_.o 
#)

#add_custom_target(run ALL 
#DEPENDS foo.bc)
#add_custom_target(foo_.bc ALL
#DEPENDS foo_.bc)
#add_custom_target(foo_.o ALL
#DEPENDS foo_.o)

