#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
#include <string.h>
						
#define SU 65 							/* Freccia su */
#define GIU 66 						    /* Freccia giu */
#define SINISTRA 68					    /* Freccia sinsitra */
#define DESTRA 67					    /* Freccia destra */
#define SPACE ' '						/* Barra spazio */
#define MAXX_R 35 				  		/* Numero di colonne dello schermo */
#define MAXY_R 30						/* Numero di righe dello schermo */

typedef struct{
  int x;
  int y;
}pos;

typedef struct{
  pos *pac;
  pos *gost;
  int num_ghost;
}pos_A;

typedef struct{
	int x;
	int y;
	int vivo;
	char dir;
	int ready;
	int id;
	int x_old;
  	int y_old;
	pthread_t id_t;
	int checked; 
	int t_vivo;
}pos_B;

typedef struct{
  int xn;
  int yn;
  int vivo;
  int id;
  char chi;
  int x_old;
  int y_old;

}pos_C;

extern char ring[MAXX_R][MAXY_R];

extern int num_ghost;
extern int num_vite;
extern int PASSO;									/* Entita spostamento */
extern int punti;
extern int punti_caramelloni;
extern int numero_caramelline;
extern int punti_caramelline;
extern pos pos_caramelloni[3];
extern pos *caramelline;
extern pthread_mutex_t mutex;						/*creo il semaforo*/
extern pos_B *BBP;
extern int buff_size;
extern pos_C *BFC;
extern int buffC_size;
extern int id_personaggi;
extern int morte;
extern pthread_t id_bulli[4000];
extern int id_bulli_dim;

void * pacman(void * parametri);
void pacmanMove(pos *pos_pacman);
void BBPadd(pos_B proiettile);
void BBPcut(int pos);
pos_B* BBPinit();
int BBPricerca(pos_B proiettile,int i);
pos_B incrementaProiettile(pos_B proiettile);
void * Shot(void *parametri);
int BBPfindID(int id);
void BFCaggiorna(pos_C *pg);
int BFCconfornta(pos_C pg,int i);
pos_C BFCfindID(int id, int *index);
pos_C* BFCinit();
void BFCadd(pos_C pg);
void trigger(pos_C* pg);
void BBPaggiorna(pos_B proiettile);

void scriviLog(int msg, char* nome);
void scriviLogBull(int x,int y, char* nome, char direzione, int id,int indice);

