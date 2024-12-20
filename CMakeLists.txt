cmake_minimum_required(VERSION 3.14)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

project(push_swap)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

option(BUILD_TEST "Build tests" ON)
option(BUILD_PUSH_SWAP "Build push_swap (for_compile_commands)" OFF)

# testing ##################################################
# Flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -fsanitize=address")

# Add libft subdirectory
if(BUILD_TEST)
  add_subdirectory(libft)

  file(GLOB PUSH_SWAP_SOURCES "src/*.c")
  file(GLOB TEST_FILES "tests/*.cpp")
  set(TEST_NAME "run_tests")
  add_executable(${TEST_NAME} ${PUSH_SWAP_SOURCES} ${TEST_FILES})

  target_link_libraries(${TEST_NAME} gtest gtest_main pthread ft)

  target_include_directories(${TEST_NAME} PRIVATE includes)
  target_include_directories(${TEST_NAME} PRIVATE libft)
  target_include_directories(${TEST_NAME} PRIVATE ${gtest_SOURCE_DIR}/googletest/include)

  include(GoogleTest)
  gtest_discover_tests(${TEST_NAME})
endif()

# Building philo ##################################################
if(BUILD_PUSH_SWAP)
  add_executable(push_swap ${PUSH_SWAP_SOURCES} run/push_swap/main.c)
  add_executable(checker ${PUSH_SWAP_SOURCES} run/checker/main.c)
  target_link_libraries(push_swap ft)
  target_link_libraries(checker ft)
  target_include_directories(push_swap PRIVATE includes)
  target_include_directories(push_swap PRIVATE libft)
  target_include_directories(checker PRIVATE includes)
  target_include_directories(checker PRIVATE libft)
endif()
