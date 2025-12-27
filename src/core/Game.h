#ifndef GAME_H
#define GAME_H

#include "core/GameState.h"
#include "entities/Player.h"
#include "world/Level.h"
#include "world/LevelData.h"
#include <raylib.h>
#include <vector>
#include <memory>

/**
 * Classe principal do jogo - o orquestrador
 * Gerencia o game loop, estados, níveis e entidades
 */
class Game {
public:
    // Construtor e Destrutor
    Game();
    ~Game();

    // Métodos principais do game loop
    void Initialize();      // Inicializa sistemas (janela, recursos, etc)
    void Run();             // Loop principal - chama Update e Draw até fechar
    void Shutdown();        // Libera recursos e fecha

private:
    // === GAME LOOP INTERNO ===
    void ProcessInput();    // Processa input baseado no estado atual
    void Update();          // Atualiza lógica baseado no estado atual
    void Draw();            // Desenha baseado no estado atual

    // === GERENCIAMENTO DE ESTADOS ===
    void UpdateMenu();
    void UpdatePlaying();
    void UpdatePaused();
    void UpdateGameOver();
    void UpdateVictory();

    void DrawMenu();
    void DrawPlaying();
    void DrawPaused();
    void DrawGameOver();
    void DrawVictory();

    // === TRANSIÇÕES DE ESTADO ===
    void ChangeState(GameState newState);

    // === GERENCIAMENTO DE NÍVEIS ===
    void LoadLevel(int levelIndex);
    void NextLevel();
    void RestartLevel();
    void ResetPlayer();

    // === DADOS DE NÍVEIS ===
    void InitializeLevels();  // Cria os dados das 4 fases
    std::vector<LevelData> CreateAllLevels();
    LevelData CreateLevel1();
    LevelData CreateLevel2();
    LevelData CreateLevel3();
    LevelData CreateLevel4();

    // === ESTADO DO JOGO ===
    GameState currentState;
    GameState previousState;  // Útil para voltar do pause

    // === ENTIDADES E MUNDO ===
    std::unique_ptr<Player> player;  // unique_ptr = "eu sou dono deste objeto"
    Level currentLevel;

    // === DADOS DOS NÍVEIS ===
    std::vector<LevelData> allLevels;
    int currentLevelIndex;

    // === CONFIGURAÇÕES ===
    static constexpr int SCREEN_WIDTH = 1280;
    static constexpr int SCREEN_HEIGHT = 720;
    static constexpr int TARGET_FPS = 60;

    // === TEMPO ===
    float deltaTime;

    // === FLAGS ===
    bool isRunning;
};

#endif // GAME_H
