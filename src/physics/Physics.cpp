#include "Physics.h"
#include "entities/Player.h"
#include "entities/Enemy.h"
#include "entities/Collectible.h"
#include <algorithm>
#include <raylib.h>

namespace Physics {
    bool CheckCollisionAABB(Rectangle a, Rectangle b) {
        // Algoritmo AABB (Axis-Aligned Bounding Box)
        // Verifica se dois retângulos se sobrepõem
        return (a.x < b.x + b.width &&
                a.x + a.width > b.x &&
                a.y < b.y + b.height &&
                a.y + a.height > b.y);
    }

    void ApplyGravity(float &velocityY, float gravity, float maxFallSpeed, float deltaTime) {
        // aplica aceleração na gravidade
        velocityY += gravity * deltaTime;

        // Limita velocidade de queda (velocidade terminal)
        if (velocityY > maxFallSpeed) {
            velocityY = maxFallSpeed;
        }
    }

    void ResolvePlayerPlatformCollision(Player &player, Rectangle platform) {
        Rectangle playerRect = player.GetCollisionRect();
        Vector2 playerVel = player.GetVelocity();

        // verifica se há colisão
        if (!CheckCollisionAABB(playerRect, platform)) {
            return;
        }

        // calcula o overlap (quanto os retangulos se sobrepoem)
        float overlapLeft = (playerRect.x + playerRect.width) - platform.x;
        float overlapRight = (platform.x + platform.width) - playerRect.x;
        float overlapTop = (playerRect.y + playerRect.height) - platform.y;
        float overlapBottom = (platform.y + platform.height) - playerRect.y;

        // Encontra o menor overlap (direção de resolução mais provável)
        float minOverlap = std::min({overlapLeft, overlapRight, overlapTop, overlapBottom});

        Vector2 newPos = player.GetPosition();
        Vector2 newVel = playerVel;

        // Resolve baseado na menor penetração
        if (minOverlap == overlapTop && playerVel.y > 0) {
            // Colisão por cima (player caindo na plataforma)
            newPos.y = platform.y - playerRect.height;
            newVel.y = 0;
            player.SetOnGround(true);
        }
        else if (minOverlap == overlapBottom && playerVel.y < 0) {
            // Colisão por baixo (player pulando e batendo a cabeça)
            newPos.y = platform.y + platform.height;
            newVel.y = 0;
        }
        else if (minOverlap == overlapLeft && playerVel.x > 0) {
            // Colisão pela esquerda
            newPos.x = platform.x - playerRect.width;
            newVel.x = 0;
        }
        else if (minOverlap == overlapRight && playerVel.x < 0) {
            // colisão pela direita
            newPos.x = platform.x + platform.width;
            newVel.x = 0;
        }

        player.SetPosition(newPos);
        player.SetVelocity(newVel);
    }

    bool CheckPlayerPlatformCollisions(Player &player, const std::vector<Rectangle> &platforms) {
        bool wasOnGround = false;

        // primeiro assume que não esta no chao
        player.SetOnGround(false);

        // verifica colisão com cada plataforma
        for (const auto& platform : platforms) {
            ResolvePlayerPlatformCollision(player, platform);

            // se apos resolver a colisao o player esta no chao
            if (player.IsOnGround()) {
                wasOnGround = true;
            }
        }

        return wasOnGround;
    }

    bool CheckPlayerEnemyCollision(const Player &player, const std::vector<Enemy> &enemies) {
        Rectangle playerRect = player.GetCollisionRect();

        for (const auto& enemy : enemies) {
            if (!enemy.IsActive()) {
                continue; // pula inimigos inativos
            }

            Rectangle enemyRect = enemy.GetCollisionRect();

            if (CheckCollisionAABB(playerRect, enemyRect)) {
                return true; // colidiu com pelo meno um inimigo
            }
        }

        return false;
    }

    int CheckPlayerCollectibleCollisions(const Player &player, std::vector<Collectible> &collectibles) {
        Rectangle playerRect = player.GetCollisionRect();
        int collected = 0;

        for (auto& collectible : collectibles) {
            if (collectible.IsCollected()) {
                continue; // ja foi coletada
            }

            Rectangle collectibleRect = collectible.GetCollisionRect();

            if (CheckCollisionAABB(playerRect, collectibleRect)) {
                collectible.Collect();
                collected++;
            }
        }

        return collected;
    }
}
