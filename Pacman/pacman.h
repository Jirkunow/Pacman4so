#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
						
#define SU 65 							/* Freccia su */
#define GIU 66 						/* Freccia giu */
#define SINISTRA 68					/* Freccia sinsitra */
#define DESTRA 67					/* Freccia destra */
#define MAXX_R 35 						/* Numero di colonne dello schermo */
#define MAXY_R 30						/* Numero di righe dello schermo */

/*Struttura che identifica la posizione di vespa e contadino*/
typedef struct{
  int x;
  int y;
}pos;

typedef struct{
  pos *pac;
  pos *gost;
}pos_A;

extern char ring[MAXX_R][MAXY_R];

extern int num_vite;
extern int PASSO;									/* Entita spostamento */
extern int punti;
extern int punti_caramelloni;
extern int numero_caramelline;
extern int punti_caramelline;
extern pos pos_caramelloni[3];
extern pos *caramelline ;
extern pthread_mutex_t mutex;/*creo e inizializzo il semaforo*/

void * pacman(void * parametri);








