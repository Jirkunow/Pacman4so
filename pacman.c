#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <pthread.h>
#include <time.h>


						
#define SU 65 							/* Freccia su */
#define GIU 66 						/* Freccia giu */
#define SINISTRA 68					/* Freccia sinsitra */
#define DESTRA 67					/* Freccia destra */
#define MAXX_R 35 						/* Numero di colonne dello schermo */
#define MAXY_R 30						/* Numero di righe dello schermo */

/*Struttura che identifica la posizione di vespa e contadino*/
typedef struct
{
  int x;
  int y;
}pos;

typedef struct
{
  pos *pac;
  pos *gost;
}pos_A;

char ring[MAXX_R][MAXY_R] = {
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ','#','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#','#',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#','#','#','#','#','#',' ',' ',' ','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#','#'},
{' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' '},
{'#','#','#','#','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#','#'},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{'#','#','#','#','#','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#','#'},
{' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#','#','#','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' '},
{'#','#','#','#','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#'},
{'#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#'},
{'#',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ','#',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};
int num_vite=3;
int PASSO = 1;									/* Entita spostamento */
int num_fantasmi = 4;
int punti = 0;
int punti_caramelloni = 10;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;/*creo e inizializzo il semaforo*/


void * ghost(void * parametri);
void * pacman(void * parametri);
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



void * pacman(void * parametri){
    pos * pos_pacman = (pos*) parametri;
    pos_pacman->x=MAXX_R/2;
    pos_pacman->y=MAXY_R/2;

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

		if(ring[pos_pacman->y][pos_pacman->x] == '$'){//Caramellone preso 
			punti += punti_caramelloni;
		}
		
		pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
		mvaddch(pos_pacman->y,pos_pacman->x,'C');
		refresh();
		pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

	}
}

void * ghost(void * parametri){

  pos * pos_gost = (pos*) parametri;/*Converto la mia variabile in input*/
  int dx,dy;
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

void * areaGioco(void * parametri){
	int i,j;
	int cambio_caramelloni = 0;
	pos_A * posizioni = (pos_A *) parametri;
	pos pos_caramelloni[3];


  	pthread_mutex_lock(&mutex);

  	for(i = 0 ; i< MAXX_R ; i++){//Disegno il ring 
		for(j = 0 ; j < MAXY_R ; j++){
			mvaddch(i,j,ring[i][j]);
     		refresh();
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
				if(cambio_caramelloni = 0){
					ring[pos_caramelloni[i].y][pos_caramelloni[i].x] = ' ';
				}
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

				ring[pos_caramelloni[i].y][pos_caramelloni[i].x] = '$';                                     
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
















//Aggiustare l'assegnamento dei punti dei Caramelloni 







