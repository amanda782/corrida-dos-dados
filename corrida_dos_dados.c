#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void imprimeRegras(char nome[])
    {
    printf("Essas são as regras do jogo:\n");
    printf("- Os dois jogadores (você e a máquina) começam com 0 pontos.\n");
    printf("- Cada jogador pode rolar o dado quantas vezes quiser, e cada valor obtido é somado à pontuação da rodada.\n");
    printf("- Se o jogador rolar um 1, a pontuação da rodada é zerada e a vez passa para o outro jogador.\n");
    printf("- O jogador pode encerrar a rodada a qualquer momento, somando a pontuação da rodada à sua pontuação total.\n");
    printf("- O primeiro jogador a atingir 100 pontos vence o jogo.\n");
    printf("- Boa sorte, %s. Divirta-se jogando!\n\n", nome);
    sleep(2);
    }

    int sorteioDado()
    {
    return (rand() % 6) + 1; // Retorna um número entre 1 e 6
    }

    int humano(int pontosTotal)
    {
    int pontosRodada = 0;
    char escolha;

    while (1)
    {
        int dado = sorteioDado();
        printf("\nVocê rolou o dado e obteve: %d\n", dado);

        if (dado == 1)
        {
            printf("\nQue pena, você perdeu todos os pontos da rodada :(\n\n");
            sleep(2);
            return 0; // quebra o laço e retorna 0 pontos
        }
        pontosRodada += dado; // Soma os pontos
        printf("\nVocê tem %d pontos na rodada e %d pontos no total\n\n", pontosRodada, pontosTotal+pontosRodada);
        sleep(1);
        
       
        
        int escolhaValida=0;
        
        while(escolhaValida==0) {
            
            printf("Deseja continuar rolando o dado? (s/n): ");
            scanf(" %c", &escolha); // lê a escolha do jogador
            
        if (escolha == 'n' || escolha == 'N') 
        {
            printf("\nVocê encerrou a rodada com %d pontos.\n\n", pontosRodada);
            sleep(2);
            return pontosRodada;
        }
        
        else if(escolha=='s' || escolha == 'S') 
            escolhaValida=1; // vai pro loop principal (sorteio do dado)
            
        else {
            printf("\nEscolha inválida. Tente novamente.\n\n "); // continua o loop (vai pro scanf novamente)
           
           
    } } }  }

    int maquina(int pontosTotal)
    {
        int pontosRodada = 0;

        printf("\nVez do computador!\n");
        sleep(2);
        while (pontosRodada < 20)
        { // quero parar em 20 por rodada
            int dado = sorteioDado();
            printf("O computador rolou o dado e obteve: %d\n", dado);
            sleep(1); 

            if (dado == 1)
            {
                printf("\nO computador perdeu todos os pontos da rodada.\n\n");
                sleep(4);
                return 0;
            }
            pontosRodada += dado;
        }
        printf("O computador tem %d pontos na rodada e %d pontos totais.\n", pontosRodada, pontosTotal+pontosRodada);
        sleep(2);
        return pontosRodada;
    }
    int main()
    {
        srand(time(NULL));
        printf("Olá! Digite o nome do jogador: ");
        char nome[50];
        scanf("%s", nome);
        printf("\nOlá %s! Vamos jogar \"Corrida até 100\".\n\n", nome);

        imprimeRegras(nome);
        int pontosHumano = 0;
        int pontosMaquina = 0;

        while (pontosHumano < 100 && pontosMaquina < 100)
        {
            printf("Sua vez, %s!\n\n", nome);
            pontosHumano += humano(pontosHumano); // Adiciona os pontos da rodada ao total do jogador
            printf("Você tem %d pontos no total.\n", pontosHumano);
            if (pontosHumano >= 100)
            {
                printf("Parabéns, %s! Você venceu\n", nome);
                break;
            }

            pontosMaquina += maquina(pontosMaquina); // Adiciona os pontos da rodada ao total do computador
            printf("O computador tem %d pontos no total.\n\n", pontosMaquina);
        }
        if (pontosMaquina >= 100)
        {
            printf("O computador venceu!\n");
          
        }
        
        else
            printf("Jogo finalizado.\n");


      

        return 0;
    }