#include<stdio.h>
#include<stdlib.h>			// for random numbers
#include<time.h>			// for randomization (using system time)
#include"screen.h"
void main(void){
	int dec[COL];
	srand(time(NULL));
	for(int i =0;i<COL;i++) dec[i] = rand()%70+30;
	clearScreen();
	setColors(GREEN,bg(YELLOW));
	barChart(dec);
//	printf("Message from main\n");
	resetColors();
//	printf("Message from main\n");
//	resetColors();
	printf("Message from main");
	puts("");
	getchar();
}
