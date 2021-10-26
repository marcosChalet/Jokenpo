#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definicoes.h"
#include "screen.h"

void sort_num(Tipo_jogada* jogada) //sorteia uma jogada para a jogada da máquina.
{
	(*jogada) = (Tipo_jogada)(rand() % QTD_TIPO_JOGADA);
}

char* mostrar_jogada(Tipo_jogada jogada)
{
	switch (jogada) {
		case PEDRA:		return "Pedra"  ;
		case PAPEL: 	return "Papel"  ;
		case TESOURA: return "Tesoura";
	}

	return NIL;
}

void vez_maquina(Tipo_jogada* jogada) //organiza a jogada da máquina.
{
	sort_num(jogada);
}

void vez_player(Tipo_jogada* jogada) //recebe a jogada do player.
{
	tela_pegar_jogada(jogada);
}

void ajustar_score(int* score, Ajuste_score result_jogada) //ajusta o score a cada jogada.
{
	switch (result_jogada) { //atribui ou retira pontos do player.
		case VENCEU: (*score) += PONTOS_POR_VITORIA; break;
		case PERDEU: (*score) -= PONTOS_POR_DERROTA; break;
	}

	if((*score) < 0){
		printf("Fim de jogo!\n\n");
		exit(0);
	}
}

char* vencedor_partida(ptr_player player, Tipo_jogada jogada_player, Tipo_jogada jogada_maquina) //define o vencedor da partida.
{
	if(jogada_player == jogada_maquina)
		return MSG_EMPATADO;

	else if(jogada_player == PEDRA){
		if(jogada_maquina == TESOURA){
			ajustar_score(&(player->score), VENCEU);
			return MSG_VENCEDOR;
		}
		else{
			ajustar_score(&(player->score), PERDEU);
			return MSG_PERDEDOR;
		}
	}

	else if(jogada_player == PAPEL){
		if(jogada_maquina == PEDRA){
			ajustar_score(&(player->score), VENCEU);
			return MSG_VENCEDOR;
		}
		else{
			ajustar_score(&(player->score), PERDEU);
			return MSG_PERDEDOR;
		}
	}

	else if(jogada_player == TESOURA){
		if(jogada_maquina == PAPEL){
			ajustar_score(&(player->score), VENCEU);
			return MSG_VENCEDOR;
		}
		else{
			ajustar_score(&(player->score), PERDEU);
			return MSG_PERDEDOR;
		}
	}
	return NIL;
}
