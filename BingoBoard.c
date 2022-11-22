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
	int i, j, k;
	int randNum;
	int maxNum=n_size*n_size;
	
	for(i=0;i<n_size*n_size;i++)
		numberStatus[i]=-1;
	
	for(i=0;i<n_size;i++){
		for(j=0;j<n_size;j++){
			randNum=rand()%maxNum;
			for (k=0;k<n_size*n_size;k++) 
			{
				if (numberStatus[k] == BINGO_NUMSTATUS_ABSENT )
				{
					if (randNum == 0)   
						break;
					else
						randNum--;  
				}
			}
			
			numberStatus[k] = i*n_size+j;
			bingoBoard[i][j]=k+1;
			maxNum--;
		}
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
	int i, j;
	int cnt=0;
	int checkBingo;
	
	//check rowÇà
	for(i=0;i<n_size;i++){
		checkBingo=1;
		for(j=0;j<n_size;j++){
			if(bingoBoard[i][j]>0){
				checkBingo=0;
				break;
			}
		}
		if(checkBingo==1){
		cnt++;
		}
	}
	//check column¿­
	for(j=0;j<n_size;j++){
		checkBingo=1;
		for(i=0;i<n_size;i++){
			if(bingoBoard[i][j]>0){
				checkBingo=0;
				break;
			}
		}
		if(checkBingo==1){
			cnt++;
		}
	} 
	checkBingo=1;
	for(i=0;i<n_size;i++){
		if(bingoBoard[i][i]>0){
			checkBingo=0;
			break;
		}
	}
	if(checkBingo==1){
		cnt++;
	}
	checkBingo=1;
	for(i=0;i<n_size;i++){
		if(bingoBoard[i][n_size-1-i]>0){
			checkBingo=0;
			break;
		}
	}
	if(checkBingo==1){
		cnt++;
	}
	return cnt;
}

