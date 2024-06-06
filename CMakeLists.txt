cmake_minimum_required(VERSION 3.17)

add_definitions("-std=c++17")

set(CLIENT r-type_client)
project(${CLIENT})
set(SERVE r-type_server)
project(${SERVE})
include(build/conanbuildinfo.cmake)

file(GLOB CLIENT_INCLUDE_FILE Game/client/include/*)
file(GLOB CLIENT_SRC_FILE Game/client/src/*)
file(GLOB SERVE_INCLUDE_FILE Game/server/include/*)
file(GLOB SERVE_SRC_FILE Game/server/src/*)

file(GLOB REGISTRY_HPP_FILE Engine/Registry/registry.hpp)
file(GLOB REGISTRY_CPP_FILE Engine/Registry/registry.cpp)
file(GLOB COMPONENT_FILE Engine/Sparse_array/component.hpp)
file(GLOB SYSTEM_FILE Engine/System/system.hpp)
file(GLOB SPARSE_ARRAY_FILE Engine/Sparse_array/sparse_array.hpp)
file(GLOB SYSTEM_SRC_FILE Engine/System/system.cpp)
file(GLOB SFML_INCLUDE_FILE Game/sfml/smfl.hpp)
file(GLOB SFML_SRC_FILE Game/sfml/sfml.cpp)


set(CLIENT_INCLUDE ${CLIENT_INCLUDE_FILE})
set(CLIENT_SRC ${CLIENT_SRC_FILE})
set(SERVE_INCLUDE ${SERVE_INCLUDE_FILE})
set(SERVE_SRC ${SERVE_SRC_FILE})
set(REGISTRY_HPP ${REGISTRY_HPP_FILE})
set(REGISTRY_CPP ${REGISTRY_CPP_FILE})
set(SPARSE_ARRAY ${SPARSE_ARRAY_FILE})
set(COMPONENT ${COMPONENT_FILE})
set(SYSTEM ${SYSTEM_FILE})
set(SYSTEM_F ${SYSTEM_SRC_FILE})
set(SFML_INCLUDE ${SFML_INCLUDE_FILE})
set(SFML_SRC ${SFML_SRC_FILE})

conan_basic_setup()
add_executable(${CLIENT} ${CLIENT_INCLUDE} ${CLIENT_SRC} ${REGISTRY_HPP} ${REGISTRY_CPP} ${SPARSE_ARRAY} ${COMPONENT} ${SYSTEM} ${SYSTEM_F} ${SFML_INCLUDE_FILE} ${SFML_SRC_FILE})
conan_basic_setup()

add_executable(${SERVE} ${SERVE_INCLUDE} ${SERVE_SRC} ${REGISTRY_HPP} ${REGISTRY_CPP} ${SPARSE_ARRAY} ${COMPONENT} ${SYSTEM} ${SYSTEM_F})
# TARGET_LINK_LIBRARIES(${CLIENT} ${CONAN_LIBS})
# TARGET_LINK_LIBRARIES(${SERVE} ${CONAN_LIBS})

# add_executable(${SERVE} ${SERVE_INCLUDE} ${SERVE_SRC} ${REGISTRY_HPP} ${REGISTRY_CPP} ${SPARSE_ARRAY} ${COMPONENT} ${SYSTEM})

add_subdirectory(Game/Lib librairies)

TARGET_LINK_LIBRARIES(${CLIENT} ${CONAN_LIBS} sfml)
TARGET_LINK_LIBRARIES(${SERVE} ${CONAN_LIBS} sfml)

install(TARGETS r-type_server DESTINATION bin)

install(TARGETS r-type_client DESTINATION bin)

set(CPACK_RESSOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")

include (CPack)