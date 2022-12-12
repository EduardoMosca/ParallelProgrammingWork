#include "banheiro.h"

int numero_boxes = 0;
int genero = 0;
int ocupado = 0;

void set_numero_boxes(int numero)
{
  numero_boxes = numero;
}

int get_numero_boxes()
{
  return numero_boxes;
}

void set_genero_atual(int genero_atual)
{
  genero = genero_atual;
}

int get_genero_atual()
{
  return genero;
}

bool box_ocupado()
{
  if (ocupado < numero_boxes)
  {
    ocupado++;
  }
  else
    return false;
  return true;
}

void desocupar_box()
{
  if (ocupado > 0)
    ocupado--;
}

bool vazio()
{
  return (ocupado == 0) ? (true) : (false);
}