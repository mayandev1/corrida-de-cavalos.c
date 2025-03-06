#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_CAVALOS 5
#define DISTANCIA 50

typedef struct{
    int numero, posicao, experiencia;
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

void upgrade(Cavalo *cavalo, int *saldo){
    int custo = 20 + cavalo->experiencia * 10;

    if (*saldo < custo){
        printf("Saldo insuficiente, upgrade indisponivel!");
        return;
    }

    *saldo -= custo;
    cavalo->velocidade += 0.5;
    cavalo->resistencia += 0.1;
    cavalo->probabilidade_impulso += 0.05;
    cavalo->experiencia += 1;

    printf("Melhoria concluída!\n Velocidade: %.1f | Resistencia: %1.f | Impulso: %.2f%% | Exp: %d\n",
         cavalo->velocidade, cavalo->resistencia, cavalo->probabilidade_impulso, cavalo->experiencia);
}

int main(){
    srand(time(NULL));

    Cavalo cavalos[NUM_CAVALOS];
    float odds[NUM_CAVALOS] = {2.5, 3.0, 1.8, 4.5, 2.2};
    int saldo = 100, aposta, escolha;
    
    for (int i = 0; i < NUM_CAVALOS; i++){
        cavalos[i].numero = i + 1; 
        cavalos[i].posicao = 0; 
        cavalos[i].velocidade = 1 + (rand() % 3);
        cavalos[i].resistencia = (rand() % 5) / 10.0 + 0.5;
        cavalos[i].probabilidade_impulso = (rand() % 100)/100.0;
        cavalos[i].experiencia = 0;
    }

    while (saldo > 0){
        
        
        printf("\nSeu saldo atual: $%d\n", saldo);
        printf("Escolha uma opcao:\n1 - Apostar em uma corrida\n2 - Melhorar um cavalo\nDigite: ");
        int opcao;
        scanf("%d", &opcao);

        if (opcao == 2){
            printf("Escolha um cavalo para melhorar:\n");
            for (int i = 0; i < NUM_CAVALOS; i++){
                printf("%d - Cavalo %d (Velocidade: %.1f | Resistencia: %1.f | Impulso: %.2f%% | Exp: %d\n)",
                i + 1, cavalos[i].numero, cavalos[i].velocidade, cavalos[i].resistencia, cavalos[i].probabilidade_impulso * 100, cavalos[i].experiencia);
            }
            scanf("%d", &escolha);
            escolha--;

            if (escolha >= 0 && escolha < NUM_CAVALOS){
                upgrade(&cavalos[escolha], &saldo);
            }
            continue;
        }
        
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
        }
        
        int corrida_terminada = 0, vencedor = -1;
        
        while (!corrida_terminada){
            for (int i = 0; i < NUM_CAVALOS; i++){
                int evento = rand() % 100;
                if (evento < 5){
                    printf("O Cavalo %d tropecou e perdeu posicoes...\n", cavalos[i].numero);
                    cavalos[i].posicao -= 2;
                    sleep(1);
                    if (cavalos[i].posicao < 0) cavalos[i].posicao = 0;
                } else if (evento < 15){
                    printf("O Cavalo %d disparou na frente!\n", cavalos[i].numero);
                    cavalos[i].posicao += 5;
                    sleep(1);
                } else if (evento < 25 && cavalos[i].resistencia < 0.7 ){
                    printf("O Cavalo %d esta cansado e reduziu a velociade!\n", cavalos[i].numero);
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
            printf("Voce perdeu sua aposta, HAHAHAHAHAHA.\n");
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