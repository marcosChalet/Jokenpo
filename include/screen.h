#ifndef SCREEN_H
#define SCREEN_H

typedef enum   Tipo_jogada 	Tipo_jogada;
typedef enum   Ajuste_score Ajuste_score;
typedef struct struct_res   struct_res;
typedef struct player* 			ptr_player;

void tela_pegar_usuario(char* apelido);
void tela_pegar_jogada(Tipo_jogada* jogada);
void tela_mostrar_jogada(ptr_player player, Tipo_jogada jogada_player, Tipo_jogada jogada_maquina, char* vencedor, int qtd_jogadas);
void tela_fim_jogo();
void tela_resultado_jogadas(struct_res** resultados);

#endif
