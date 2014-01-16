 void bubblesort(){
	int hs[] = "highscore.txt";
	FILE *file;
	file = fopen("highscore.txt", "a");
	int i, j;

	if ((file = fopen("highscore.txt", "a") == NULL)){
		return -1;
	} else {
    	while(1) {
      		hs[i] = fgetc(file);
      if(hs!=EOF) {
        printf("\n %lf \n", hf[i]);
        i++;
      }
      else {
        break;
      }
    }
 
    fclose(file);
    system("\n\n\nPAUSE");	
    return 0;
  }
 
}

     for (i = 0; i < length -1; ++i) {
 		for (j = 0; j < length - i - 1; ++j){
 	    	if (hs[j] > hs[j + 1]){
 				int tmp = hs[j];
 				hs[j] = hs[j + 1];
 				hs[j + 1] = tmp;
 	    	}
 		}
     }
 }


