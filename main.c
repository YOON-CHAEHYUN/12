#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "BingoBoard.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i,num;
	
	num=n_size*n_size;	
	
	printf("**********************************\n");
	printf("             BINGO                \n");
	printf("**********************************\n");
	
	//PRINT BINGO BOARD
	//SELECT NUMBER
	//UPDATE THE STATUS
	
	bingo_init();
	bingo_print();
	
	printf("\n\n\n\n\n\n\n\n\n");
	printf("@@@@@@@@@@@VICTORY@@@@@@@@@@@@@@@@");
	return 0;
}
