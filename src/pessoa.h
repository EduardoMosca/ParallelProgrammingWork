#ifndef _PESSOA_H_
#define _PESSOA_H_
#include "banheiro.h"
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct
{
  int id_pessoa;
  int genero_pessoa;
} pessoa_t;

void set_id(pessoa_t *pessoa, int id);
int get_id(pessoa_t *pessoa);

void set_genero(pessoa_t *pessoa, int genero);
int get_genero(pessoa_t *pessoa);

bool EnterRestroom(pessoa_t *pessoa);
void GetStall(pessoa_t *pessoa, Uint32 *tempo_final, SDL_mutex *mutex_dentro_banheiro, SDL_mutex *mutex_fora_banheiro);

#endif
