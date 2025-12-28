#include "Renderer.h"
#include "entities/Player.h"
#include "entities/Enemy.h"
#include "entities/Collectible.h"
#include <raylib.h>
#include <string>

namespace Renderer {
    void Initialize(int screenWidth, int screenHeight, const char *title) {
        // Inicializa a janela raylib
        InitWindow(screenWidth, screenHeight, title);

        // define o FPS alvo para 60
        SetTargetFPS(60);

        // Configurações adicionais
        SetExitKey(KEY_NULL); // Desabilita ESC para sair da janela
    }

    void Shutdown() {
        CloseWindow();
    }

    void BeginFrame(Color backgroundColor) {
        BeginDrawing();
        ClearBackground(backgroundColor);
    }

    void EndFrame() {
        EndDrawing();
    }

    void DrawPlatform(Rectangle platform, Color color) {
        DrawRectangleRec(platform, color);
        // desenha a borda para destacar
        DrawRectangleLinesEx(platform, 2.0f, ColorBrightness(color, -0.3f));
    }

    void DrawPlatforms(const std::vector<Rectangle> &platforms, Color color) {
        for (const auto& platform : platforms) {
            DrawPlatform(platform, color);
        }
    }

    void DrawGameUI(int lives, int presentsCollected, int totalPresents) {
        // desenha vidas no canto superior esquerdo
        const int heartSize = 30;
        const int heartSpacing = 40;
        const int margin = 20;

        for (int i = 0; i < lives; i++) {
            int x = margin + (i * heartSpacing);
            int y = margin;

            // desenha o coração como losango simples
            Vector2 points[4] = {
                {(float)x + heartSize/2, (float)y},             // topo
                {(float)x + heartSize, (float)y + heartSize/2}, // direita
                {(float)x + heartSize/2, (float)y + heartSize}, // baixo
                {(float)x, (float)y + heartSize/2}              // esquerda
            };

            DrawTriangle(points[0], points[1], points[2], RED);
            DrawTriangle(points[0], points[2], points[3], RED);
        }

        // Desenha contador de presentes no canto superior direito
        std::string presentText = "Presentes: " + std::to_string(presentsCollected) + "/" + std::to_string(totalPresents);
        int textWidth = MeasureText(presentText.c_str(), 30);
        DrawText(presentText.c_str(), GetScreenWidth() - textWidth - margin, margin, 30, GOLD);

        // Desenha indicador se saída está aberta
        if (presentsCollected >= totalPresents) {
            const char* exitText = "SAÍDA DESBLOQUEADA!";
            int exitTextWidth = MeasureText(exitText, 40);
            DrawText(exitText, GetScreenWidth()/2 - exitTextWidth/2, 100, 40, GREEN);
        }
    }

    void DrawGameOverScreen() {
        // Fundo Semi-Transparente
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.7f));

        // texto principal
        const char* gameOverText = "GAMEOVER";
        int texttWidth = MeasureText(gameOverText, 80);
        DrawText(gameOverText, GetScreenWidth()/2 - texttWidth/2, GetScreenHeight()/2 - 100, 80, RED);

        // instruções
        const char* restartText = "Pressione R para reiniciar";
        int restartWidth = MeasureText(restartText, 30);
        DrawText(restartText, GetScreenWidth()/2 - restartWidth/2, GetScreenHeight()/2 + 50, 30, WHITE);

        const char* menuText = "Pressione ESC para menu";
        int menuWidth = MeasureText(menuText, 30);
        DrawText(menuText, GetScreenWidth()/2 - menuWidth/2, GetScreenHeight()/2 + 100, 30, WHITE);
    }

    void DrawVictoryScreen() {
        // Fundo Semi-Transparente
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(GREEN, 0.3f));

        // Texto principal
        const char* victoryText = "FELIZ NATAL!";
        int textWidth = MeasureText(victoryText, 80);
        DrawText(victoryText, GetScreenWidth()/2 - textWidth/2, GetScreenHeight()/2 - 100, 80, GOLD);

        // Subtítulo
        const char* completeText = "Você completou todas as fases!";
        int completeWidth = MeasureText(completeText, 40);
        DrawText(completeText, GetScreenWidth()/2 - completeWidth/2, GetScreenHeight()/2, 40, WHITE);

        // Instruções
        const char* menuText = "Pressione ESC para menu";
        int menuWidth = MeasureText(menuText, 30);
        DrawText(menuText, GetScreenWidth()/2 - menuWidth/2, GetScreenHeight()/2 + 100, 30, WHITE);
    }

    void DrawMenuScreen() {
        // Fundo
        ClearBackground(Color{44, 62, 80, 255}); // azul escuro natalino

        // título
        const char* titleText = "CHRISTMAS PLATFORMER";
        int titleWidth = MeasureText(titleText, 70);
        DrawText(titleText, GetScreenWidth()/2 - titleWidth/2, 150, 70, RED);

        // Decoração natalina
        DrawPoly({200, 200}, 5, 30, 0, GOLD);
        DrawPoly({GetScreenWidth() - 200.0f, 200}, 5, 30, 0, GOLD);

        // Instruções
        const char* startText = "Pressione ENTER para iniciar";
        int startWidth = MeasureText(startText, 40);
        DrawText(startText, GetScreenWidth()/2 - startWidth/2, GetScreenHeight()/2 + 50, 40, WHITE);
        const char* controlsText = "Controles: SETAS/WASD para mover, ESPACO para pular";
        int controlsWidth = MeasureText(controlsText, 25);
        DrawText(controlsText, GetScreenWidth()/2 - controlsWidth/2, GetScreenHeight()/2 + 150, 25, LIGHTGRAY);

        // Créditos
        const char* creditsText = "Desenvolvido com Raylib";
        int creditsWidth = MeasureText(creditsText, 20);
        DrawText(creditsText, GetScreenWidth()/2 - creditsWidth/2, GetScreenHeight() - 50, 20, DARKGRAY);
    }

    void DrawPauseScreen() {
        // Fundo semi-transparente sobre o jogo
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.5f));

        // Texto
        const char* pauseText = "PAUSADO";
        int textWidth = MeasureText(pauseText, 80);
        DrawText(pauseText, GetScreenWidth()/2 - textWidth/2, GetScreenHeight()/2 - 50, 80, WHITE);

        // Instruções
        const char* continueText = "Pressione ESC para continuar";
        int continueWidth = MeasureText(continueText, 30);
        DrawText(continueText, GetScreenWidth()/2 - continueWidth/2, GetScreenHeight()/2 + 50, 30, LIGHTGRAY);
    }
}
