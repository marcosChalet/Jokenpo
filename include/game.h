#ifndef GAME_H
#define GAME_H

typedef enum   Tipo_jogada 	Tipo_jogada;
typedef enum   Ajuste_score Ajuste_score;
typedef struct player* 			ptr_player;
typedef struct struct_res   struct_res;

/* Sorteia uma jogada para a máquina. */
void  sort_num(Tipo_jogada* jogada);

/* Retorna uma string referente à jogada */
char* mostrar_jogada(Tipo_jogada jogada);

/* Cria uma jogada para a máquina. */
void  vez_maquina(Tipo_jogada* jogada);

/* Cria uma jogada para o player. */
void  vez_player(Tipo_jogada* jogada);

/* Incrementa ou retira pontos a cada jogada do player. */
void  ajustar_score(int* score, Ajuste_score result_jogada);

/* Lógica do jogo para definir o vencedor da jogada. */
char* vencedor_partida(ptr_player player, Tipo_jogada jogada_player, Tipo_jogada jogada_maquina);

#endif
