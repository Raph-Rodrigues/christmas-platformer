# Versão mínima do CMake necessária
cmake_minimum_required(VERSION 3.20)

# Nome do projeto e linguagem
project(ChristmasPlatformer
    VERSION 1.0.0
    LANGUAGES CXX
)

# Configurações do C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Flags de compilação para diferentes modos
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Define o diretório de saída dos executáveis
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Encontra a biblioteca Raylib
find_package(raylib 5.5 REQUIRED)

# Adiciona o subdiretório src
add_subdirectory(src)

# Mensagens de status (útil para debug)
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
