/**
 * Christmas Platformer
 * Entry point do jogo
 */

 #include "core/Game.h"
 #include <iostream>
 #include <exception>

 int main() {
     try {
         // Cria instância do jogo
         Game game;

         // Inicializa sistemas
         game.Initialize();

         // Roda o game loop
         game.Run();

         // Cleanup
         game.Shutdown();

         return 0;

     } catch (const std::exception& e) {
         std::cerr << "ERRO FATAL: " << e.what() << std::endl;
         return 1;
     }
 }
