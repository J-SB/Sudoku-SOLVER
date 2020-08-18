#include <bits/stdc++.h>
using namespace std;

#define ZERO 0
#define N 9


bool findEmptyLocations(int board[N][N],int &row, int &col)
{
	for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
           if (board[row][col] == ZERO)
				return true;
        }
    }


	return false;
}


bool checkRow(int board[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
    {
        if (board[row][col] == num)
			return true;
    }

	return false;
}


bool checkCol(int board[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
    {
        if (board[row][col] == num)
			return true;
    }

	return false;
}


bool checkBox(int board[N][N], int startRow,int startCol, int num)
{
	for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row + startRow][col + startCol]== num)
				return true;
        }
    }


	return false;
}


bool isSafe(int board[N][N], int row,int col, int num)
{

	return !checkRow(board, row, num) && !checkCol(board, col, num) && !checkBox(board, row - row % 3,col - col % 3, num) && board[row][col] == ZERO;
}


void displayBoard(int board[N][N])
{
	for (int row = 0; row < N; row++)
         {
		   for (int col = 0; col < N; col++)
            {
            cout << board[row][col] << "|";
            }
          cout << endl;
          cout<<"------------------"<<endl;
         }


}




bool solveSudoku(int board[N][N])
{
	int row, col;

	if (!findEmptyLocations(board, row, col))
		return true;


	for (int num = 1; num <= 9; num++)
    {

		if (isSafe(board, row, col, num))
		{

			board[row][col] = num;

			if (solveSudoku(board))
				return true;

			board[row][col] = ZERO;
		}
	}

	return false;
}






void showInstructions()
{
    cout<<"Sudoku Solver"<<endl;
    cout<<"-------------"<<endl<<endl;
    cout<<"In this program given a 9*9 Sudoku board."<<endl;
    cout<<"The Backtracking Algorithm used in the code solves the board ."<<endl<<endl;
}



int main()
{

    showInstructions();

	int board[N][N]= {{ 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 8, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

     cout<<"Initial Board"<<endl;
     cout<<"------------------"<<endl;
     displayBoard(board);
     cout<<endl<<endl;


	if (solveSudoku(board) == true)
    {
        cout<<"Solved Board"<<endl;
        cout<<"------------------"<<endl;
        displayBoard(board);
    }

	else
		cout << "Sorry....this configuration is not solvable !!!!";

	return 0;
}
