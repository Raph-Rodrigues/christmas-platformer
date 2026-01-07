#ifndef LEVEL_H
#define LEVEL_H

#include "LevelData.h"
#include "entities/Enemy.h"
#include "entities/Collectible.h"
#include <vector>
#include <memory>

// Forward declaration
class Player;

/**
 * Classe que gerencia um nível durante o jogo
 * Carrega LevelData e cria/gerencia as entidades vivas
 */
class Level {
public:
    // Construtor padrão
    Level();

    // Carrega um nível a partir dos dados
    void LoadFromData(const LevelData& data);

    // Métodos principais
    void Update(float deltaTime, Player& player);
    void Draw() const;

    // Reset do nível (quando player perde vida)
    void Reset();

    // Getters
    const std::vector<Rectangle>& GetPlatforms() const { return platforms; }
    const std::vector<Enemy>& GetEnemies() const { return enemies; }
    std::vector<Enemy>& GetEnemies() { return enemies; }  // Versão não-const
    std::vector<Collectible>& GetCollectibles() { return collectibles; }

    Vector2 GetPlayerStartPosition() const { return playerStartPos; }
    Vector2 GetExitPosition() const { return exitPos; }

    // Estado do nível
    int GetPresentsCollected() const { return presentsCollected; }
    int GetTotalPresents() const { return totalPresents; }
    bool IsExitUnlocked() const { return presentsCollected >= totalPresents; }

    // Incrementa contador de presentes
    void CollectPresent() { presentsCollected++; }

private:
    // Dados estáticos (plataformas não mudam)
    std::vector<Rectangle> platforms;
    Vector2 playerStartPos;
    Vector2 exitPos;
    Rectangle exitRect;

    // Entidades vivas (mudam durante o jogo)
    std::vector<Enemy> enemies;
    std::vector<Collectible> collectibles;

    // Estado
    int presentsCollected;
    int totalPresents;
    int levelNumber;

    // Dados originais para reset
    LevelData originalData;

    // Helper para criar entidades a partir dos dados
    void SpawnEnemies(const std::vector<EnemySpawnData>& spawns);
    void SpawnCollectibles(const std::vector<Vector2>& positions);
};

#endif // LEVEL_H
