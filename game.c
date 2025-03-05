#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_CAVALOS 5
#define DISTANCIA 50

typedef struct{
    int numero, posicao;
    float velocidade, probabilidade_impulso, resistencia;
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
    float odds[NUM_CAVALOS] = {2.5, 3.0, 1.8, 4.5, 2.2};
    int saldo = 100, aposta, escolha;
    
    while (saldo > 0){
        
        for (int i = 0; i < NUM_CAVALOS; i++){
            cavalos[i].numero = i + 1;
        }
        
        printf("Seu saldo atual: $%d\n", saldo);
        printf("Escolha um cavalo para apostar:\n");
        for (int i = 0; i < NUM_CAVALOS; i++){
            printf("%d - Cavalo %d (Odds: %.1f)\n", i + 1, cavalos[i].numero, odds[i]);
        }

        while (escolha > 5){
            printf("Digite o numero do cavalo: ");
            scanf("%d", &escolha);
            if (escolha > 5) printf("Numero invalido!\n");
        }
        escolha--;
        
        printf("Digite o valor da aposta: ");
        scanf("%d", &aposta);
        
        if (aposta > saldo || aposta <= 0){
            printf("Aposta Invalida!\n");
            continue;
        }
        
        for (int i = 0; i < NUM_CAVALOS; i++){
            cavalos[i].numero = i + 1; 
            cavalos[i].posicao = 0; 
            cavalos[i].velocidade = 1 + (rand() % 3);
            cavalos[i].resistencia = (rand() % 5) / 10.0 + 0.5;
            cavalos[i].probabilidade_impulso = (rand() % 100)/100.0;
        }
            
        int corrida_terminada = 0, vencedor = -1;
        
        while (!corrida_terminada){
            for (int i = 0; i < NUM_CAVALOS; i++){
                int evento = rand() % 100;
                if (evento < 5) {
                    printf("O Cavalo %d tropecou e perdeu posicoes...\n", cavalos[i].numero);
                    cavalos[i].posicao -= 2;
                    sleep(1);
                    if (cavalos[i].posicao < 0) cavalos[i].posicao = 0;
                } else if (evento < 15) {
                    printf("O Cavalo %d disparou na frente!\n", cavalos[i].numero);
                    cavalos[i].posicao += 5;
                    sleep(1);
                } else if (evento < 25 && cavalos[i].resistencia < 0.7 ) {
                    printf("O Cavalo %d está cansado e reduziu a velociade!\n", cavalos[i].numero);
                    cavalos[i].velocidade -= 0.5;
                    sleep(1);
                }
                    
                if ((rand() % 100) < cavalos[i].probabilidade_impulso * 100){
                    cavalos[i].posicao += (rand() % 6) + 1;
                } else{
                    cavalos[i].posicao += rand() % 4 + (int)cavalos[i].velocidade;
                }

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
            int ganho = aposta * odds[vencedor];
            printf("Parabens! Voce ganhou $%d!\n", ganho);
            saldo += ganho;
        } else{
            printf("Que pena! Voce perdeu sua aposta.\n");
            saldo -= aposta;
        }

        printf("Deseja jogar novamente? (1 - Sim, 0 - Nao): ");
        int continuar;
        scanf("%d", &continuar);
        if (!continuar) break;
    }

    if (saldo <= 0) printf("VOCE PERDEU TUDO O QUE TINHA!\n");
    printf("Jogo encerrado. Seu saldo final: $%d\n", saldo);
    return 0; 
}