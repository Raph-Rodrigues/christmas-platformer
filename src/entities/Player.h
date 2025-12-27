#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

/**
 * Classe que representa o personagem jogável
 * Controla movimento, pulo, física e estado do jogador
 */

class Player {
    public:
        // Construtor - inicializa o player em posição
        Player(Vector2 startPos);

        // Métodos principais
        void Update(float deltaTime);       // atualiza lógica do player
        void Draw() const;                  // desenha o player na tela
        void HandleInput();                 // processa o input do teclado

        // Ações
        void Jump();                        // executa o pulo
        void TakeDamage();                  // leva dano
        void Reset(Vector2 position);       // reseta a posição do player após sua morte

        // Getters - métodos para acessar dados privados
        Vector2 GetPosition() const { return position; }
        Vector2 GetVelocity() const { return velocity; }
        Rectangle GetCollisionRect() const; // retorna o retangulo de colisão
        int GetLives() const { return lives; }
        bool IsOnGround() const { return onGround; }
        bool IsAlive() const { return lives > 0; }

        // Setters - métodos para modificar dados privados
        void SetPosition(Vector2 pos) { position = pos; }
        void SetVelocity(Vector2 vel) { velocity = vel; }
        void SetOnGround(bool grounded) { onGround = grounded; }
    private:
        // Atributos de movimento e posição
        Vector2 position;                  // posição atual
        Vector2 velocity;                  // velocidade atual

        // constantes de gameplay (baseadas no design document)
        static constexpr float MOVE_SPEED = 200.0f;
        static constexpr float JUMP_FORCE = -500.0f;
        static constexpr float GRAVITY = 980.0f;
        static constexpr float MAX_FALL_SPEED = 600.0f;

        // dimensões
        static constexpr float HEIGHT = 32.0f;
        static constexpr float WIDTH = 32.0f;

        // estado
        int lives;
        bool onGround;

        // cor da renderização
        Color color;
};

#endif
