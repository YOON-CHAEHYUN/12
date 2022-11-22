#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "BingoBoard.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int get_number(void)
{
	int selNum=0;
	
	
	do{
		printf("select a number: ");
		scanf("%d",&selNum);
		fflush(stdin);//???? ??? ??????? ?????? ???? ?? 
		if (selNum<1||selNum>n_size*n_size||bingo_checkNum(selNum)==BINGO_NUMSTATUS_ABSENT)
			{
				printf("%i is not on the board! select other one.\n");
			}
	}while(selNum<1||selNum>n_size*n_size||bingo_checkNum(selNum)==BINGO_NUMSTATUS_ABSENT);
	return selNum;
}

int main(int argc, char *argv[]) {
	
	int i,num, selNum,imsi;
	num=n_size*n_size;
	
	srand((unsigned int)time(NULL));	
	
	printf("**********************************\n");
	printf("             BINGO                \n");
	printf("**********************************\n");
	
	//PRINT BINGO BOARD
	//SELECT NUMBER
	//UPDATE THE STATUS
	
	imsi=0;
	bingo_init();
	while(imsi<n_bingo){
		bingo_print();
		printf("Bingo: %i\n",imsi);
		selNum=get_number();
		bingo_inputNum(selNum);
		imsi=bingo_countCompletedLine();
		
	}
	bingo_print();
	printf("\n\n\n\n\n\n\n\n\n");
	printf("@@@@@@@@@@@VICTORY@@@@@@@@@@@@@@@@");
	return 0;
}
