#ifndef LEVELDATA_H
#define LEVELDATA_H

#include <raylib.h>
#include <vector>

/**
 * Estrutura que define spawn de um inimigo
 * Contém dados necessários para criar um Enemy
 */
struct EnemySpawnData {
    Vector2 position;       // Posição inicial
    float patrolLeft;       // Limite esquerdo da patrulha
    float patrolRight;      // Limite direito da patrulha
};

/**
 * Estrutura que contém todos os dados estáticos de um nível
 * Funciona como "receita" para construir o nível
 * Não contém objetos do jogo, apenas dados de configuração
 */
struct LevelData {
    // Plataformas do nível
    std::vector<Rectangle> platforms;

    // Dados para spawnar inimigos
    std::vector<EnemySpawnData> enemySpawns;

    // Posições dos coletáveis
    std::vector<Vector2> collectiblePositions;

    // Posições especiais
    Vector2 playerStartPosition;
    Vector2 exitPosition;

    // Metadados
    int levelNumber;                // Número da fase (1, 2, 3, 4)
    const char* levelName;          // Nome da fase ("Floresta de Natal")
    int requiredPresents;           // Quantos presentes para abrir saída

    // Construtor padrão
    LevelData()
        : playerStartPosition({100, 100})
        , exitPosition({1100, 100})
        , levelNumber(1)
        , levelName("Level 1")
        , requiredPresents(0)
    {}
};

#endif // LEVELDATA_H
