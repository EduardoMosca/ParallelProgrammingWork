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

#endif