#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

/**
 * Classe que representa um inimigo com patrulha simples
 * Move-se horizontalmente entre dois pontos
 */

 class Enemy {
     public:
        // Construtor - define posição inicial e limites de patrulha
        Enemy(Vector2 startPos, float patrolRangeLeft, float patrolRangeRight);

        // Métodos principais
        void Update(float deltaTime);
        void Draw() const;

        // Getters
        Vector2 GetPosition() const { return position; }
        Rectangle GetCollisionRect() const;
        bool IsAlive() const { return active; }

        // Estado
        void Desactivate() { active = false; }
    private:
        Vector2 position;
        float speed;

        float patrolLeft;
        float patrolRight;
        bool movingRight;

        static constexpr float MOVE_SPEED = 100.0f;
        static constexpr float WIDTH = 28.0f;
        static constexpr float HEIGHT = 28.0f;

        bool active;
        Color color;
 };

#endif
