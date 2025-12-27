# Christmas Platformer - Game Design Document

## 🎯 Visão Geral

Jogo de plataforma 2D temático de Natal onde o jogador controla um personagem que deve coletar presentes enquanto evita obstáculos e inimigos através de 4 fases progressivas.

**Objetivo:** Coletar todos os presentes de cada fase para progredir.

---

## 🎮 Mecânicas de Gameplay

### Controles
- **Seta Esquerda/A:** Mover para esquerda
- **Seta Direita/D:** Mover para direita
- **Espaço/W:** Pular
- **ESC:** Pausar/Menu

### Movimento do Personagem
- **Velocidade constante:** Sem aceleração gradual
- **Resposta imediata:** Tecla pressionada = movimento instantâneo
- **Parada instantânea:** Sem deslize ao soltar a tecla
- **Pulo simples:** Altura fixa ao pressionar, sem variação por tempo de tecla
- **Física básica:** Gravidade constante aplicada quando no ar

### Sistema de Vidas
- **3 vidas iniciais**
- Perde vida ao:
  - Colidir com inimigo
  - Cair em buraco/armadilha
- **Game Over:** Quando todas as vidas acabam
- **Sem checkpoints:** Fase recomeça do início ao perder vida

---

## 🎭 Entidades

### 1. Player (Personagem Jogável)
**Representação:** Quadrado/retângulo colorido (ex: vermelho/verde temático)

**Propriedades:**
- Posição (x, y)
- Velocidade de movimento: 200 pixels/segundo
- Altura do pulo: 300 pixels
- Gravidade: 980 pixels/segundo²
- Tamanho: 32x32 pixels

**Estados:**
- Idle (parado)
- Walking (andando)
- Jumping (pulando)
- Falling (caindo)

### 2. Enemy (Inimigo)
**Representação:** Quadrado/retângulo colorido (ex: roxo/azul escuro)

**Comportamento:**
- **Patrulha simples:** Move-se horizontalmente entre dois pontos
- **Detecção:** Nenhuma - apenas segue padrão de patrulha
- **Velocidade:** 100 pixels/segundo
- **Tamanho:** 28x28 pixels
- **Dano:** Remove 1 vida ao colidir com player

**Lógica:**
```
while (game running):
    move in current direction
    if (reached patrol point A or B):
        reverse direction
```

### 3. Collectible (Presente)
**Representação:** Quadrado/losango colorido (ex: amarelo/dourado)

**Propriedades:**
- Posição fixa no nível
- Tamanho: 24x24 pixels
- **Efeito:** Incrementa contador de presentes coletados
- **Comportamento:** Desaparece ao ser coletado

### 4. Platform (Plataforma)
**Representação:** Retângulo sólido (ex: branco/cinza)

**Propriedades:**
- Posição e dimensões variáveis
- Sólida - player pode andar e pular sobre ela
- Estática - não se move

---

## 🏔️ Sistema de Níveis

### Estrutura de Fase
Cada fase consiste em:
- **Plataformas:** Disposição variada criando desafios de navegação
- **Inimigos:** 2-5 inimigos com patrulhas
- **Presentes:** 5-8 presentes espalhados estrategicamente
- **Linha de chegada:** Porta/portal que só abre ao coletar todos presentes

### Progressão
1. **Fase 1 - Tutorial:** Poucas plataformas, 2 inimigos, fácil
2. **Fase 2 - Floresta:** Plataformas verticais, 3 inimigos
3. **Fase 3 - Montanha:** Desafio de precisão, 4 inimigos
4. **Fase 4 - Céu:** Fase final mais difícil, 5 inimigos

### Condição de Vitória
```
if (presents_collected == total_presents_in_level):
    unlock_exit()
    if (player reaches exit):
        load_next_level()
```

---

## 🎨 Especificações Visuais

### Fase 1 - Renderização Geométrica
Todas as entidades são renderizadas como formas geométricas simples:

| Entidade | Forma | Cor Sugerida |
|----------|-------|--------------|
| Player | Retângulo | Vermelho (#E74C3C) |
| Enemy | Retângulo | Roxo (#9B59B6) |
| Present | Losango | Amarelo (#F1C40F) |
| Platform | Retângulo | Branco (#ECF0F1) |
| Background | Sólido | Azul escuro (#2C3E50) |

### Preparação para Sprites
A arquitetura deve permitir substituir renderização geométrica por sprites sem modificar lógica:
- Separação clara entre lógica e renderização
- Interface de renderização abstraída
- Estrutura de dados pronta para armazenar texturas

---

## 🔧 Especificações Técnicas

### Resolução
- **Janela:** 1280x720 pixels
- **Framerate alvo:** 60 FPS
- **Delta time:** Sim (movimento independente de FPS)

### Física
- **Gravidade:** 980 px/s² (simulando ~10 m/s²)
- **Velocidade terminal:** 600 px/s (queda máxima)
- **Detecção de colisão:** AABB (Axis-Aligned Bounding Box)

### Arquitetura
```
Game Loop:
    1. Process Input (teclado)
    2. Update (física, IA, colisões)
    3. Render (desenhar tudo)
```

---

## 📊 Dados de Nível

### Formato (inicial - pode evoluir)
```cpp
struct LevelData {
    std::vector<Platform> platforms;
    std::vector<Enemy> enemies;
    std::vector<Collectible> presents;
    Vector2 playerStartPos;
    Vector2 exitPos;
};
```

---

## 🚀 Fases de Desenvolvimento

### Marco 1: Core System
- [ ] Game loop básico
- [ ] Renderização de formas geométricas
- [ ] Input handling

### Marco 2: Player
- [ ] Movimento horizontal
- [ ] Pulo e gravidade
- [ ] Colisão com plataformas

### Marco 3: World
- [ ] Sistema de níveis
- [ ] Carregar/renderizar plataformas
- [ ] Câmera (se necessário)

### Marco 4: Gameplay
- [ ] Presentes coletáveis
- [ ] Sistema de vidas
- [ ] Transição entre fases

### Marco 5: Inimigos
- [ ] IA de patrulha
- [ ] Colisão player-inimigo
- [ ] Lógica de dano

### Marco 6: Polish
- [ ] UI (vidas, presentes coletados)
- [ ] Tela de menu
- [ ] Tela de game over/vitória

---

## 🔄 Futuras Expansões (Pós-MVP)

- Sistema de sprites e animações
- Efeitos sonoros e música
- Power-ups (duplo pulo, invencibilidade)
- Sistema de pontuação/tempo
- Mais tipos de inimigos
- Plataformas móveis
- Port para Rust

---

**Última atualização:** Dezembro 2025
