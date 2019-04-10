#include<stdio.h>
//#include<stdlib.h>			// for random numbers
//#include<time.h>			// for randomization (using system time)
#include"screen.h"
#include <signal.h>
#include"sound.h"
#include "comm.h"
void main(void){
	FILE *f;
	short sd[RATE];
	for(;;){
	int ret = system(RCMD);
	if (ret == SIGINT) break;
	//system(RCMD);
	f = fopen("test.wav","r");
	if(f==NULL){
		printf("cannot open the file\n");
		return 1;
	}
//	int dec[COL];
//	srand(time(NULL));
//	for(int i =0;i<COL;i++) dec[i] = rand()%70+30;
	clearScreen();
	setColors(GREEN,bg(YELLOW));
//	barChart(dec);
//	printf("Message from main\n");
	struct WAVHDR hdr;
	fread(&hdr, sizeof(hdr),1,f);	//read WAV header
	fread(&sd,sizeof(sd),1,f); //read wav data   
	 fclose(f);	
	displayWAVHDR(hdr);
	displayWAVDATA(sd);
	sendDATA(sd);
}
	resetColors();
//	getchar();
//	printf("Message from main\n");
//	resetColors();
//	printf("Message from main");
	puts("");
	getchar();
}
