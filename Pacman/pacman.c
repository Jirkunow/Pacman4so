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
pthread_t id_bulli[4000];
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

			if(pos_pacman->x < MAXY_R){
			pos_pacman->x+=1;
			}


			if(ring[pos_pacman->y][pos_pacman->x] == '#'){
				pos_pacman->x-=1;
			}
			break;
		case SPACE:
			scriviLog(SPACE,"hai premuto spazio");
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
			caramelline[i].x = MAXX_R*2;
			caramelline[i].y = MAXY_R*2;
			numero_caramelline--;

		}
	}

}

void BBPadd(pos_B proiettile){
	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/

	scriviLog(buff_size,"Buff size in BBPadd");
	scriviLog(proiettile.id,"ID diproiettile in BBPadd");
		
	BBP[proiettile.id].vivo = proiettile.vivo;
	BBP[proiettile.id].x = proiettile.x;
	BBP[proiettile.id].y = proiettile.y;
	BBP[proiettile.id].dir = proiettile.dir;
	BBP[proiettile.id].id = proiettile.id;
	BBP[proiettile.id].ready = proiettile.ready;


	pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
}

void BBPaggiorna(pos_B proiettile){
	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/

	scriviLog(buff_size,"Buff size in BBPaggiorna");
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

pos_B BBPcut(int pos){
	pos_B *cout = &(BBP[pos]);

	cout = NULL;
	cout = (pos_B*)calloc(sizeof(pos_B*),1);
	
	if(buff_size > 0){
		for(int i = pos; i<buff_size-1;i++){
			BBP[i] = BBP[i+1];
			BBP[i].id =i; 
		}
	}

	buff_size--;


	/*pos_B cout;
	pthread_mutex_lock(&mutex);//Inizio sezione critica
	
	buff_size--;

	cout = BBP[buff_size];
	for(int i = pos; i<buff_size;i++){
		BBP[i] = BBP[i+1];
	}
	//BBP = (pos_B*) realloc(BBP,sizeof(pos_B)*buff_size);
    pthread_mutex_unlock(&mutex);//Fine sezione critica
*/
	return *cout;
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
	pos_B ausilio;
	int *id = (int*) parametri;

	scriviLog(BBP[*id].id,"Shot con id");
	scriviLog(BBP[*id].vivo,"Shot con vivo");

	BBP[*id].ready = 1;
	do{
		scriviLog(BBP[*id].id,"Shot con id");
		scriviLog(BBP[*id].x,"Shot con x");
		scriviLog(BBP[*id].y,"Shot con y");

		BBP[*id] = incrementaProiettile(BBP[*id]);
		*id = BBP[*id].id;

		scriviLog(BBP[*id].vivo,"Shot con vivo");

	}while(BBP[*id].vivo == 1);

	scriviLog(BBP[*id].id,"Shot con id (DOPO)");
	scriviLog(BBP[*id].vivo,"Shot con vivo (DOPO)");
	
	scriviLog(buff_size,"buff_size (PRIMA)");	

	ausilio = BBPcut(BBP[*id].id);

	scriviLog(buff_size,"buff_size (DOPO)");
		
}

pos_B incrementaProiettile(pos_B proiettile){

	if(BBP[proiettile.id].ready){
		usleep(500000);
	}

	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/		

	proiettile.x_old=proiettile.x;
	proiettile.y_old=proiettile.y;	

	switch(proiettile.dir){

		case'U':
			if(proiettile.y>1){
				proiettile.y = proiettile.y-1;
			}else{
				proiettile.vivo = 0;
			}

			if(ring[proiettile.y][proiettile.x] == '#'){
					proiettile.vivo = 0;
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
			}
			break;
	}
	pthread_mutex_unlock(&mutex);/*fine sezione critica*/	

	return proiettile;
}

pos_B *BBPfindID(int id){
	pos_B *tmp_hlp;
	pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
	for(int i = 0; i<buff_size;i++){
		if(BBP[i].id == id){
			*tmp_hlp = BBP[i];
		pthread_mutex_unlock(&mutex);/*Fine sezione critica*/			
			return tmp_hlp;		
		}
	}
	pthread_mutex_unlock(&mutex);/*Fine sezione critica*/
	return NULL;
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

	scriviLog(SPACE,"sei dentro trigger");

	for(int i = 0; i<4; i++){

		pthread_mutex_lock(&mutex);/*Inizio sezione critica*/
		
		buff_size++;
		proiettile[i].vivo = 1;
		proiettile[i].dir = direzioni[i];
		proiettile[i].id = buff_size-1;
		proiettile[i].x = pg->xn;
		proiettile[i].y = pg->yn;
		proiettile[i].ready = 0;

		pthread_mutex_unlock(&mutex);/*Fine sezione critica*/

		//scriviLog(proiettile[i].x ,"sei dentro trigger for zone:proiettile[i].x ");
		proiettile[i] = incrementaProiettile(proiettile[i]);

		BBPadd(proiettile[i]);
		//scriviLog(proiettile[i].y,"sei dentro trigger post incremento:proiettile[i].y");
		id_bulli_dim++;

		pthread_create(&(id_bulli[id_bulli_dim-1]),NULL,&Shot,(void*)&(BBP[buff_size-1].id ));

		usleep(500);
	}	






}













