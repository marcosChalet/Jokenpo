#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "screen.h"
#include "definicoes.h"

void erro_arq(FILE** fp)
{
	/*
	 * caso dê erro ao abrir o arquivo, tenta cria-lo
	 * e verificar se deu erro novamente.
	 */

	if((*fp) == NULL){

		(*fp) = fopen(NOME_ARQUIVO, "w");
		if((*fp) == NULL){
			printf("Erro na abertura do arquivo!\n");
			exit(0);
		}
		fclose((*fp));

		(*fp) = fopen(NOME_ARQUIVO, "r");
	}

}

ptr_player carregar_jogador() //carrega ou cria um player.
{
	/*
	 * O arquivo está organizado linha a linha com a estrutura:
	 * nome
	 * score
	 *	
	 * nome
	 * score
	 * .
	 * .
	 * .
	 * nome
	 * score
	 *
	 * Ou seja, cada jogador salvo ocupará duas linhas de conteúdo
	 * com nome e escore, respectivamente, separadas por uma linha
	 * em branco.
	 */

	ptr_player player = malloc(sizeof(player));
	char apelido[BITS_NOME];
	char buf[BITS_NOME];
	int controle_arq = 0; /* verifica se o nick foi achado.	*/
	FILE* fp = fopen(NOME_ARQUIVO, "r");
	erro_arq(&fp);

	tela_pegar_usuario(apelido);

	while(fscanf(fp, "%s", buf) != EOF){ /* ao achar o nickname no arquivo, copia os dados para a estrutura. */
		if(strcmp(apelido, buf) == 0){
			player->nome = malloc(strlen(buf)+1);
			strcpy(player->nome, buf);
			
			if(!fscanf(fp, "%s", buf))
				exit(0);
			
			player->score = atoi(buf);
			controle_arq = 1;
			break;	
		}
	}

	if(controle_arq != 1){ /* caso ainda o nickname ainda não esteja contido no arquivo. */
		player->nome = malloc(strlen(apelido)+1);
		strcpy(player->nome, apelido);
		player->score = INICIO_SCORE;
	}

	fclose(fp);

	return player;
}

void save_game(ptr_player player)
{
	/* A variável pos_modificar controla o local em que deve
	 * ser modificado o score. Note que caso não ache o player
	 * haverá -1 atribuído à variável, ondicando que deve ser
	 * criado um novo player.
	 */

	ptr_player lista_players = malloc(sizeof(ptr_player) * MAX_LISTA_USUARIOS);
	int pos_modificar = -1, qtd = 0, i = 0;
	char buf[BITS_NOME];
	FILE* fp = fopen(NOME_ARQUIVO, "r");

	while(fscanf(fp, "%s", buf) != EOF){ //carrega em uma lista os dados salvos no arquivo e guarda a posição do player a ser alterado.
		if(strcmp(player->nome, buf) == 0){ //guarda a posição a ser alterada.
			pos_modificar = qtd;
		}

		lista_players[qtd].nome = malloc(strlen(buf)+1);
		strcpy(lista_players[qtd].nome, buf);

		if(!fscanf(fp, "%s", buf))
			exit(0);
		
		lista_players[qtd].score = atoi(buf);
		qtd++;
	}

	fclose(fp);

	if(pos_modificar == -1){ //caso o player não seja encontrado.
		lista_players[qtd].nome = malloc(strlen(player->nome)+1);
		strcpy(lista_players[qtd].nome, player->nome);
		lista_players[qtd].score = player->score;
		qtd++;
	}
	else{ //atualizando o score do player.
		lista_players[pos_modificar].score = player->score; 
	}

	//salvando no arquivo a nova lista com os dados atualizados.
	fp = fopen(NOME_ARQUIVO, "w");
	if(fp == NULL){
		printf("Erro ao abrir arquivo!\n\n");
		exit(0);
	}

	while(i < qtd){ //salvando os dados atualizados no arqivo.
		fprintf(fp, "%s\n", lista_players[i].nome);
		fprintf(fp, "%d\n\n", lista_players[i].score);
		i++;
	}
	fclose(fp);

	for(int i = 0; i < qtd; i++){
		free(lista_players[i].nome);
	}

	free(lista_players);
	lista_players = NULL;
}

