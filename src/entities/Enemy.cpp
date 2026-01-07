#include "Enemy.h"
#include <raylib.h>

Enemy::Enemy(Vector2 startPosition, float patrolRangeLeft, float patrolRangeRight)
    : position(startPosition)
    , speed(MOVE_SPEED)
    , patrolLeft(patrolRangeLeft)
    , patrolRight(patrolRangeRight)
    , movingRight(true)
    , active(true)
    , color(PURPLE)
{
}

void Enemy::Update(float deltaTime) {
    if (!active) {
        return; // nao atualiza inativo
    }

    // move na direção atual
    if (movingRight) {
        position.x += speed * deltaTime;

        // verifica se atingiu o limite direito
        if (position.x + WIDTH >= patrolRight) {
            position.x = patrolRight - WIDTH;   // ajusta para não ultrapassar
            movingRight = false;                // inverte a direção
        }
    }
    else {
        position.x -= speed * deltaTime;

        // verifica se atingiu o limite esquerdo
        if (position.x <= patrolLeft) {
            position.x = patrolLeft;    // ajusta para não ultrapassar
            movingRight = true;         // inverte a direção
        }
    }
}

void Enemy::Draw() const {
    if (!active) {
        return; // nao desenha inativo
    }

    // desenha o inimigo como retangulo
    Rectangle enemyRect = {position.x, position.y, WIDTH, HEIGHT};
    DrawRectangleRec(enemyRect, color);

    // desenha borda mais escura
    DrawRectangleLinesEx(enemyRect, 2.0f, ColorBrightness(color, -0.4f));

    // desenha 'olhos'
    float eyeSize = 4.0f;
    float eyeOffset = WIDTH * 0.25f;
    float eyeY = position.y + HEIGHT * 0.35f;

    // olho esquerdo
    DrawCircle(position.x + eyeOffset, eyeY, eyeSize, RED);
    // olho direito
    DrawCircle(position.x + WIDTH - eyeOffset, eyeY, eyeSize, RED);

    // Opcional: Desenha linha de patrulha (útil para debug)
        #ifdef DEBUG_DRAW
        DrawLine(patrolLeft, position.y + HEIGHT + 5, patrolRight, position.y + HEIGHT + 5, Fade(RED, 0.3f));
        #endif
}

Rectangle Enemy::GetCollisionRect() const {
    return Rectangle{
        position.x,
        position.y,
        WIDTH,
        HEIGHT,
    };
}
