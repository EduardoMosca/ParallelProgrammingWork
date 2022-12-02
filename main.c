// cmake .. -G "MinGW Makefiles"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>
#include <SDL.h>

int cont = 0;

SDL_sem *lock;

void print(void *args)
{
  while (cont < 1000000000 - 1)
  {
    SDL_SemWait(lock);
    cont++;
    // SDL_UnlockMutex(lock);
    // printf("Valor atual thread 1: %d\n", cont);
    SDL_SemPost(lock);
  }
}

void print2(void *args)
{
  while (cont < 1000000000 - 1)
  {
    SDL_SemWait(lock);
    cont++;
    // SDL_UnlockMutex(lock);
    // printf("Valor atual thread 2: %d\n", cont);
    SDL_SemPost(lock);
  }
}

#ifdef __linux__
int main(int argc, char *argv[])
#elif _WIN32
int SDL_main(int argc, char *argv[])
#endif
{
  srand(time(NULL));
  int people[60];

  SDL_Thread *thread1, *thread2;
  lock = SDL_CreateSemaphore(1);
  thread1 = SDL_CreateThread((void *)print, "sum1", (void *)NULL);
  thread2 = SDL_CreateThread((void *)print2, "sum2", (void *)NULL);
  SDL_WaitThread(thread1, NULL);
  SDL_WaitThread(thread2, NULL);
  // SDL_DestroyMutex(lock);
  SDL_DestroySemaphore(lock);
  printf("O valor e: %d\n", cont);
  return 0;
}