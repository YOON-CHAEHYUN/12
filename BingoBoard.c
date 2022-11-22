#include "BingoBoard.h"
#define bingo_hole -1

static int bingoBoard[n_size][n_size];
static int numberStatus[n_size*n_size];


int bingo_checkNum(int selNum){
	if(numberStatus[selNum-1]==bingo_hole)
		return BINGO_NUMSTATUS_ABSENT;
	return BINGO_NUMSTATUS_PRESENT;
}

void bingo_init(void){
	int i, j, cnt=1;
	for(i=0;i<n_size;i++)
		for(j=0;j<n_size;j++){
			if(cnt==15)
			{
				bingoBoard[i][j]=bingo_hole;
				numberStatus[cnt-1]=bingo_hole;
				cnt++;
			}
			
			numberStatus[cnt-1]=i*n_size+j;
			bingoBoard[i][j]=cnt++;
		}
}
void bingo_print(void){
	int i,j;
	
	
	printf("============================\n");
	for(i=0;i<n_size;i++){
		for(j=0;j<n_size;j++){
			if(bingoBoard[i][j]==bingo_hole)
				printf("X\t");
			else	
				printf("%i\t",bingoBoard[i][j]);
		}
		printf("\n");
	
	}
	printf("============================\n");
}
void bingo_inputNum(int sel){
	int i,j;
	
	i=numberStatus[sel-1]/n_size;
	j=numberStatus[sel-1]%n_size;
	bingoBoard[i][j]=bingo_hole;
	numberStatus[sel-1]=bingo_hole;
}
int bingo_countCompletedLine(void){
	
}

