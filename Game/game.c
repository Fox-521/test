#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row;i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		//打印一行数据
			//printf("  % c|  %c|   %c\n",board[i][0],board[i][1],board[i][2]);
		for (int j = 0; j < col; j++) {
			printf(" %c ",board[i][j]);
			if (j < col - 1)//判断要不要打印最后一个|
				printf("|");
	  }
		printf("\n");
			//打印分割行
		if (i < row - 1) {//判断要不要打印最后一个分割行---
			for (int j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
			
	}

}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x=0,y=0;
	printf("玩家走：>\n");
	while (1) {
		printf("请输入要下的坐标：>");
		scanf("%d%d",&x,&y);
		//判断x y坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;//跳出死循环
			}
			else {
				printf("该坐标被占用\n");
			}
		}
		else {
			printf("该坐标非法，请重新输入！\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("电脑走：>\n");
	while (1) {
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{//横三行
	for (int i = 0; i < row; i++) {
		if (board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][1]!=' ') {
			return board[i][1];
		}
	}
//竖三行
	for (int i = 0; i < col; i++) {
		if (board[0][i] == board[1][i]&&board[1][i] == board[2][i] && board[1][i] != ' ') {
			return board[1][i];
		}
	}

//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (1 == IsFull(board, ROW, COL)) {
		return 'Q';
	}
	return'C';
}
//返回1表示棋盘满了
//返回0，表示棋盘没满
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;//没满
			}
		}
	}
	return 1;
}

