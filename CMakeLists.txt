cmake_minimum_required(VERSION 3.15)
project(trabalhoPPC)

# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 23)
SET(GCC_COVERAGE_COMPILE_FLAGS "CFLAGS=-m64 CXXFLAGS=-m64")

# if(WIN32)
#   list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/libs/SDL2/cmake")
#   find_package(SDL2 REQUIRED)
#   include_directories(${SDL2_INCLUDE_DIRS})
#   add_library(queue STATIC "${PROJECT_SOURCE_DIR}/src/queue.c")
#   add_library(banheiro STATIC "${PROJECT_SOURCE_DIR}/src/banheiro.c")
#   add_library(pessoa STATIC "${PROJECT_SOURCE_DIR}/src/pessoa.c")
#   add_executable(${PROJECT_NAME} main.c)
#   target_link_libraries(${PROJECT_NAME}
#   ${SDL2_STATIC_LIBRARIES}
#   "${PROJECT_SOURCE_DIR}/build/libqueue.a"
#   "${PROJECT_SOURCE_DIR}/build/libbanheiro.a"
#   "${PROJECT_SOURCE_DIR}/build/libpessoa.a"
#   )
#   target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/src")
# endif(WIN32)

if(WIN32)
  list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/libs/SDL2-VC/cmake")
  find_package(SDL2 REQUIRED)
  include_directories(${SDL2_INCLUDE_DIRS})
  add_library(queue STATIC "${PROJECT_SOURCE_DIR}/src/queue.c")
  add_library(banheiro STATIC "${PROJECT_SOURCE_DIR}/src/banheiro.c")
  add_library(pessoa STATIC "${PROJECT_SOURCE_DIR}/src/pessoa.c")
  add_executable(${PROJECT_NAME} main.c)
  target_link_libraries(${PROJECT_NAME}
  ${SDL2_LIBRARIES}
  "${PROJECT_SOURCE_DIR}/build/Release/queue.lib"
  "${PROJECT_SOURCE_DIR}/build/Release/banheiro.lib"
  "${PROJECT_SOURCE_DIR}/build/Release/pessoa.lib")
  target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/src")
  configure_file("${PROJECT_SOURCE_DIR}/libs/SDL2-VC/lib/x64/SDL2.dll" "${PROJECT_SOURCE_DIR}/build/Release/SDL2.dll" COPYONLY)
endif(WIN32)
  
if(UNIX)
  find_package(SDL2 REQUIRED)
  include_directories(${SDL2_INCLUDE_DIRS})
  add_executable(${PROJECT_NAME} main.c)
  target_link_libraries(${PROJECT_NAME} 
  ${SDL2_LIBRARIES} 
  "${PROJECT_SOURCE_DIR}/src/queue.c"
  "${PROJECT_SOURCE_DIR}/src/banheiro.c"
  "${PROJECT_SOURCE_DIR}/src/pessoa.c"
  )
  target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/src")
endif(UNIX)


# add_executable(${PROJECT_NAME} main.c)

# target_link_libraries(${PROJECT_NAME} ${SDL2_STATIC_LIBRARIES})