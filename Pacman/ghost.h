#include "pacman.h"

#define VAR_MV_GHOST_INIT 7

typedef struct{
  int cod;
  int fail;
}ERRORE;

extern int num_fantasmi;

void * ghost(void * parametri);
pos * Passo_ghost(pos *ghost, pos *pacman);
