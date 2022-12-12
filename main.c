// cmake .. -G "MinGW Makefiles"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>
#include <SDL.h>
#include "src/queue.h"
#include "src/banheiro.h"
#include "src/pessoa.h"

#define NUMERO_DE_GENEROS 3
#define NUMERO_DE_PESSOAS 60
#define NUMERO_DE_BOXES 1

SDL_mutex *mutex_fora_banheiro = NULL;
SDL_mutex *mutex_dentro_banheiro = NULL;
SDL_mutex *acesso_fila = NULL;

queue fila;
int *numero_pessoas = NULL;
unsigned int *tempo_de_espera = NULL;

void funcao_pessoa(void *thread_id)
{
  int *id = (int *)thread_id;

  int genero = -1;
  clock_t inicio, tempo_final;
  do
  {
    genero = rand() % NUMERO_DE_GENEROS;
    if (numero_pessoas[genero] > 0)
      numero_pessoas[genero]--;
    else
      genero = -1;
  } while (genero == -1);

  inicio = SDL_GetTicks64();
  pessoa_t pessoa;
  set_id(&pessoa, *id);
  set_genero(&pessoa, genero);
  printf("Pessoa com ID %lu de genero %d entrou na fila\n", get_id(&pessoa), genero);

  // SDL_LockMutex(acesso_fila);
  print_queue(&fila);
  // SDL_UnlockMutex(acesso_fila);

  while (get_id(&pessoa) != fila.head->value)
    ;

  SDL_LockMutex(mutex_dentro_banheiro);

  while (!EnterRestroom(&pessoa))
    ;

  printf("Pessoa de ID %lu com genero %d saiu da fila\n", get_id(&pessoa), get_genero(&pessoa));

  // SDL_LockMutex(acesso_fila);
  erase_queue(&fila);
  // SDL_UnlockMutex(acesso_fila);

  print_queue(&fila);

  GetStall(&pessoa, &tempo_final, mutex_dentro_banheiro, mutex_fora_banheiro);

  tempo_de_espera[get_genero(&pessoa)] += (tempo_final - inicio) / 1000;
}

#ifdef __linux__
int main(int argc, char *argv[])
#elif _WIN32
int SDL_main(int argc, char *argv[])
#endif
{
  start_queue(&fila);
  set_numero_boxes(NUMERO_DE_BOXES);
  mutex_fora_banheiro = SDL_CreateMutex();
  mutex_dentro_banheiro = SDL_CreateMutex();
  acesso_fila = SDL_CreateMutex();

  SDL_Thread *thread_pessoas[NUMERO_DE_PESSOAS];
  Uint64 inicio, fim;

  Uint64 tempo_total = 0;

  srand(time(NULL));

  numero_pessoas = (int *)calloc(NUMERO_DE_GENEROS, sizeof(int));
  tempo_de_espera = (unsigned int *)calloc(NUMERO_DE_GENEROS, sizeof(unsigned int));

  for (int i = 0; i < NUMERO_DE_GENEROS; i++)
  {
    numero_pessoas[i] = NUMERO_DE_PESSOAS / NUMERO_DE_GENEROS;
    tempo_de_espera[i] = 0;
  }

  inicio = SDL_GetTicks64();
  for (int i = 0; i < NUMERO_DE_PESSOAS; i++)
  {
    add_queue(i, &fila);
    thread_pessoas[i] = SDL_CreateThread((void *)funcao_pessoa, "funcao_pessoa", (void *)&i);

    SDL_Delay(1000);
  }

  for (int i = 0; i < NUMERO_DE_PESSOAS; i++)
  {
    SDL_WaitThread(thread_pessoas[i], NULL);
  }

  fim = SDL_GetTicks64();

  tempo_total = (fim - inicio) / 1000;

  puts("");

  printf("Numero de pessoas: %d\n", NUMERO_DE_PESSOAS);
  printf("Total de boxes: %d\n", NUMERO_DE_BOXES);
  printf("O tempo total de execucao do programa foi: %llu minutos e %llu segundos\n", (tempo_total / 60), (tempo_total - (tempo_total / 60) * 60));
  printf("Quantidade de pessoas por genero: %d\n", NUMERO_DE_PESSOAS / NUMERO_DE_GENEROS);
  printf("Tempo de espera por genero: \n");
  for (int i = 0; i < NUMERO_DE_GENEROS; i++)
  {
    printf(" | %d: %lu segundos total ", i, tempo_de_espera[i]);
    printf("(cerca de %lu segundos por pessoa)\n", (tempo_de_espera[i] / (NUMERO_DE_PESSOAS / NUMERO_DE_GENEROS)));
  }
  int tempo_de_uso = 0;

  printf("Taxa de ocupacao do box: %.2lf\n", ((5.0 * NUMERO_DE_PESSOAS) / (tempo_total * NUMERO_DE_BOXES)));

  // SDL_DestroySemaphore(mutex_fora_banheiro);
  // SDL_DestroySemaphore(mutex_dentro_banheiro);
  SDL_DestroyMutex(mutex_fora_banheiro);
  SDL_DestroyMutex(mutex_dentro_banheiro);
  SDL_DestroyMutex(acesso_fila);
  free(numero_pessoas);
  free(tempo_de_espera);
  return 0;
}