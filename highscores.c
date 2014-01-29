#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF 255
int hs[11];
char puffer[BUF];
FILE *datei;

/* schreibt HSF-Datei Zeilenweise in Array*/
void txtToArr(){
	int i;
	datei = fopen("highscore.hsf", "r");
	for(i=0;i<11;i++){
		fgets(puffer, BUF, datei);
		hs[i]=(int)strtol(puffer,NULL,0);
	}
	fclose(datei);
}

/* Bubblesort-Algorithmus, Sortiert die Highscore-Liste.*/
void bubble(){
	int i,j;
	for (i=0; i<11;++i) {
 		for (j=0;j<11-i;++j){
 			if (hs[j]>hs[j+1]){
 				int tmp = hs[j];
 				hs[j]=hs[j+1];
 				hs[j+1]=tmp;
			}
		}
	}
}


void highscores(int pnts){
	int i;
	txtToArr();
	if(pnts>hs[11]){
		hs[10]=pnts;
		bubble();
		datei = fopen("highscore.hsf", "w");
		for(i=11;i>0;i--){
			fprintf(datei,"%d\n",hs[i]);
		}
		fclose(datei);
		return;
	}
	
}

int main(){
	highscores(903);
}
