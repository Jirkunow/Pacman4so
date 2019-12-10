#include "ghost.h"

void * ghost(void * parametri){

  pos * pos_gost = (pos*) parametri;/*Converto la mia variabile in input*/
  int dx,dy;
  int sulla_caramella = 0;
  pos_gost->x=15;//La vespa inizierà in una posizione casuale all'interno dello schermo
  pos_gost->y=21;

  pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
  mvaddch(pos_gost->y,pos_gost->x,'M');
  refresh();
  pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

  while(num_vite>0)
  {
	
    usleep(500000);	
    pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
    mvaddch(pos_gost->y,pos_gost->x,' ');
    pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

    switch(rand()%3)
    {
      case 0://se rand%3 mi ha dato 0 non mi sposto in orizzontale
        dx=0;
        break;
      case 1://se rand%3 mi ha dato 1 mi muovo a destra
        dx=PASSO;
        break;
      case 2://se rand%3 mi ha dato 2 mi muovo a sinistra
        dx=-PASSO;
        break;
      default:
        perror("Caso impossibile.\n");
    }

    if(pos_gost->x+dx<1 || pos_gost->x+dx>=MAXX_R){ // Se il movimento mi fa uscire dai limiti inverto la direzione
		dx=-dx;
	}
	
	if(ring[pos_gost->y][pos_gost->x+dx]=='#'){
		dx=-dx;
	}else{
    	pos_gost->x+=dx;                                      
	}

    switch(rand()%3)
    {
      case 0://se rand%3 mi ha dato 0 non mi sposto in verticale
        dy=0;
        break;
      case 1://se rand%3 mi ha dato 1 mi muovo in basso
        dy=PASSO;
        break;
      case 2://se rand%3 mi ha dato 2 mi muovo in alto
        dy=-PASSO;
        break;
      default:
        perror("Caso impossibile.\n");
    }

    if(pos_gost->y+dy<1 || pos_gost->y+dy>=MAXY_R){// Se il movimento mi fa uscire dai limiti inverto la direzione
		dy=-dy;
    }
                                      
	if(ring[pos_gost->y+dy][pos_gost->x]=='#'){
		dy=-dy;
	}else{
		pos_gost->y+=dy;
	}

    pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
    mvaddch(pos_gost->y,pos_gost->x,'M');
    refresh();
    pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

  }

}
