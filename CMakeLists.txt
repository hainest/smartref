cmake_minimum_required(VERSION 3.5)

project(delegation LANGUAGES CXX)

enable_testing()

################################################################################
# Counter library                                                              #
################################################################################
add_library(libcounter INTERFACE)
target_sources(libcounter INTERFACE ${PROJECT_SOURCE_DIR}/src/counter.h)
target_include_directories(libcounter INTERFACE ${PROJECT_SOURCE_DIR}/src)
target_compile_features(libcounter INTERFACE cxx_std_17)

add_executable(test_counter tests/counter.cpp)
target_link_libraries(test_counter PRIVATE libcounter)
add_test(counter test_counter)
################################################################################


################################################################################
# Reflection library                                                           #
################################################################################
add_library(libreflection INTERFACE)
target_sources(libreflection INTERFACE ${PROJECT_SOURCE_DIR}/src/reflection.h)
target_include_directories(libreflection INTERFACE ${PROJECT_SOURCE_DIR}/src)
target_compile_features(libreflection INTERFACE cxx_std_17)
target_link_libraries(libreflection INTERFACE libcounter)

add_executable(test_reflection tests/reflection.cpp)
target_compile_features(test_reflection INTERFACE cxx_std_17)
target_link_libraries(test_reflection PRIVATE libcounter)
add_test(reflection test_reflection)
################################################################################


################################################################################
# Delegation library                                                           #
################################################################################
add_library(libdelegation INTERFACE)
target_sources(libdelegation INTERFACE ${PROJECT_SOURCE_DIR}/src/using.h)
target_include_directories(libdelegation INTERFACE ${PROJECT_SOURCE_DIR}/src)
target_compile_features(libdelegation INTERFACE cxx_std_17)
target_link_libraries(libdelegation INTERFACE libreflection)

add_executable(test_delegation examples/delegation.cpp)
target_sources(test_delegation PRIVATE ${PROJECT_SOURCE_DIR}/examples/foobar.h)
target_link_libraries(test_delegation PRIVATE libdelegation)
add_test(delegation test_delegation)
################################################################################