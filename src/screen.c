#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "definicoes.h"

void tela_pegar_usuario(char* apelido)
{
	printf(" ******* PEDRA, PAPEL OU TESOURA *******\n");
	printf(" *                                     *\n");
	printf(" *                                     *\n");
	printf(" *      Entre com o seu nickname!      *\n");
	printf(" *                                     *\n");
	printf(" *                                     *\n");
	printf(" ***************************************\n -> ");
	if(scanf("%s", apelido) != 1)
		exit(0);
		
	if(system("clear||cls") == -1)
		exit(0);
	
		printf(" Player:  %-30s" , "XXXXXXX");
		printf(" partida %d/%d\n", 0, ROUND_DURACAO);
		printf("       X\t   %s\n", "XXXXXXX");
		printf(" Máquina: %s\n\n", "XXXXXXX");
		
		printf(" SCORE XX\n\n");
	
}

void tela_pegar_jogada(Tipo_jogada* jogada)
{
	printf(" ***************************************\n");
	printf(" * digite:                             *\n");
	printf(" * [1] Pedra                           *\n");
	printf(" * [2] Papel                           *\n");
	printf(" * [3] Tesoura                         *\n");
	printf(" *                                     *\n");
	printf(" ***************************************\n -> ");
	if(scanf("%u", jogada) != 1)
		exit(0);
	
	(*jogada)--;
	if(system("clear||cls") == -1)
		exit(0);
}

void tela_mostrar_jogada(ptr_player player, Tipo_jogada jogada_player, Tipo_jogada jogada_maquina, char* vencedor, int qtd_jogadas)
{

		printf(" Player:  %-30s"  , mostrar_jogada(jogada_player));
		printf(" partida %d/%d\n" , qtd_jogadas+1, ROUND_DURACAO);
		printf("       X\t   %s\n", vencedor);
		printf(" Máquina: %s\n\n" , mostrar_jogada(jogada_maquina));

		printf(" SCORE %d\n\n", player->score);
}

void tela_fim_jogo()
{
	printf(" ***************************************\n");
	printf(" *                                     *\n");
	printf(" *                                     *\n");
	printf(" *           FIM DO JOGO!              *\n");
	printf(" *                                     *\n");
	printf(" *                                     *\n");
	printf(" ***************************************\n");
}

void tela_resultado_jogadas(struct_res** resultados)
{

	/* A função consiste em elencar os resultados em duas colunas
   * seguindo sequencialmente da esquerda para a direita, em or-
	 * dem de jogadas.
	 */

	if(system("clear||cls") == -1)
		exit(0);


	printf(" ############################################# SEUS RESULTADOS #############################################\n");

	
	for(int i = 0; i < ROUND_DURACAO; i += 2){
	
		if(i < ROUND_DURACAO-1){
				printf(" #  *****************************************");
				printf(" %-17s *****************************************  #\n", " ");

				
				//Indica qual foi a jogada do player e em qual partida está.
				//esquerda
				printf(" #  * Player:  %-20s  "  , mostrar_jogada(resultados[i]->jog_player));
				printf("   %d/%d *" , (resultados[i]->num_jogadas)+1, ROUND_DURACAO);
				//direita
				printf(" %-17s * Player:  %-20s  ", " ", mostrar_jogada(resultados[i+1]->jog_player));
				printf("   %d/%d *  #\n #  *" , (resultados[i+1]->num_jogadas)+1, ROUND_DURACAO);

			
				//Indica se venceu ou se perdeu a partida.
				//esquerda
				printf("        X\t   %s %-12s*", resultados[i]->resultado, " ");
				//direita
				printf(" %-17s *        X\t   %s %-8s*  #\n", " ", resultados[i+1]->resultado, " ");

				
				//indica qual foi a jogada da máquina.
				//esquerda
				printf(" #  * Máquina: %-29s*", mostrar_jogada(resultados[i]->jog_maquina));
				//direita
				printf(" %-17s * Máquina: %-29s*  #\n", " ", mostrar_jogada(resultados[i+1]->jog_maquina));


				//só um espaço entre os outros dados e o score.
				//esquerda
				printf(" #  * %-38s*", " ");
				//direita
				printf(" %-17s * %-38s*  #\n", " ", " ");
				
				//indica qual o score após a jogada.
				//esquerda
				printf(" #  * SCORE %-32d*", resultados[i]->score);
				//direita
				printf(" %-17s * SCORE %-32d*  #\n", " ", resultados[i+1]->score);
				
				
				//esquerda
				printf(" #  *****************************************");
				//direita
				printf(" %-17s *****************************************  #\n", " ");
				
				printf(" # %-103s #\n", " ");
				
		}else{

			/*
			 * Quando houver uma quantidade impar de jogadas, entra
			 * aqui para centralizar o resultado da ultima.
			 */

			printf(" #%-30s *****************************************  %-30s #\n", " ", " ");
			printf(" #%-30s * Player:  %-20s", " ", mostrar_jogada(resultados[i]->jog_player));
			printf("   %d/%d   * %-31s #\n" , (resultados[i]->num_jogadas)+1, ROUND_DURACAO, " ");
			printf(" #%-30s *        X\t   %s %-9s* %-31s #\n", " ", resultados[i]->resultado, " ", " ");
			printf(" #%-30s * Máquina: %-29s* %31s #\n", " ", mostrar_jogada(resultados[i]->jog_maquina), " ");
			printf(" #%-30s * %-38s* %31s #\n", " ", " ", " ");
			printf(" #%-30s * SCORE %-32d* %31s #\n", " ", resultados[i]->score, " ");
			printf(" #%-30s *****************************************  %-30s #\n", " ", " ");
			
		}
	
	}
	printf(" ###########################################################################################################\n");

}
