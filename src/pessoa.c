#include "pessoa.h"

void set_id(pessoa_t *pessoa, int id)
{
  pessoa->id_pessoa = id;
}

int get_id(pessoa_t *pessoa)
{
  return pessoa->id_pessoa;
}

void set_genero(pessoa_t *pessoa, int genero)
{
  pessoa->genero_pessoa = genero;
}

int get_genero(pessoa_t *pessoa)
{
  return pessoa->genero_pessoa;
}

bool EnterRestroom(pessoa_t *pessoa)
{
  if (!vazio() && get_genero_atual() != pessoa->genero_pessoa)
  {
    return false;
  }

  else if (vazio())
  {
    printf("Genero %d entrou!\n", pessoa->genero_pessoa);
    set_genero_atual(pessoa->genero_pessoa);
  }
  return true;
}

void GetStall(pessoa_t *pessoa, Uint32 *tempo_final, SDL_mutex *mutex_dentro_banheiro, SDL_mutex *mutex_fora_banheiro)
{
  while (!box_ocupado())
    ;
  *tempo_final = SDL_GetTicks64();
  printf("Entrou no box pessoa do genero %d\n", get_genero(pessoa));
  SDL_UnlockMutex(mutex_dentro_banheiro);
  SDL_Delay(5000);
  SDL_LockMutex(mutex_fora_banheiro);
  desocupar_box();
  printf("Saiu do box id: %d do genero %d \n", get_id(pessoa), get_genero(pessoa));
  SDL_UnlockMutex(mutex_fora_banheiro);
}