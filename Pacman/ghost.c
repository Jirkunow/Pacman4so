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
    /*switch(rand()%3)
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
	}*/

	

	

    pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
    mvaddch(pos_gost->y,pos_gost->x,'M');
    refresh();
    pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

  }

}


pos * Passo_ghost(pos *ghost, pos *pacman){

	pos distanza;
	float modulo_n = 0;
	float modulo_n2 = 0;
	ERRORE codice_errore = {VAR_MV_GHOST_INIT, 1};

	distanza.x = ghost->x - pacman->x;
	distanza.y = ghost->y - pacman->y;

	modulo_n = sqrt((float)((float)distanza.x * (float)distanza.x) - ((float)distanza.y * (float)distanza.y));

	do{
		if(codice_errore.cod != 0){
			distanza.x = ghost->x - pacman->x +1;
			modulo_n2 =  sqrt((float)((float)distanza.x * (float)distanza.x) - ((float)distanza.y * (float)distanza.y));

			if(modulo_n2 >= modulo_n && codice_errore.cod != 1 ){
				distanza.x = ghost->x - pacman->x -2;
				modulo_n2 =  sqrt((float)((float)distanza.x * (float)distanza.x) - ((float)distanza.y * (float)distanza.y));

				if(modulo_n2 >= modulo_n && codice_errore.cod != 2){
					distanza.x = ghost->x - pacman->x;
					distanza.y = ghost->y - pacman->y +1;
					modulo_n2 =  sqrt((float)((float)distanza.x * (float)distanza.x) - ((float)distanza.y * (float)distanza.y));

					if(modulo_n2 >= modulo_n && codice_errore.cod != 3){
						ghost->y--;
						codice_errore.cod = 3;				
					}else{
						switch(rand()%3){
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
					}
				}else{
					ghost->y++;	
					codice_errore.cod = 2;	
				}				
			}else{
				ghost->x--;
				codice_errore.cod = 1;	
			}
		}else{
			ghost->x++;
			codice_errore.cod = 0;	
		}

		switch(codice_errore.cod){

			case 0:
				if(ring[ghost->y][ghost->x]=='#'){
					ghost->x--;		
					codice_errore.fail = 1;			
				}
				break;
			case 1:
				if(ring[ghost->y][ghost->x]=='#'){
					ghost->x++;	
					codice_errore.fail = 1;		
				}
				break;
			case 2:
				if(ring[ghost->y][ghost->x]=='#'){
					ghost->y--;	
					codice_errore.fail = 1;				
				}
				break;
			case 3:
				if(ring[ghost->y][ghost->x]=='#'){
					ghost->y++;	
					codice_errore.fail = 1;				
				}
				break;
		}

	}while(codice_errore.fail);

	return ghost;

}








