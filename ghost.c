#include "ghost.h"

void * ghost(void *parametri){		
	int *id_ = (int*) parametri;/*Converto la mia variabile in input*/
	int dx,dy,rand_try;
	int i = 0;
	int id = *id_;
	pos* pacman = (pos*) malloc(sizeof(pos));;
	pos* pos_gost = (pos*) malloc(sizeof(pos));
	int sulla_caramella = 0;
	pos_C* pos_char = &(BFC[id]);

	pos_gost->x = pos_char->xn;
	pos_gost->y = pos_char->yn;
	pos_char->id = id;
	pos_char->chi = 'M';

	scriviLog(pos_char->id,"Sono nato Fantasmino:");

	usleep(500);

/*	pthread_mutex_lock(&mutex);//Inizio sezione critica
	mvaddch(pos_gost->y,pos_gost->x,'M');
	refresh();
	pthread_mutex_unlock(&mutex);//Fine sezione critica
*/
    while(num_vite>0){
	
		pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
		pacman->x = BFC[0].xn;
		pacman->y = BFC[0].yn;
		pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

		for(i = 0; i < numero_caramelline+1; i++){
			if(ring[pos_gost->y][pos_gost->x] == '.'){
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
			refresh();
			sulla_caramella = 0;
		    pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
		}
		
		pos_char->x_old = pos_gost->x;
		pos_char->y_old = pos_gost->y;

		pos_gost->x = pos_char->xn;
		pos_gost->y = pos_char->yn;	


		*pos_gost = Passo_ghost(pos_gost , pacman);

		pos_char->xn = pos_gost->x;
		pos_char->yn = pos_gost->y;	

		/*if(pos_char->xn  != pos_char->x_old  || pos_char->yn  != pos_char->y_old){
			BFCaggiorna(pos_char);
		}*/

		
		rand_try = rand()%97;

		if(rand_try == 0){
			trigger(pos_char);
		}

/*		pthread_mutex_lock(&mutex);//Inizio sezione critica
		mvaddch(pos_gost->y,pos_gost->x,'M');
		refresh();
		pthread_mutex_unlock(&mutex);//Fine sezione critica
*/
    }

}

pos Passo_ghost(pos *ghost, pos *pacman){

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
			return *ghost;	
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
			return *ghost;
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


	return *ghost;
	
}










