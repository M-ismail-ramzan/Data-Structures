#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

void print_board(int row, int col) {
	// printing the Board
	for (size_t i = 0; i < row; i++)
	{
		for (size_t i = 0; i < col; i++)
		{
			cout << "  *  ";
		}
		cout << "\n";
	}
}

void generate_snake(string board[][10], int row, int col) {
	int snakes[3][2];
	// Generating the head and tail & snakes
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			snakes[i][j] = rand() % 10;
		}
		while (snakes[i][0] == snakes[i][1]) {
			snakes[i][0] = rand() % 10;
		}
		if (snakes[i][0] < snakes[i][1]) {
			int temp = snakes[i][1];
			snakes[i][1] = snakes[i][0];
			snakes[i][0] = temp;
		}
	}

	// Location of each Snake is!
	for (size_t i = 0; i < 3; i++)
	{
		cout << " Snake No" << i << "  Head Location: " << snakes[i][0] << " Tail Location: " << snakes[i][1];
		cout << "\n";
	}

	cout << "\n   Snakes on Board   \n";
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << "  *  ";

			//printing the snakes on board
			if (snakes[i][0] == i && snakes[i][0] == j) {
				cout << "  S  ";
			}
		}
	}

}

// generate_ladder
void generate_ladder(string board[][10], int row, int col) {
	int ladder[3][2];
	// Generating the head and tail & ladder
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			ladder[i][j] = rand() % 10;
		}
		while (ladder[i][0] == ladder[i][1]) {
			ladder[i][0] = rand() % 10;
		}
		if (ladder[i][0] > ladder[i][1]) {
			int temp = ladder[i][1];
			ladder[i][1] = ladder[i][0];
			ladder[i][0] = temp;
		}


	}

	// Location of each Ladder is!
	for (size_t i = 0; i < 3; i++)
	{
		cout << " Ladder No" << i << "  Head Location: " << ladder[i][0] << " Tail Location: " << ladder[i][1];
		cout << "\n";
	}


	cout << "\n   Ladder on Board   \n";
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << "  *  ";

			//printing the snakes on board
			if (ladder[i][0] == i && ladder[i][0] == j) {
				cout << "  L  ";
			}
		}
	}
}

int main() {
	srand((time(NULL)));
	// making a 2d array
	const int row = 10;
	const int col = 10;
	string board[row][col];
	print_board(row, col);
	generate_snake(board, row, col);
	generate_ladder(board, row, col);
}