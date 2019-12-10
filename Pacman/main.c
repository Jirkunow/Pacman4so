#include "ghost.h"

void * areaGioco(void * parametri);

int main(){
	int i,j;
	pthread_t pacmanID, gostID, areaGiocoID;
	pos pos_gost,pos_pacman;
	pos_A area;

    srand(time((time_t*)NULL));
    initscr();
    noecho();
    curs_set(0);

	area.pac = &pos_pacman;
	area.gost = &pos_gost;

	pthread_create(&pacmanID,NULL,&pacman,(void*)&pos_pacman);
	pthread_create(&gostID,NULL,&ghost,(void*)&pos_gost);
	pthread_create(&areaGiocoID,NULL,&areaGioco,(void*)&area);
	
	while(num_vite > 0);
	refresh();
	clear();
	mvprintw(MAXY_R/2,MAXX_R/2,"GAME OVER");
	usleep(5000000);
	endwin();
}

void * areaGioco(void * parametri){
	int i,j;
	int cambio_caramelloni = 0;
	pos_A * posizioni = (pos_A *) parametri;



  	pthread_mutex_lock(&mutex);
	caramelline = (pos*) malloc(sizeof(pos*));

  	for(i = 0 ; i< MAXX_R ; i++){//Disegno il ring 
		for(j = 0 ; j < MAXY_R ; j++){
			mvaddch(i,j,ring[i][j]);
     		refresh();
			if(ring[i][j] == '.'){
				caramelline[numero_caramelline].x = i;
				caramelline[numero_caramelline].y = j;
				numero_caramelline++;
				caramelline = (pos*) realloc(caramelline,sizeof(pos*)*(numero_caramelline +1));
			}
			usleep(700);
		}
  	}
  	pthread_mutex_unlock(&mutex);
	
	time_t tempo_salvato = time(NULL);	
	
	while (num_vite>0){ //inizio ciclo di gioco

		if((time(NULL)-tempo_salvato) > 10){                           //Se sono passati dieci secondi... è Giusto? 

			for(i=0;i<3;++i){                      
				pthread_mutex_lock(&mutex);
				mvaddch(pos_caramelloni[i].x,pos_caramelloni[i].y,' ');//cancello i vecchi caramelloni
				pthread_mutex_unlock(&mutex);
		 	}

			cambio_caramelloni = 1;
	  		
			for(i = 0; i<3;i++){
				do{
				
					pos_caramelloni[i].y = rand()%MAXY_R;
					pos_caramelloni[i].x = rand()%MAXX_R;
				
				}while(  !(
							 (ring[pos_caramelloni[i].x][pos_caramelloni[i].y] != '#') &&        //sin che sta sul bordo
							 (pos_caramelloni[i].y < MAXX_R) && 
							 (pos_caramelloni[i].x < MAXY_R) &&                                  //Sin che è fuori dal ring
							 (pos_caramelloni[i].y > 0) &&                                      
							 (pos_caramelloni[i].x > 0)                                          //Sin che sta fuori dal ring ma in alto
						  )											                             
                      );                                   
			}

			for(i=0;i < 3;++i){
				pthread_mutex_lock(&mutex);
				mvaddch(pos_caramelloni[i].x,pos_caramelloni[i].y,'$');
				pthread_mutex_unlock(&mutex);
		  	}

		  	tempo_salvato=time((time_t*)NULL);//Mi salvo il tempo in cui le ho generate		
		}

		if(cambio_caramelloni == 1){
			time_t tempo_salvato = time(NULL);
			cambio_caramelloni = 0;	
		}		

		/*controllo la collisione fra pacman e fantasma*/
		if((posizioni->pac->x == posizioni->gost->x) && posizioni->pac->y == posizioni->gost->y){
			num_vite--;
			posizioni->pac->x=MAXX_R/2;
    		posizioni->pac->y =MAXY_R/2;
		}



		pthread_mutex_lock(&mutex);
		mvprintw(0,MAXY_R+3,"Vite: %d",num_vite);/*Stampo il numero di vite*/
		mvprintw(1,MAXY_R+3,"punti: %d",punti);/*Stampo il numero di vite*/
	  	curs_set(0);
	  	refresh();
		pthread_mutex_unlock(&mutex);
		usleep(50000);
    }; /* ciclo finchè pacman non perde tutte le vite */
}
