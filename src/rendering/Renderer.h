#ifndef RENDERER_H
#define RENDERER_H

#include "raylib.h"
#include <vector>

class Player;
class Enemy;
class Collectible;

/**
 * Namespace contendo funções de renderização
 * Separa lógica de desenho das entidades
 * Facilita futura transição para sprites
 */
namespace Renderer {

    /**
     * Inicializa sistema de renderização
     * Configura window, FPS target, etc.
     */
    void Initialize(int screenWidth, int screenHeight, const char* title);

    /**
     * Fecha sistema de renderização
     */
    void Shutdown();

    /**
     * Inicia frame de desenho
     * Limpa tela com cor de fundo
     */
    void BeginFrame(Color backgroundColor);

    /**
     * Finaliza frame de desenho
     */
    void EndFrame();

    /**
     * Desenha plataforma (retângulo simples)
     */
    void DrawPlatform(Rectangle platform, Color color);

    /**
     * Desenha múltiplas plataformas
     */
    void DrawPlatforms(const std::vector<Rectangle>& platforms, Color color);

    /**
     * Desenha UI do jogo (vidas, presentes coletados, etc)
     */
    void DrawGameUI(int lives, int presentsCollected, int totalPresents);

    /**
     * Desenha tela de game over
     */
    void DrawGameOverScreen();

    /**
     * Desenha tela de vitória
     */
    void DrawVictoryScreen();

    /**
     * Desenha tela de menu
     */
    void DrawMenuScreen();

    /**
     * Desenha tela de pause
     */
    void DrawPauseScreen();

#endif
