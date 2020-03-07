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
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;/*creo e inizializzo il semaforo*/

void * pacman(void * parametri){
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

	}
}

void pacmanMove(pos *pos_pacman){

	int i = 0;
	char c;


	c=getch();

	pos_pacman->x = BFC[0].xn;
	pos_pacman->y = BFC[0].yn;

	switch(c){// Mi sposto in base al tasto che ho premuto
		 // controllando ogni volta di non uscire dai limiti
		case SU:
			if(pos_pacman->y>1){
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
			if(pos_pacman->x>1){
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
			caramelline[i].x = -1;
			caramelline[i].y = -1;
			numero_caramelline--;

		}
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
		
		scriviLogBull(BBP[i].x,BBP[i].y,"Inserimento proiettile: ",BBP[i].dir,BBP[i].id,i);
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

	scriviLog(pos,"BBPcut-> eliminazione proiettile con indice");
	scriviLogBull(BBP[pos].x,BBP[pos].y,"Sto per essere eliminato",BBP[pos].dir,BBP[pos].id,pos);	

	//pthread_cancel(BBP[pos].id_t);
	
	if(buff_size > 0){
		for(int i = pos; i<buff_size-1;i++){
			
			scriviLogBull(BBP[i].x,BBP[i].y,"Scambi sul buffer \n",BBP[i].dir,BBP[i].id,i);	

			scriviLogBull(BBP[i+1].x,BBP[i+1].y,"Scambi sul buffer \n",BBP[i+1].dir,BBP[i+1].id,i+1);	
			
		
			BBP[i] = BBP[i+1];

		}
	}

	if(	buff_size > 0){
		buff_size--;
	}


	scriviLogBull(BBP[pos].x,BBP[pos].y,"Ora nella mia posizione c'e' ",BBP[pos].dir,BBP[pos].id,pos);
	for(int i = pos+1; i<buff_size-1;i++){
		scriviLogBull(BBP[i].x,BBP[i].y,"Scambi sul buffer \n",BBP[i].dir,BBP[i].id,i);
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
		scriviLog(*indice,"Shot, indice dello shot");
		scriviLog(*id,"Shot, id dello shot");
		
		if(*indice != -7){
			BBP[*indice] = incrementaProiettile(BBP[*indice]);

			scriviLogBull(BBP[*indice].x,BBP[*indice].y,"Sono il proiettile",BBP[*indice].dir,BBP[*indice].id,*id);

		}

		pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
		usleep(1000000);			

	}while(BBP[*indice].vivo == 1 && *indice != -7);

	scriviLog(BBP[*indice].id,"Id shot fuori while");
		
}

pos_B incrementaProiettile(pos_B proiettile){		

	proiettile.x_old=proiettile.x;
	proiettile.y_old=proiettile.y;

	if(proiettile.vivo && proiettile.checked){
		scriviLog(proiettile.id,"Incremento proiettile id ");
		
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
					
					buff_size--;					
					
					scriviLogBull(proiettile.x,proiettile.y,"Muro colpito!!",proiettile.dir,proiettile.id,proiettile.id);
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

					buff_size--;					

					scriviLogBull(proiettile.x,proiettile.y,"Muro colpito!!",proiettile.dir,proiettile.id,proiettile.id);
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

					buff_size--;					

					scriviLogBull(proiettile.x,proiettile.y,"Muro colpito!!",proiettile.dir,proiettile.id,proiettile.id);
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

					buff_size--;					

					scriviLogBull(proiettile.x,proiettile.y,"Muro colpito!!",proiettile.dir,proiettile.id,proiettile.id);
				}
				break;
		}
		scriviLogBull(proiettile.x,proiettile.y,"Incremento Proiettile ",proiettile.dir,proiettile.id,proiettile.id);
			
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
	pos_C fantasmi[3];
	BFC =(pos_C*) malloc(sizeof(pos_C)*7);

	BFC[0].chi = 'C';
	BFC[0].vivo = 1;
	BFC[0].id = id_personaggi;
	id_personaggi++;
	BFC[0].xn = MAXX_R/2;
    	BFC[0].yn = MAXY_R/2; 
	buffC_size++;

	for(int i = 0; i < 3; i++){
		
		fantasmi[i].id = i+1;
		id_personaggi++;
		fantasmi[i].vivo = 1;
		fantasmi[i].chi = 'M';
		fantasmi[i].xn = 14;
		fantasmi[i].yn = 21 - i;
		
		BFCadd(fantasmi[i]);	

			
	}
		

	return BFC;
}

void BFCadd(pos_C pg){
	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
	
	buffC_size++;

	BFC[buffC_size-1].id = pg.id;
	BFC[buffC_size-1].vivo = pg.vivo;
	BFC[buffC_size-1].chi = pg.chi;
	BFC[buffC_size-1].xn = pg.xn;
	BFC[buffC_size-1].yn = pg.yn;

   	pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
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

	scriviLog(SPACE,"Sei dentro trigger");
	
	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/

	for(int i = 0; i<4; i++){

		
		buff_size++;
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
		}else{
			scriviLogBull(proiettile[i].x,proiettile[i].y, "Proiettile non inserito perche non vivo, dir", proiettile[i].dir, proiettile[i].id,i);
		}

		scriviLog(proiettile[i].vivo,"Richiesta lancio thread shot status vita");

		if(proiettile[i].vivo == 1){
			scriviLog(id_bulli[id_bulli_dim],"Richiesta lancio thread shot id");
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











