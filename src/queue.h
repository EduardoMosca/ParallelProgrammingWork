#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <malloc.h>

#define QUEUE_EMPTY -1

typedef struct node
{
  int value;
  struct node *next;
} node;

typedef struct
{
  node *head;
  node *tail;
} queue;

void start_queue(queue *fila);

void add_queue(int value, queue *fila);

void print_queue(queue *fila);

int retorna(int a, int b);

int retorna_tamanho_fila(void);

int erase_queue(queue *fila);

int get_head(queue *fila);

#endif