#include "pacman.h"

void * pacman(void * parametri){
    pos * pos_pacman = (pos*) parametri;
    pos_pacman->x=MAXX_R/2;
    pos_pacman->y=MAXY_R/2;
	int i = 0;

    pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
    mvaddch(pos_pacman->y,pos_pacman->x,'C');
    refresh();
    pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

	while(num_vite>0)
	{
		char c;

	   	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
		mvaddch(pos_pacman->y,pos_pacman->x,'C');
		refresh();
		pthread_mutex_unlock(&mutex);/*Fine sezione critica*/		
		
		c=getch();

		pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
		mvaddch(pos_pacman->y,pos_pacman->x,' ');
		pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

			switch(c){// Mi sposto in base al tasto che ho premu to
					 // controllando ogni volta di non uscire dai limiti
				case SU:
					if(pos_pacman->y>1){
						pos_pacman->y-=1;
					}

					if(ring[pos_pacman->y][pos_pacman->x]  == '#'){
						pos_pacman->y+=1;
					}

					break;

				case GIU:
					if(pos_pacman->y<MAXX_R-1){
						pos_pacman->y+=1; 
					}

					if(ring[pos_pacman->y][pos_pacman->x]  == '#'){
						pos_pacman->y-=1;
					}
					break;

				case SINISTRA:
					if(pos_pacman->x>1){
						pos_pacman->x-=1;
					}

					if(ring[pos_pacman->y][pos_pacman->x] == '#'){
						pos_pacman->x+=1;
					}	

					break;

				case DESTRA:

					if(pos_pacman->x < MAXY_R-1){
					pos_pacman->x+=1;
					}


					if(ring[pos_pacman->y][pos_pacman->x] == '#'){
						pos_pacman->x-=1;
					}
					break;

		}

		for(i = 0; i <3 ; i++){
			if(pos_caramelloni[i].x == pos_pacman->y  && pos_caramelloni[i].y == pos_pacman->x ){//Caramellone preso 
				punti += punti_caramelloni;
				pos_caramelloni[i].x = MAXX_R*2;
				pos_caramelloni[i].y = MAXY_R*2;

			}
		}

		for(i = 0; i < (numero_caramelline + 1); i++ ){
				if(caramelline[i].x == pos_pacman->y  && caramelline[i].y == pos_pacman->x ){			
					punti += punti_caramelline;
					caramelline[i].x = MAXX_R*2;
					caramelline[i].y = MAXY_R*2;
					numero_caramelline--;

			}
		}
		
		pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
		mvaddch(pos_pacman->y,pos_pacman->x,'C');
		refresh();
		pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

	}
}




























