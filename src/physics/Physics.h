#ifndef PHYSICS_H
#define PHYSICS_H

#include "raylib.h"
#include <vector>

// Forward declarations - diz que essas classes existem sem incluir os headers
class Player;
class Enemy;
class Collectible;

/**
 * Namespace contendo funções utilitárias de física e colisão
 * Não mantém estado - apenas processa dados
 */

 namespace Physics {
     /**
          * Verifica colisão AABB (Axis-Aligned Bounding Box)
          * Forma mais simples e rápida de detecção de colisão para retângulos
    */

    bool CheckCollisionAABB(Rectangle a, Rectangle b);
    /**
         * Aplica gravidade a uma velocidade vertical
         * @param velocityY Velocidade atual (modificada por referência)
         * @param gravity Força da gravidade
         * @param maxFallSpeed Velocidade máxima de queda
         * @param deltaTime Tempo desde o último frame
    */
    void ApplyGravity(float& velocityY, float gravity, float maxFallSpeed, float deltaTime);

    /**
        * Resolve colisão entre player e plataforma
        * Ajusta posição e velocidade do player para ficar "em cima" da plataforma
    */
    void ResolvePlayerPlatformCollision(Player& player, Rectangle platform);

    /**
         * Verifica e resolve colisões entre player e múltiplas plataformas
         * @return true se player está no chão
    */
    bool CheckPlayerPlatformCollisions(Player& player, const std::vector<Rectangle>& platforms);

    /**
         * Verifica colisão entre player e inimigos
         * @return true se colidiu com algum inimigo
    */
    bool CheckPlayerEnemyCollision(const Player& player, const std::vector<Enemy>& enemies);

    /**
         * Verifica e processa colisões entre player e coletáveis
         * @return número de itens coletados neste frame
    */
    int CheckPlayerCollectibleCollisions(const Player& player, std::vector<Collectible>& collectibles);

 }

#endif
