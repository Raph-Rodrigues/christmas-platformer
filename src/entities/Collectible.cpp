#include "Collectible.h"
#include <cmath>
#include <cstdint>
#include <raylib.h>

Collectible::Collectible(Vector2 position)
    : position(position), collected(false), color(GOLD), animationTime(0.0f)
    {
    }

void Collectible::Update(float deltaTime) {
    // atualiza a animação se ja foi coletado
    // mesmo coletado atualiza para possiveis efeitos futuros
    animationTime += deltaTime;
}

void Collectible::Draw() const {
    // não desenha se já foi coletado
    if (collected) {
        return;
    }

    // desenha como losango (diamante) rotacionando
    // usa animationTime para fazer "flutuar" visualmente
    float offset = sinf(animationTime * 2.0f) * 5.0f; // oscila 5 pxs

    Vector2 adjustedPos = {position.x, position.y + offset};

    // pontos do losango
    Vector2 points[4] = {
        {adjustedPos.x + SIZE/2, adjustedPos.y},        // topo
        {adjustedPos.x + SIZE, adjustedPos.y + SIZE/2}, // direita
        {adjustedPos.x + SIZE/2, adjustedPos.y + SIZE}, // baixo
        {adjustedPos.x, adjustedPos.y + SIZE/2}         // esquerda
    };

    // desenha dois triangulos formando losango
    DrawTriangle(points[0], points[1], points[2], color);
    DrawTriangle(points[0], points[2], points[3], color);

    // desenha borda para destacar
    DrawLineV(points[0], points[1], ColorBrightness(color, -0.3f));
    DrawLineV(points[1], points[2], ColorBrightness(color, -0.3f));
    DrawLineV(points[2], points[3], ColorBrightness(color, -0.3f));
    DrawLineV(points[3], points[0], ColorBrightness(color, -0.3f));
}

Rectangle Collectible::GetCollisionRect() const {
    // Retângulo de colisão ligeiramente menor que o visual
    // Isso torna a coleta mais "generosa" para o jogador
    float margin = 4.0f;
    return Rectangle{
        position.x + margin,
        position.y + margin,
        SIZE - margin * 2,
        SIZE - margin * 2
    };
}
