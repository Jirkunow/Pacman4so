#include "ghost.h"

void * areaGioco(void * parametri);
void gestoreProiettili(pos_C *posizioni);
void stampaRing();
time_t stampaCaramelloni(time_t tempo_salvato);
void stampante(pos_C *posizioni);


int main(){
	int i,j;
	pthread_t pacmanID, areaGiocoID;
    pthread_t ghostID[5];
	pos pos_pacman;
	pos_C ghst;

    srand(time((time_t*)NULL));
    initscr();
    noecho();
    curs_set(0);
	BBP = BBPinit();
	BFC = BFCinit();

	pthread_create(&pacmanID,NULL,&pacman,(void*)&pos_pacman);
	
	for(i=1;i<4;i++){
		num_ghost++;

		pthread_create(&(ghostID[i-1]),NULL,&ghost,(void*)&(BFC[i]));

	}


	pthread_create(&areaGiocoID,NULL,&areaGioco,(void*)BFC);
	
	while(num_vite > 0);
	clear();
	clear();
	clear();
	clear();
	clear();
	clear();
	mvwprintw(stdscr, MAXY_R/2,MAXX_R/2,"GAME OVER");
	refresh();
	usleep(500000);
	endwin();
}

void * areaGioco(void * parametri){
	int i,j;
	pos_C *posizioni = (pos_C *) parametri;
	time_t tempo_salvato = time(NULL);	
	
	stampaRing();
	while (num_vite>0){ //inizio ciclo di gioco
		tempo_salvato = stampaCaramelloni(tempo_salvato);

		pthread_mutex_lock(&mutex);//inizio sezione critica


		/*controllo la collisione fra pacman e fantasma*/
		for(i = 1; i<buffC_size;i++){
			if((posizioni[0].xn == posizioni[i].xn) && posizioni[0].yn == posizioni[i].yn){

				num_vite--;
				BFC[0].xn = MAXX_R/2;
    				BFC[0].yn = MAXY_R/2; 
			}

		}


		gestoreProiettili(posizioni);

		pthread_mutex_unlock(&mutex);//fine sezione critica

		

		stampante(posizioni);

		pthread_mutex_lock(&mutex);
		mvprintw(0,MAXY_R+3,"Vite: %d",num_vite);/*Stampo il numero di vite*/
		mvprintw(1,MAXY_R+3,"punti: %d",punti);/*Stampo il numero di vite*/
	  	curs_set(0);
	  	refresh();
		pthread_mutex_unlock(&mutex);
		usleep(50);
    	}; /* ciclo finchè pacman non perde tutte le vite */

}


void gestoreProiettili(pos_C *posizioni){
	int w =buff_size;
	int ok = 0;
	pos_B ausilio;

	for(int i = 0; i<buff_size; i++){
		ok = 1;
		if(BBP[i].ready && BBP[i].vivo){
			scriviLog(buff_size,"Dentro gestore proiettili in ciclo buff");
			scriviLog(BBP[i].id,"Dentro gestore proiettili in ciclo id");

			for(int j = 0; j < numero_caramelline+1 ; j++){
				if(BBP[i].x == caramelline[j].y && BBP[i].y == caramelline[j].x){
					BBP[i].vivo = 0;
					mvaddch(BBP[i].y_old,BBP[i].x_old ,' ');
					refresh();
					ok = 0;					
				}
			}
			
			if(ring[BBP[i].x][BBP[i].y] == '#'){
				BBP[i].vivo = 0;
				mvaddch(BBP[i].y_old,BBP[i].x_old ,' ');
				//mvaddch(BBP[i].y,BBP[i].x ,' ');
				refresh();
				ok = 0;	
			}

			if(BBP[i].x == posizioni[0].xn && BBP[i].y == posizioni[0].yn){
				num_vite--;
				posizioni[0].xn =MAXX_R/2;
				posizioni[0].yn =MAXY_R/2;
				BBP[i].vivo = 0;
				mvaddch(BBP[i].y_old,BBP[i].x_old ,' ');
				//mvaddch(BBP[i].y,BBP[i].x ,' ');
				refresh();
				ok = 0;
			}
			for(int j = 1; j < 6 ; j++){
				if(BBP[i].x == BFC[j].xn && BBP[i].y == BFC[j].yn){
					BFC[j].xn=14;
					BFC[j].yn =21-i;
					BBP[i].vivo = 0;

					mvaddch(BFC[j].yn,BFC[j].xn,'M');
					mvaddch(BBP[i].y_old,BBP[i].x_old ,' ');
					//mvaddch(BBP[i].y,BBP[i].x ,' ');
					refresh();
					ok = 0;
				}		
			}
			if(ok){
				mvaddch(BBP[i].y_old,BBP[i].x_old ,' ');
				mvaddch(BBP[i].y,BBP[i].x ,'o');
				refresh();
			}
			if(!(BBP[i].vivo)){
				mvaddch(BBP[i].y_old,BBP[i].x_old ,' ');
				//mvaddch(BBP[i].y,BBP[i].x ,' ');
				//mvaddch(BBP[i].y,BBP[i].x ,'+');
				refresh();
			}
			refresh();
			scriviLog(BBP[i].id,"Sto uscendo dal ciclo id");
		}

	}
	


}

void stampaRing(){
	pthread_mutex_lock(&mutex);
	caramelline = (pos*) malloc(sizeof(pos*));

  	for(int i = 0 ; i< MAXX_R ; i++){//Disegno il ring 
		for(int j = 0 ; j < MAXY_R ; j++){
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

}

time_t stampaCaramelloni(time_t tempo_salvato){
	int cambio_caramelloni = 0;

		if((time(NULL)-tempo_salvato) > 10){                           //Se sono passati dieci secondi

			for(int i=0;i<3;++i){                      
				pthread_mutex_lock(&mutex);
				mvaddch(pos_caramelloni[i].x,pos_caramelloni[i].y,' ');//cancello i vecchi caramelloni
				pthread_mutex_unlock(&mutex);
		 	}

			cambio_caramelloni = 1;
	  		
			for(int i = 0; i<3;i++){
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

			for(int i=0;i < 3;++i){
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

		return tempo_salvato;

}



void stampante(pos_C *posizioni){
	
	pthread_mutex_lock(&mutex);	//inizio sezione critica
	for(int i = 0; i<buffC_size ; i++){	
		mvaddch(posizioni[i].yn,posizioni[i].xn,posizioni[i].chi);
		refresh();

	}
	pthread_mutex_unlock(&mutex); //fine sezione critica

	
}






