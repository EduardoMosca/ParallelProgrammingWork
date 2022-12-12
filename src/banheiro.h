#ifndef _BANHEIRO_H_
#define _BANHEIRO_H_
#include <stdbool.h>

void set_numero_boxes(int numero);
int get_numero_boxes(void);

void set_genero_atual(int genero_atual);
int get_genero_atual(void);

bool box_ocupado(void);

void desocupar_box(void);

bool vazio(void);

#endif