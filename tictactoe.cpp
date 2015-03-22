#include <iostream>
#include <cmath> 
#include <cstdlib>

using namespace std;

void printBoard(char board[3][3])
{
	cout << "   1 2 3" << endl;;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			
			if (j == 1 || j == 0)
			{
				if (j == 0)
				{
					cout << i + 1 <<"  "<< board[i][j];
				}
				else
				{
					cout << board[i][j];
				}
				cout << "|";
			}
			else
			{
				cout << board[i][j];
			}
		}
		cout << endl;
		if (i == 0 || i == 1)
		{
			cout << "  -------" << endl;
		}
	}
}

void setBoard(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}

char checkWin(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][1] != ' '))
		{
			return board[i][0];
		}
		if (((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && board[1][i] != ' '))
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	return ' ';
}


int main()
{
	cout << "time to play tic tac toe" << endl;
	char board[3][3];
	setBoard(board);
	printBoard(board);
	bool gameplay = true; 
	int num_of_players = 0; 
	int player_order = 0; 
	int turn = 0;
	int row = 0;
	int col = 0; 
	char x = 'X';
	char o = 'O';
	char play = ' ';
	char comp_play = ' ';
	
	while (gameplay)
	{
		if (turn % 2 == 0)
		{
			play = x;
		}
		else
		{
			play = o;
		}
		cout << "what row and column would you like to play an " << play << " ?" << endl;
		cin >> row; 
		cin >> col;
		row--;
		col--;
		if (row < 0 || row > 2 || col < 0 || col > 2)
		{
			cout << "cant compute that, try again" << endl;
		}
		else
		{
			if (board[col][row] == ' ')
			{
				board[col][row] = play;
				printBoard(board);
				turn++;
				char winner = checkWin(board);
				if (winner == 'X')
				{
					cout << "Player X wins" << endl;
					cout << "if you want to play again type 1"<<endl;
					cin>>gameplay;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							board[i][j] = ' '; 
						}
					}
					turn = 0;
					if(gameplay != 1)
					{
						gameplay = false;
					}
				}
				if (winner == 'O')
				{
					cout << "Player O wins" << endl;
					cout << "if you want to play again type 1"<<endl;
					cin>>gameplay;
					turn = 0; 
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							board[i][j] = ' '; 
						}
					}
					if(gameplay != 1)
					{
						gameplay = false;
					}
				}
			}
			else
			{
				cout << "thats an invalid move" << endl;
			}
		}		
	}
	return 0;
}
