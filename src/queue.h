#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <malloc.h>

typedef struct queue
{
  int value;
  struct queue *next;
} queue;

void start_queue(queue **fila);

void add_queue(int value, queue *fila);

#endif