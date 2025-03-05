#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_CAVALOS 5
#define DISTANCIA 50

typedef struct{
    int numero;
    int posicao;
} Cavalo;

void exibirPista(Cavalo cavalos[]){
    system("cls");
    for (int i = 0; i < NUM_CAVALOS; i++){
        printf("Cavalo %d: ", cavalos[i].numero);
        for (int j = 0; j < cavalos[i].posicao; j++){
            printf("-");
        }
        printf("%d\n", cavalos[i].numero);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));

    Cavalo cavalos[NUM_CAVALOS];
    for (int i = 0; i < NUM_CAVALOS; i++){
        cavalos[i].numero = i + 1;
        cavalos[i].posicao = 0; 
    }

    int saldo = 100;
    int aposta, escolha;

    while (saldo > 0) {
        printf("Seu saldo atual: $%d\n", saldo);
        printf("Escolha um cavalo para apostar:\n");
        for (int i = 0; i < NUM_CAVALOS; i++){
            printf("%d - Cavalo %d\n", i + 1, cavalos[i].numero);
        }
        printf("Digite o numero do cavalo: ");
        scanf("%d", &escolha);
        escolha--;

        printf("Digite o valor da aposta: ");
        scanf("%d", &aposta);

        if (aposta > saldo){
            printf("Saldo insuficiente!\n");
            continue;
        }

        for (int i = 0; i < NUM_CAVALOS; i++){
            cavalos[i].posicao = 0; 
        }

        int corrida_terminada = 0;
        int vencedor = -1;

        while (!corrida_terminada){
            for (int i = 0; i < NUM_CAVALOS; i++){
                cavalos[i].posicao += rand() % 4;
                if (cavalos[i].posicao >= DISTANCIA){
                    corrida_terminada = 1;
                    vencedor = i;
                    break;
                }
            }
            exibirPista(cavalos);
            sleep(1);
        }

        printf("O vencedor foi o Cavalo %d!\n", cavalos[vencedor].numero);

        if (vencedor == escolha){
            printf("Parabens! Voce ganhou $%d!\n", aposta * 2);
            saldo += aposta;
        } else{
            printf("Que pena! Voce perdeu sua aposta.\n");
            saldo -= aposta;
        }

        printf("Deseja jogar novamente? (1 - Sim, 0 - Nao): ");
        int continuar;
        scanf("%d", &continuar);
        if (!continuar) break;
    }

    printf("Jogo encerrado. Seu saldo final: $%d\n", saldo);
    return 0;
}