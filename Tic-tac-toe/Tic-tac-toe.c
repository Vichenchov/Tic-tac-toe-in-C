#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define R 3
#define C 3

void printBoards(char board[][C]);
void turn(int num, char board[][C], char s);
char sign(int* num);
int ifAlreadySignedPlace(int placeValue);
void replayTurn(char board[][C], char s);
int ifWin(char board[][C]);

void main() {
	int num, w = 0, countRound = 0, next;
	char Board[R][C] = { '7','8','9',
						 '4','5','6',
						 '1','2','3' }, s;

	printf("\033[0m Choose a number to replace it with X sign... (X starts)\n");
	printBoards(Board);

	while (countRound != 9) {
		scanf_s("%d", &num);
		s = sign(&countRound);
		turn(num, Board, s);
		printBoards(Board);
		if (countRound >= 5) {
			if (ifWin(Board) == 1) {
				w = 1;
				break;
			}
		}
		printf("\033[0m Next round...\n\n");
	}

	!w ? printf("\033[0m It's a draw.\n\n") : printf("\033[0m %c won!!!\n\n", s);

	printf("\033[0m press 1 to play again or any key to exit...");
	scanf_s("%d", &next);
	if (next == 1)
		main();
}

//checks if someone won
int ifWin(char board[][C]) {
	for (int i = 0; i < C; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
	return 0;
}

//replay turn if the player choose signed place
void replayTurn(char board[][C], char s) {
	int newNum;
	printf("\n");
	printf("\033[0m Already chosen place, play again...\n");
	scanf_s("%d", &newNum);
	turn(newNum, board, s);
}

//checks if the chosen place has been signed already
int ifAlreadySignedPlace(int placeValue) {
	if (placeValue == 'X' || placeValue == 'O')
		return 1;
	return 0;
}

//chooses the correct sign of each round
char sign(int* countRound) {
	return ++ * countRound % 2 == 0 ? 'O' : 'X';
}

//changes the chosen number with the correct sign
void turn(int num, char board[][C], char s) {
	switch (num)
	{
	case 1:
		!ifAlreadySignedPlace(board[2][0]) ? board[2][0] = s : replayTurn(board, s);
		break;
	case 2:
		!ifAlreadySignedPlace(board[2][1]) ? board[2][1] = s : replayTurn(board, s);
		break;
	case 3:
		!ifAlreadySignedPlace(board[2][2]) ? board[2][2] = s : replayTurn(board, s);
		break;
	case 4:
		!ifAlreadySignedPlace(board[1][0]) ? board[1][0] = s : replayTurn(board, s);
		break;
	case 5:
		!ifAlreadySignedPlace(board[1][1]) ? board[1][1] = s : replayTurn(board, s);
		break;
	case 6:
		!ifAlreadySignedPlace(board[1][2]) ? board[1][2] = s : replayTurn(board, s);
		break;
	case 7:
		!ifAlreadySignedPlace(board[0][0]) ? board[0][0] = s : replayTurn(board, s);
		break;
	case 8:
		!ifAlreadySignedPlace(board[0][1]) ? board[0][1] = s : replayTurn(board, s);
		break;
	case 9:
		!ifAlreadySignedPlace(board[0][2]) ? board[0][2] = s : replayTurn(board, s);
		break;
	default:
		break;
	}
}

//print boards
void printBoards(char board[][C]) {
	printf("\n");
	for (int i = 0; i < R; i++)
	{
		for (int y = 0; y < C; y++)
		{
			if (board[i][y] == 'X') {
				printf("\033[0;31m %c", board[i][y]);
			}
			else {
				if(board[i][y] == 'O'){
					printf("\033[0;32m %c", board[i][y]);
				}
				else {
					printf("\033[0m %c", board[i][y]);
				}
			}
			if (y < 2)
				printf("\033[0m | ");
		}
		printf("\n");
		if (i != 2) {
			for (int z = 0; z < 3; z++)
			{
				printf("\033[0m ___");
			}
			printf("\n");
		}
		printf("\n");
	}
}

