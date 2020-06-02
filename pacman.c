#include "pacman.h"


char ring[MAXX_R][MAXY_R] = {
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',' ','#'},
{'#',' ','.',' ',' ',' ',' ','.',' ',' ',' ',' ',' ','.','.','.','.',' ',' ',' ',' ',' ','.',' ',' ',' ',' ','.',' ','#'},
{'#',' ','.',' ','#','#',' ','.',' ','#','#','#',' ','.','.','.','.',' ','#','#','#',' ','.',' ','#','#',' ','.',' ','#'},
{'#',' ','.',' ',' ',' ',' ','.',' ',' ',' ',' ',' ','.','.','.','.',' ',' ',' ',' ',' ','.',' ',' ',' ',' ','.',' ','#'},
{'#',' ','.','.','.','.','.','.',' ','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',' ','#'},
{'#',' ','.',' ',' ',' ',' ','.',' ','.','.','.','.','.','.','.','.','.','.','.',' ',' ','.',' ',' ',' ',' ','.',' ','#'},
{'#',' ','.',' ','#','#',' ','.',' ','.','.','.','.','.','.','.','.','.','.','.','.','.','.',' ','#','#',' ','.',' ','#'},
{'#',' ','.',' ',' ',' ',' ','.','.','.','.',' ',' ',' ',' ',' ',' ',' ',' ','.',' ','.','.',' ',' ',' ',' ','.',' ','#'},
{'#',' ','.','.','.','.','.','.','.','.','.',' ','#','#','#','#','#','#',' ','.','.','.','.','.','.','.','.','.',' ','#'},
{'#',' ',' ',' ',' ',' ',' ','.',' ',' ',' ','.',' ',' ','#','#',' ',' ','.',' ',' ',' ','.',' ',' ',' ',' ',' ',' ','#'},
{'#','#','#','#','#','#',' ','.',' ','#',' ','.',' ',' ','#','#',' ','.','.',' ','#',' ','.',' ','#','#','#','#','#','#'},
{' ',' ',' ',' ',' ','#',' ','.',' ','#',' ','.','.','.',' ',' ','.','.','.',' ','#',' ','.',' ','#',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ','#',' ','.',' ','#',' ',' ',' ','.','.','.','.',' ',' ',' ','#',' ','.',' ','#',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ','#',' ','.',' ','#','#','#',' ','.','.','.','.',' ','#','#','#',' ','.',' ','#',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ','#',' ','.',' ','#',' ',' ',' ','.','.','.','.',' ',' ',' ','#',' ','.',' ','#',' ',' ',' ',' ',' '},
{'#','#','#','#','#','#',' ','.',' ','#',' ','.','.','.','.','.','.','.','.',' ','#',' ','.',' ','#','#','#','#','#','#'},
{' ',' ',' ',' ',' ',' ',' ','.',' ',' ',' ','.',' ',' ',' ',' ',' ',' ','.',' ',' ',' ','.',' ',' ',' ',' ',' ',' ',' '},
{'.','.','.','.','.','.','.','.','.','.','.','.',' ','#',' ',' ','#',' ','.','.','.','.','.','.','.','.','.','.','.','.'},
{' ',' ',' ',' ',' ',' ',' ','.',' ',' ',' ','.',' ','#',' ',' ','#',' ','.',' ',' ',' ','.',' ',' ',' ',' ',' ',' ',' '},
{'#','#','#','#','#','#',' ','.',' ','#',' ','.',' ','#',' ',' ','#',' ','.',' ','#',' ','.',' ','#','#','#','#','#','#'},
{' ',' ',' ',' ',' ','#',' ','.',' ','#',' ','.',' ','#','#','#','#',' ','.',' ','#',' ','.',' ','#',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ','#',' ','.',' ','#',' ','.',' ',' ',' ',' ',' ',' ','.',' ','#',' ','.',' ','#',' ',' ',' ',' ',' '},
{'#','#','#','#','#','#',' ','.',' ','#',' ','.','.','.','.','.','.','.','.',' ','#',' ','.',' ','#','#','#','#','#','#'},
{'#',' ',' ',' ',' ',' ',' ','.',' ',' ',' ','.',' ',' ',' ',' ',' ',' ','.',' ',' ',' ','.',' ',' ',' ',' ',' ',' ','#'},
{'#',' ','.','.','.','.','.','.','.','.','.','.',' ','#','#','#','#',' ','.','.','.','.','.','.','.','.','.','.',' ','#'},
{'#',' ','.',' ',' ',' ','.','.','.','.','.','.','.',' ',' ',' ',' ','.','.','.','.','.','.','.',' ',' ',' ','.',' ','#'},
{'#',' ','.',' ','#',' ','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',' ','#',' ','.',' ','#'},
{'#',' ','.',' ','#',' ','.','.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.','.',' ','#',' ','.',' ','#'},
{'#',' ','.',' ','#',' ','.',' ','#','#','#','#','#',' ',' ',' ',' ','#','#','#','#','#',' ','.',' ','#',' ','.',' ','#'},
{'#',' ','.',' ',' ',' ','.','.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.',' ',' ',' ',' ','.',' ','#'},
{'#',' ','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};
int vittoria = 0;
int ps=1;
int music_status = 0;
int num_ghost = 0;
int num_vite=3;
int PASSO = 1;									/* Entita spostamento */
int punti = 0;
int punti_caramelloni = 10;
int numero_caramelline = 0;
int punti_caramelline = 1;
int buff_size = 0;
pos pos_caramelloni[3] = {};
pos *caramelline = NULL;
pos_B *BBP =NULL;
pos_C *BFC = NULL;
int buffC_size = 0;
int id_personaggi = 0;
int id_bulletti = 0;
int morte = 0;
int id_bulli[4000];
int id_bulli_dim = 0;
int id_g[6];
int _id_g_dim = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;/*creo e inizializzo il semaforo*/
char c;

void * pacman(void * parametri){
    pos *pos_pacman = (pos*) parametri;
    pthread_t id_t;

    pthread_create(&(id_t),NULL,&movimentoPacman,(void*)(pos_pacman));

	while(num_vite>0){
		c=getch();
	}
}

void pacmanMove(pos *pos_pacman){

	int i = 0;


	pos_pacman->x = BFC[0].xn;
	pos_pacman->y = BFC[0].yn;

	switch(c){// Mi sposto in base al tasto che ho premuto
		 // controllando ogni volta di non uscire dai limiti
		case SU:
			if(pos_pacman->y>0){
				pos_pacman->y-=1;
			}else{
				pos_pacman->y = MAXY_R;			
			}

			if(ring[pos_pacman->y][pos_pacman->x]  == '#'){
				pos_pacman->y+=1;
			}

			break;

		case GIU:
			if(pos_pacman->y<MAXX_R){
				pos_pacman->y+=1; 
			}else{
				pos_pacman->y = 0;
			}
			

			if(ring[pos_pacman->y][pos_pacman->x]  == '#'){
				pos_pacman->y-=1;
			}
			break;

		case SINISTRA:
			if(pos_pacman->x>0){
				pos_pacman->x-=1;
			}else{
				pos_pacman->x = MAXX_R;
			}

			if(ring[pos_pacman->y][pos_pacman->x] == '#'){
				pos_pacman->x+=1;
			}	

			break;

		case DESTRA:

			if(pos_pacman->x < MAXY_R){
				pos_pacman->x+=1;
			}else{
				pos_pacman->x = 0;			
			}


			if(ring[pos_pacman->y][pos_pacman->x] == '#'){
				pos_pacman->x-=1;
			}
			break;
		case SPACE:
			trigger(&(BFC[0]));
			break;

	}

	pthread_mutex_lock(&mutex);//Inizio sezione critica


	for(i = 0; i <3 ; i++){
		if(pos_caramelloni[i].x == pos_pacman->y  && pos_caramelloni[i].y == pos_pacman->x ){//Caramellone preso 
			punti += punti_caramelloni;
			pos_caramelloni[i].x = MAXX_R*2;
			pos_caramelloni[i].y = MAXY_R*2;
			musiche(3);
		}
	}

	for(i = 0; i < (numero_caramelline + 1); i++ ){
		if(ring[pos_pacman->y][pos_pacman->x] == '.'){			
			punti += punti_caramelline;
			ring[pos_pacman->y][pos_pacman->x] = ' ';
			numero_caramelline = numero_caramelline-1 ;
			musiche(4);
			
			if(numero_caramelline == 0){
				vittoria = 1;
			}
		}
	}
	
	pthread_mutex_unlock(&mutex);//Fine sezione critica

}

void * movimentoPacman(void *parametri){
	pos *pos_pacman = (pos*) parametri;

	while(num_vite>0){
		
		pthread_mutex_lock(&mutex);//Inizio sezione critica

		BFC[0].x_old = pos_pacman->x;
		BFC[0].y_old = pos_pacman->y;

		pos_pacman->x = BFC[0].xn;
		pos_pacman->y = BFC[0].yn;

		pthread_mutex_unlock(&mutex);//Fine sezione critica

		pacmanMove(pos_pacman);

		pthread_mutex_lock(&mutex);//Inizio sezione critica
		mvaddch(BFC[0].y_old,BFC[0].x_old,' ');
		refresh(); 
		
		BFC[0].xn = pos_pacman->x;
		BFC[0].yn = pos_pacman->y;

		pthread_mutex_unlock(&mutex);//Fine sezione critica
		usleep(300000);
	}

}

int BBPadd(pos_B proiettile){
	int i = 0;
	
	while(BBP[i].vivo && (i < buff_size)){
		i++;	
	}


	if(i < 4000){

		BBP[i].vivo = proiettile.vivo;
		BBP[i].x = proiettile.x;
		BBP[i].y = proiettile.y;
		BBP[i].dir = proiettile.dir;
		BBP[i].id = proiettile.id;
		BBP[i].ready = proiettile.ready;
		BBP[i].checked = proiettile.checked;
		BBP[i].t_vivo = proiettile.t_vivo;
		BBP[i].id_t = proiettile.id_t;
		buff_size++;

	}
	

	return 1;

}

void BBPaggiorna(pos_B proiettile){
	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
	usleep(500);
	
	//BBP = (pos_B*) realloc(BBP,sizeof(pos_B)*buff_size);
		
	BBP[proiettile.id].vivo = proiettile.vivo;
	BBP[proiettile.id].x = proiettile.x;
	BBP[proiettile.id].y = proiettile.y;
	BBP[proiettile.id].dir = proiettile.dir;
	BBP[proiettile.id].id = proiettile.id;
	BBP[proiettile.id].ready = proiettile.ready;


	pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
}

void BBPcut(int pos){

	//pthread_cancel(BBP[pos].id_t);
	
	if(buff_size > 0){
		for(int i = pos; i<buff_size-1;i++){
	
			BBP[i] = BBP[i+1];

		}
	}

	if(	buff_size > 0){
		buff_size--;
	}
	
}

pos_B* BBPinit(){

	BBP = (pos_B*)calloc(sizeof(pos_B*),4000);

	return BBP;
}

int BBPricerca(pos_B proiettile,int i){

	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
	if((proiettile.x == BBP[i].x) && (proiettile.y == BBP[i].y)){
		pthread_mutex_unlock(&mutex);/*Fine sezione critica*/		
		return 1;
	}
	return 0;
	pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
}

void * Shot(void *parametri){
	//pos_B *proiettile = (pos_B*) parametri;
	//int id = proiettile->id;
	int *indice = (int*) malloc(sizeof(int*));
	int exit = 1;
	int *id = (int*) parametri;
					
	do{

		pthread_mutex_lock(&mutex);/*Inizio sezione critica*/		
		*indice = BBPfindID(*id);

		if(*indice != -7){
			BBP[*indice] = incrementaProiettile(BBP[*indice]);
			if(BBP[*indice].vivo == 0){
				BBPcut(*indice);

			}
		}

		pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
		usleep(250000);			

	}while(BBP[*indice].vivo == 1 && *indice != -7);

}

pos_B incrementaProiettile(pos_B proiettile){		

	proiettile.x_old=proiettile.x;
	proiettile.y_old=proiettile.y;

	if(proiettile.vivo && proiettile.checked){
		
		switch(proiettile.dir){
		
			case'U':
				if(proiettile.y>1){
					proiettile.y = proiettile.y-1;
				}else{
					proiettile.vivo = 0;
				}

				if(ring[proiettile.y][proiettile.x] == '#'){
					proiettile.vivo = 0;
					mvaddch(proiettile.y_old,proiettile.x_old ,' ');
					refresh();					

				}
				break;

			case'D':
				if(proiettile.y<MAXX_R-1){
					proiettile.y = proiettile.y +1;

				}else{
					proiettile.vivo = 0;
				}

				if(ring[proiettile.y][proiettile.x] == '#'){
					proiettile.vivo = 0;
					mvaddch(proiettile.y_old,proiettile.x_old ,' ');
					refresh();				

				}
				break;

			case'L':
				if(proiettile.x>1){
					proiettile.x =proiettile.x-1;
				}else{
					proiettile.vivo = 0;
				}

				if(ring[proiettile.y][proiettile.x] == '#'){
					proiettile.vivo = 0;
					mvaddch(proiettile.y_old,proiettile.x_old ,' ');
					refresh();				

				}
				break;
			case'R':
				if(proiettile.x < MAXY_R){
					proiettile.x =proiettile.x+1;

				}else{
					proiettile.vivo = 0;
				}

				if(ring[proiettile.y][proiettile.x] == '#'){
					proiettile.vivo = 0;
					mvaddch(proiettile.y_old,proiettile.x_old ,' ');
					refresh();					

				}
				break;
		}
			
		proiettile.checked = 0;
		proiettile.ready = 1;
	}	

	return proiettile;
}

int BBPfindID(int id){
		
	for(int i = 0; i<buff_size;i++){
		if(BBP[i].id == id){
			return i;		
		}
	}

	return -7;
}

pos_C* BFCinit(){
	pos_C fantasmi[5];
	BFC =(pos_C*) malloc(sizeof(pos_C)*7);
	int i,j;

	BFC[0].chi = 'C';
	BFC[0].vivo = 1;
	BFC[0].id = id_personaggi;
	id_personaggi++;
	BFC[0].xn = MAXX_R/2;
    	BFC[0].yn = MAXY_R/2; 
	buffC_size++;

	id_g[0] = 0;

	for(i = 0; i < 3; i++){

		fantasmi[i].vivo = 1;
		fantasmi[i].chi = 'M';
		fantasmi[i].xn = 14;
		fantasmi[i].yn = 21 - i;
		
		BFCadd(fantasmi[i]);	

			
	}

	do{
		i = rand()%MAXX_R;
		j = rand()%MAXY_R;		
	}while(ring[i][j] != '.' );

	fantasmi[4].vivo = 1;
	fantasmi[4].chi = 'M';
	fantasmi[4].xn = i;
	fantasmi[4].yn = j;
	
	BFCadd(fantasmi[4]);
	buffC_size--;	
		

	return BFC;
}

void BFCadd(pos_C pg){
	
	buffC_size++;
	id_personaggi++;

	BFC[buffC_size-1].id = id_personaggi;
	BFC[buffC_size-1].vivo = pg.vivo;
	BFC[buffC_size-1].chi = pg.chi;
	BFC[buffC_size-1].xn = pg.xn;
	BFC[buffC_size-1].yn = pg.yn;
	BFC[buffC_size-1].x_old = pg.xn;
	BFC[buffC_size-1].y_old = pg.yn;
	scriviLog(BFC[buffC_size-1].id,"Fantasmino skerzo aggiunto in BFC");	

}

pos_C BFCfindID(int id, int *index){
	int i = 0;
	pos_C errore;
	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
	for(i = 0; i < buffC_size; i++){		
		if(BFC[i].id == id){
			*index = i;
  		 	pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
			return BFC[i];
		}
	}
	pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
	return errore;

}

int BFCconfornta(pos_C pg,int i){

	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
	if((pg.xn == BFC[i].xn) && (pg.yn == BFC[i].yn)){
		pthread_mutex_unlock(&mutex);/*Fine sezione critica*/		
		return 1;
	}
	pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
	return 0;
}


void BFCaggiorna(pos_C *pg){

	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/

	BFC[pg->id].id = pg->id;
	BFC[pg->id].vivo = pg->vivo;
	BFC[pg->id].chi = pg->chi;
	BFC[pg->id].xn = pg->xn;
	BFC[pg->id].yn = pg->yn;

	pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

}



void scriviLog(int msg, char* nome){
  FILE *fd;

  fd=fopen("log.txt", "a");
  if( fd==NULL ){
    perror("Errore in apertura del file");
    exit(1);
  }

  fprintf(fd, "%s = %d\n\n",nome, msg);

  fclose(fd);
}

void trigger(pos_C *pg){
	char direzioni[4] = {'U','D','L','R'};
	pos_B proiettile[4];
	int id;
	
	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
	
	musiche(2);

	for(int i = 0; i<4; i++){

		proiettile[i].vivo = 1;
		proiettile[i].dir = direzioni[i];
		proiettile[i].id = id_bulli_dim; 
		proiettile[i].x = pg->xn;
		proiettile[i].y = pg->yn;
		proiettile[i].ready = 0;
		proiettile[i].checked = 1;
		proiettile[i].t_vivo = 1;

		id_bulli[id_bulli_dim] = id_bulli_dim;

		proiettile[i] = incrementaProiettile(proiettile[i]);

		if(proiettile[i].vivo){
			id = BBPadd(proiettile[i]);
		}

		if(proiettile[i].vivo == 1){
			pthread_create(&(BBP[id].id_t),NULL,&Shot,(void*)&(id_bulli[id_bulli_dim]));
		}
		id_bulli_dim++;
	}	
	pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
	usleep(1000000);
}

void scriviLogBull(int x,int y, char* nome, char direzione, int id,int indice){
  FILE *fd;

  fd=fopen("logBullet.txt", "a");
  if( fd==NULL ){
    perror("Errore in apertura del file");
    exit(1);
  }

  fprintf(fd, "%s direzione %c  x = %d y = %d id = %d indice = %d\n\n",nome, direzione, x, y,id,indice);

  fclose(fd);
}

void musiche(int colonna){

	switch(colonna){
		case 0:
			system("ffplay Main_Loop.mp3 -nodisp -nostats -hide_banner &");
		break;

		case 1:
		break;

		case 2:
			system("pkill -f ffplay");
			system("ffplay Sparo\\ 4\\ \\(Multiple\\).aif -nodisp -nostats -hide_banner &");			
		break;
			
		case 3:
			system("pkill -f ffplay");
			system("ffplay Coin\\ BONUS.aif -nodisp -nostats -hide_banner &");
		break;
		
		case 4:
			system("pkill -f ffplay");
			system("ffplay Coins\\ 6.aif -nodisp -nostats -hide_banner &");
		break;

	}

}






