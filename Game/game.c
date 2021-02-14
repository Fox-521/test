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
		//��ӡһ������
			//printf("  % c|  %c|   %c\n",board[i][0],board[i][1],board[i][2]);
		for (int j = 0; j < col; j++) {
			printf(" %c ",board[i][j]);
			if (j < col - 1)//�ж�Ҫ��Ҫ��ӡ���һ��|
				printf("|");
	  }
		printf("\n");
			//��ӡ�ָ���
		if (i < row - 1) {//�ж�Ҫ��Ҫ��ӡ���һ���ָ���---
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
	printf("����ߣ�>\n");
	while (1) {
		printf("������Ҫ�µ����꣺>");
		scanf("%d%d",&x,&y);
		//�ж�x y����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;//������ѭ��
			}
			else {
				printf("�����걻ռ��\n");
			}
		}
		else {
			printf("������Ƿ������������룡\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("�����ߣ�>\n");
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
{//������
	for (int i = 0; i < row; i++) {
		if (board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][1]!=' ') {
			return board[i][1];
		}
	}
//������
	for (int i = 0; i < col; i++) {
		if (board[0][i] == board[1][i]&&board[1][i] == board[2][i] && board[1][i] != ' ') {
			return board[1][i];
		}
	}

//�Խ���
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
//����1��ʾ��������
//����0����ʾ����û��
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;//û��
			}
		}
	}
	return 1;
}

