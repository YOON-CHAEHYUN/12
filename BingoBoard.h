#define n_size 5
#define n_bingo 2
#define BINGO_NUMSTATUS_ABSENT -1
#define BINGO_NUMSTATUS_PRESENT 0



void bingo_init(void);
void bingo_print(void);
void bingo_inputNum(int sel);
int bingo_countCompletedLine(void);
