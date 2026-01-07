# Lista todos os arquivos fonte que vamos criar
set(SOURCES
    main.cpp
    core/Game.cpp
    entities/Player.cpp
    entities/Enemy.cpp
    entities/Collectible.cpp
    physics/Physics.cpp
    rendering/Renderer.cpp
    world/Level.cpp
)

# Lista todos os headers
set(HEADERS
    core/Game.h
    core/GameState.h
    entities/Player.h
    entities/Enemy.h
    entities/Collectible.h
    physics/Physics.h
    rendering/Renderer.h
    world/Level.h
    world/LevelData.h
)

# Cria o executável
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Inclui o diretório src para os headers
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Linka com Raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Propriedades do executável
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
