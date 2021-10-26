#ifndef DEFINICOES_H
#define DEFINICOES_H

typedef enum Tipo_jogada{
	PEDRA,
	PAPEL,
	TESOURA
}Tipo_jogada;

typedef enum Ajuste_score{
	PERDEU,
	VENCEU
}Ajuste_score;


typedef struct player* ptr_player;
typedef struct player{
	char* nome;
	int 	score;
}player;

typedef struct struct_res{
	Tipo_jogada jog_player;
	Tipo_jogada jog_maquina;
	int   num_jogadas;
	int   score;
	char* resultado;
}struct_res;

#define QTD_TIPO_JOGADA 3
#define ROUND_DURACAO 5
#define NOME_ARQUIVO "./doc/save.txt"
#define NIL "NIL"
#define BITS_NOME 20
#define INICIO_SCORE 50
#define MAX_LISTA_USUARIOS 100
#define PONTOS_POR_VITORIA 10
#define PONTOS_POR_DERROTA 10
#define MSG_VENCEDOR "Você Venceu!"
#define MSG_PERDEDOR "Você Perdeu!"
#define MSG_EMPATADO "Vocẽ Empatou"

#endif
