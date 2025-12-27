#ifndef GAMESTATE_H
#define GAMESTATE_H

/**
 * Enumeração dos possíveis estados do jogo
 * Controla o fluxo principal da aplicação
 */
 enum class GameState {
    MENU,       // Tela de menu inicial
    LOADING,    // Carregando recursos/fase
    PLAYING,    // Jogando ativamente
    PAUSED,     // Jogo pausado
    GAME_OVER,  // Perdeu todas as vidas
    VICTORY     // Completou todas as fases
 };

#endif
