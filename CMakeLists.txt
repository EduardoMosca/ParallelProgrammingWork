cmake_minimum_required(VERSION 3.15)
project(trabalhoPPC)

# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)

# if(WIN32)
#   list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/libs/SDL2/cmake")
#   find_package(SDL2 REQUIRED)
#   include_directories(${SDL2_INCLUDE_DIRS})
#   add_executable(${PROJECT_NAME} main.c)
#   target_link_libraries(${PROJECT_NAME} ${SDL2_STATIC_LIBRARIES})
# endif(WIN32)

if(WIN32)
  list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/libs/SDL2-VC/cmake")
  find_package(SDL2 REQUIRED)
  include_directories(${SDL2_INCLUDE_DIRS})
  add_executable(${PROJECT_NAME} main.c)
  target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} "${PROJECT_SOURCE_DIR}/src/queue.c")
  target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/src")
  configure_file("${SDL2_LIBDIR}/SDL2.dll" "${PROJECT_SOURCE_DIR}/build/Release/SDL2.dll")
endif(WIN32)
  
if(UNIX)
  find_package(SDL2 REQUIRED)
  include_directories(${SDL2_INCLUDE_DIRS})
  add_executable(${PROJECT_NAME} main.c)
  target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} "${PROJECT_SOURCE_DIR}/src/queue.c")
  target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/src")
endif(UNIX)


# add_executable(${PROJECT_NAME} main.c)

# target_link_libraries(${PROJECT_NAME} ${SDL2_STATIC_LIBRARIES})