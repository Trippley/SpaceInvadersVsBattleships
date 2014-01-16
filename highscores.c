#include <stdio.h>

void highscores(int pnts){
	FILE *test;
	test = fopen("highscore.txt", "a");
	fprintf(test,"%d\n",pnts);
	fclose(test);
	return;
}
