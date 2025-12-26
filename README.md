# 🎄 Christmas Platformer

Um jogo de plataforma temático de Natal desenvolvido em C++ com Raylib e dentro de ambiente Linux no CachyOS.

## 🎮 Preview

> 📸 Screenshots em breve - projeto em desenvolvimento

## ✨ Features

- 🎅 Personagem jogável com movimentação e pulo
- 🎁 Sistema de coleta de presentes
- ❤️ Sistema de vidas (3 vidas)
- 👾 Inimigos e obstáculos
- 🏔️ 4 fases temáticas de Natal
- 🎨 Renderização geométrica (expansível para sprites)

## 🛠️ Tecnologias

- **Linguagem:** C++17
- **Engine gráfica:** Raylib
- **Build system:** CMake 3.20+
- **Controle de versão:** Git

## 📊 Status do Projeto

🚧 **Em desenvolvimento ativo** - Implementando features base

**Próximos marcos:**
- [ ] Setup do projeto e estrutura base
- [ ] Sistema de movimentação do player
- [ ] Física e colisões
- [ ] Sistema de níveis
- [ ] Inimigos e coletáveis

## 📋 Pré-requisitos

Certifique-se de ter instalado:

- **Compilador C++17:** GCC 9+ ou Clang 10+
- **CMake:** 3.20 ou superior
- **Raylib:** 5.0 ou superior
- **Git:** Para controle de versão

### Instalação no Arch/ArchBasedDistros
```bash
sudo pacman -S base-devel cmake raylib git
```

## 🔨 Como Compilar
```bash
# Clone o repositório
git clone https://github.com/Raph-Rodrigues/christmas-platformer.git
cd christmas-platformer

# Crie a pasta de build
mkdir build
cd build

# Configure com CMake
cmake ..

# Compile
make

# Executável gerado: build/ChristmasPlatformer
```

## 🚀 Como Rodar
```bash
# A partir da pasta build
./ChristmasPlatformer
```

## 🎯 Roadmap

- **Fase 1:** Sistema base e movimentação
- **Fase 2:** Física e colisões
- **Fase 3:** Níveis e gameplay
- **Fase 4:** Port para Rust (Bevy/ggez/Macroquad)

## 📝 Licença

MIT License - sinta-se livre para usar e modificar

---

**Desenvolvido com ❤️ durante o Natal de 2025**
