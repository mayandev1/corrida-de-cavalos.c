# Corrida de Cavalos - Jogo em C

## Descrição

Este projeto é um jogo de corrida de cavalos desenvolvido em linguagem C. O jogo simula corridas de cavalos, onde o jogador pode apostar em um cavalo, melhorar suas habilidades e acompanhar a evolução de suas estatísticas. Além disso, eventos aleatórios influenciam o desempenho dos cavalos durante as corridas.

## Funcionalidades

1. **Apostas nas Corridas:** O jogador pode apostar em um cavalo e ganhar dinheiro se seu cavalo vencer a corrida.
2. **Melhorias nos Cavalos:** Os cavalos podem ser melhorados, aumentando sua velocidade, resistência e outros atributos ao longo do tempo. Cada melhoria tem um custo, que é descontado do saldo do jogador.
3. **Eventos Aleatórios:** Durante as corridas, podem ocorrer eventos aleatórios, como o cavalo tropeçar, disparar na frente, ou ficar cansado, afetando o desempenho na corrida.
4. **Tabela dos Cavalos:** O jogador pode visualizar a tabela com as estatísticas de todos os cavalos, como velocidade, resistência, impulso e experiência.
5. **Saldo do Jogador:** O jogador começa com um saldo inicial de dinheiro e deve gerenciá-lo, fazendo apostas e realizando melhorias.

## Como Jogar

1. **Iniciar o Jogo:** Ao iniciar o jogo, o jogador verá o menu principal, onde poderá escolher entre as opções de apostar em uma corrida, melhorar um cavalo, visualizar a tabela dos cavalos ou sair.
2. **Apostas:** Ao escolher a opção de aposta, o jogador poderá selecionar um cavalo e realizar uma aposta. O valor da aposta será deduzido do saldo do jogador.
3. **Melhorias:** Ao escolher melhorar um cavalo, o jogador pode selecionar um cavalo específico para melhorar suas estatísticas. Cada melhoria tem um custo, que será deduzido do saldo.
4. **Tabela de Cavalos:** A tabela exibe as estatísticas de todos os cavalos, permitindo que o jogador acompanhe suas evoluções ao longo do tempo.
5. **Corrida:** Durante a corrida, os cavalos se movem conforme suas velocidades e eventos aleatórios, e o jogador verá a posição de cada cavalo na pista.

## Como Rodar

1. **Pré-requisitos:**
   - Compilador C (exemplo: GCC).
   - Sistema operacional com suporte para a biblioteca `unistd.h` (Linux/Mac). Para Windows, a função `sleep` pode ser substituída por `Sleep` da biblioteca `windows.h`.

2. **Compilação:**
   - Abra o terminal ou prompt de comando.
   - Navegue até o diretório do projeto e execute o seguinte comando para compilar o código:
     ```bash
     gcc -o corrida-cavalos main.c
     ```

3. **Execução:**
   - Após a compilação, execute o jogo com o seguinte comando:
     ```bash
     ./corrida-cavalos
     ```

## Estrutura do Código

- **Função `exibirPista`:** Responsável por mostrar a posição dos cavalos na pista durante a corrida.
- **Função `upgrade`:** Permite que o jogador melhore um cavalo, aumentando suas estatísticas.
- **Função `exibirMenu`:** Exibe o menu principal para o jogador escolher suas opções.
- **Função `exibirTabela`:** Exibe a tabela com as estatísticas de todos os cavalos.
- **Função `main`:** Controla o fluxo do jogo, permitindo ao jogador realizar ações como apostar, melhorar cavalos e visualizar a tabela.

## Licença

Este projeto é de código aberto e pode ser usado, modificado e distribuído conforme necessário. 
