#include <stdio.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include "ROCCAT_Talk.h"


#include "highscores.h"
#define LVLANZAHL 3

int grenze = 100;
float factor= 1.2;

int level(int pnts, int lvl){
	CROCCAT_Talk roccat;
	roccat.set_ryos_kb_SDKmode(TRUE);
	if(lvl<LVLANZAHL){
		//passiert nix, da noch nicht genügend level erreicht wurden
		if(pnts< grenze*factor){
			return 0;
		}
		else{
//			schowOnScreen("Congrats, Level %d beaten",lvl);	// Textausgabe an bildschrim (printf??)
			roccat.All_Key_Blinking(300,100);				// Heroisches blinken der Tastatur für 3 Sekunden
			lvl++;
			grenze=(int)pnts+(grenze*factor);				// grenze fürs nächste Level wird erhöht
//			eraseScreen();									// alle objekte vom schirm löschen, extern definiert
//			newScreen();									// neue objekte auf den schirm setzen, extern definiert

		/*	##############################################
		## Brauchts das in dieser Datei??	##############
		##################################################
			switch (lvl){
			case 1:											// hier beschreibung für lvl 1
				break;
			case 2:											// hier für lvl 2
				break;
			case 3:											// ...	
				break;
			}
		####################################################
		*/							
		}
	}
	// game vorbei, da level 20 besiegt wurde
	else{
//		schowOnScreen("Congrats, you won the game",lvl);	// Textausgabe an bildschrim (printf??)
		roccat.All_Key_Blinking(300,1000);					// Heroisches blinken der Tastatur für 30 Sekunden
		highscores(pnts);									// schreibt die Punkte in Highscore-liste
		return 1;
	}
	roccat.set_ryos_kb_SDKmode(FALSE);
}