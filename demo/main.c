#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "screen.h"
#include "definicoes.h"
#include "arq_banco.h"

void guardar_resumo_rodada(int score, struct_res** resultados, Tipo_jogada jogada_player,\
Tipo_jogada jogada_maquina, char* vencedor, int qtd_jogadas)
{
	resultados[qtd_jogadas] = malloc(sizeof(struct_res));

	(resultados[qtd_jogadas])->jog_player  = jogada_player;
	(resultados[qtd_jogadas])->jog_maquina = jogada_maquina;
	(resultados[qtd_jogadas])->num_jogadas = qtd_jogadas;
	(resultados[qtd_jogadas])->score       = score;
	(resultados[qtd_jogadas])->resultado   = malloc(strlen(vencedor)+1);
	strcpy((resultados[qtd_jogadas])->resultado, vencedor);
}

int main(){

	srand(time(NULL));
	Tipo_jogada jogada_maquina;
	Tipo_jogada jogada_player;
	struct_res** resultados = (struct_res**)malloc(sizeof(struct_res*) * ROUND_DURACAO);
	
	char* vencedor;
	int qtd_jogadas = -1;

	ptr_player player = carregar_jogador();

	while(true){
	
		qtd_jogadas++;
		if(qtd_jogadas == ROUND_DURACAO)
			break;

		vez_player(&jogada_player);
		vez_maquina(&jogada_maquina);
		vencedor = vencedor_partida(player, jogada_player, jogada_maquina);
		tela_mostrar_jogada(player, jogada_player, jogada_maquina, vencedor, qtd_jogadas);
		guardar_resumo_rodada(player->score, resultados, jogada_player, jogada_maquina, vencedor, qtd_jogadas);
	}

	save_game(player);
	tela_fim_jogo();
	tela_resultado_jogadas(resultados);

	return 0;
}
