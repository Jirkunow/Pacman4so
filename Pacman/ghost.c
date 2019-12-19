#include "ghost.h"

int num_fantasmi = 4;

void * ghost(void * parametri){

  pos_A * pos_char = (pos_A*) parametri;/*Converto la mia variabile in input*/
  int dx,dy;
  int i = 0;
  pos* pacman = pos_char->pac;
  pos* pos_gost = pos_char->gost;
  int sulla_caramella = 0;
  pos_gost->x=15;//Il fantasma inizierà al centro del ring 
  pos_gost->y=21;

  pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
  mvaddch(pos_gost->y,pos_gost->x,'M');
  refresh();
  pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

  while(num_vite>0){

	for(i = 0; i < numero_caramelline+1; i++){
		if(caramelline[i].x == pos_gost->y  && caramelline[i].y == pos_gost->x ){
				sulla_caramella = 1;
		}
	}
	
    usleep(500000);	
    pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
    mvaddch(pos_gost->y,pos_gost->x,' ');
    pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

    if(sulla_caramella == 1){
        pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
    	mvaddch(pos_gost->y,pos_gost->x,'.');
		sulla_caramella = 0;
        pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
	}


	pos_gost = Passo_ghost(pos_gost , pacman);

    pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
    mvaddch(pos_gost->y,pos_gost->x,'M');
    refresh();
    pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

  }

}

pos * Passo_ghost(pos *ghost, pos *pacman){

	char visualizza_errore;
	int codice_errore = 1;
	int rand_try,dp;
	
	if(ghost->x == pacman->x){ //controllo se pacman ed il fantasmino sono sulla stessa linea 
		if((ghost->y - pacman->y) < 0){
			dp = 1;
		}else{ 
			dp = -1;
		}
		if(ring[ghost->y+dp][ghost->x]!='#'){
			ghost->y += dp;	
			return ghost;	
		}
	}
	if(ghost->y == pacman->y){
		if((ghost->x - pacman->x) < 0){
			dp = 1;
		}else{ 
			dp = -1;
		}
		if(ring[ghost->y][ghost->x+dp]!='#'){
			ghost->x += dp;	
			return ghost;
		}
			
	}

	while(codice_errore){ //Se arrivo qua vuol dire che pacman ed il fantasmino non sono sulla stessa linea allora mi muovo a caso

		rand_try = rand()%4;

		switch(rand_try){
		  case 0://se rand%4 mi ha dato 0 mi sposto verso il basso
		    ghost->x++;
		    break;
		  case 1://se rand%4 mi ha dato 1 mi sposto verso l'alto
		    ghost->x--;
		    break;
		  case 2://se rand%4 mi ha dato 2 mi sposto verso destra
		    ghost->y++;
		    break;
		  case 3://se rand%4 mi ha dato 3 mi sposto verso sinistra
			ghost->y--;
			break;
		  default:
				visualizza_errore = rand_try + 48;
			    pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
				mvaddch(0,70,visualizza_errore);
				refresh();
				pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
		    perror("Caso impossibile.\n");
    	}
		
		switch(rand_try){//controllo collisioni 

			case 0:
				if(ring[ghost->y][ghost->x]=='#'){
					ghost->x--;		
					codice_errore = 1;			
				}else{
					codice_errore = 0;
					}
				break;
			case 1:
				if(ring[ghost->y][ghost->x]=='#'){
					ghost->x++;	
					codice_errore = 1;		
				}else{
					codice_errore = 0;
					}
				break;
			case 2:
				if(ring[ghost->y][ghost->x]=='#'){
					ghost->y--;	
					codice_errore = 1;				
				}else{
					if(ghost->x < 0 || ghost->x > MAXX_R){
						ghost->x = -ghost->x;
					}
					
					codice_errore = 0;
					}
				break;
			case 3:
				if(ring[ghost->y][ghost->x]=='#'){
					ghost->y++;	
					codice_errore = 1;				
				}else{
					if(ghost->x < 0 || ghost->x > MAXX_R){
						ghost->x = -ghost->x;
					}
					codice_errore = 0;
					}
				break;
		}		
	}
	return ghost;
	
}










