#ifndef ARQ_BANCO_H
#define ARQ_BANCO_H

/* Corrige/termina caso haja erro na abertura do arquivo. */
void  erro_arq(FILE** fp);

/* Busca e carrega ou cria o player do arquivo para uma lista. */
ptr_player carregar_jogador();

/* Salva a lista de players no arquivo. */
void  save_game(ptr_player player);

#endif
