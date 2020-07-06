#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include <time.h>

#define m 3
#define n 3
using namespace std;

class Jogo
{
public:
    int matriz[m][n];

        void tabuleiro()
            {
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        matriz[i][j] = 0;
                    }
                }
            }

            void imprime()
            {
                for(int i=0;i<3;i++)
                    {
                        printf("\n");
                        for(int j=0;j<3;j++)
                        {
                            printf("| %d |", matriz[i][j]);
                        }
                        printf("\n");
                    }
            }

            void jogada(int joga)
            {
                int a,b;

                a = rand() % 3;
                b = rand() % 3;

                if(matriz[a][b] != 0)
                {
                    jogada(joga); //chama a funcao de novo ate jogar em algo que acerte
                }
                else
                {
                    matriz[a][b] = joga;
                }


            }

            void valida()
            {

                if(matriz[0][0] + matriz[0][1]+matriz[0][2] == 3 || matriz[1][0] + matriz[1][1]+matriz[1][2] == 3 ||  matriz[2][0] + matriz[2][1]+matriz[2][2] == 3 || matriz[0][0] + matriz[1][0] + matriz[2][0] == 3 ||  matriz[0][1] + matriz[1][1]+matriz[2][1] == 3 ||  matriz[2][0] + matriz[2][1]+matriz[2][2] == 3 ||  matriz[0][0] + matriz[1][1]+ matriz[2][2] == 3 ||  matriz[2][0] + matriz[1][1]+ matriz[10][2] == 3)
                {
                    printf("O jogador 1 Ganhou");
                }
                else if(matriz[0][0] + matriz[0][1]+matriz[0][2] == -3 || matriz[1][0] + matriz[1][1]+matriz[1][2] == -3 ||  matriz[2][0] + matriz[2][1]+matriz[2][2] == -3 || matriz[0][0] + matriz[1][0] + matriz[2][0] == -3 ||  matriz[0][1] + matriz[1][1]+matriz[2][1] == -3 ||  matriz[2][0] + matriz[2][1]+matriz[2][2] == -3 ||  matriz[0][0] + matriz[1][1]+ matriz[2][2] == -3 ||  matriz[2][0] + matriz[1][1]+ matriz[10][2] == -3)
                {
                    printf("O Jogador 2 Ganhou");
                }
                else
                {
                    printf("Empatado");
                }

            }





};



int main()
{
     srand(time(NULL));

     Jogo play;

     play.tabuleiro();

      int cont=0;
      int p=1;
      int jogador=1;

      while (cont++ < 100 && p==1) {

          play.jogada(jogador);
          play.imprime();
          play.valida();

            if(jogador == 1)
            {
                jogador = -1;
            }
            else if(jogador == -1)
            {
                jogador = 1;
            }



        cout<<"\nDigite 1 para continuar ou qualquer outro numero para sair \n";
        cin>>p;

       system("CLS");// Limpa a tela no windows

    }

}
