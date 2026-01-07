#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include "raylib.h"

/**
 * Classe que representa um item coletável (presente de Natal)
 * Desaparece quando o jogador coleta
 */
 class Collectible {
     public:
        Collectible(Vector2 position);

        void Update(float deltaTime);
        void Draw() const;

        Vector2 GetPosition() const { return position; }
        Rectangle GetCollisionRect() const;
        bool IsCollected() const { return collected; }

        void Collect() { collected = true; }
    private:
        Vector2 position;

        static constexpr float SIZE = 24.0f;

        bool collected;
        Color color;

        float animationTime;
 };

#endif
