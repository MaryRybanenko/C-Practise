#include "first_animation.h"

void placeSymbols(int arrLeter[][10], int col, int row, int x, int y)
{
	ConsoleColor color;
	for (int i = 0; i < col; i++)
	{
		GotoXY(x, y);
		for (int j = 0; j <= row; j++)
		{
			if (j == row)
			{
				y++;
			}
			else
			{
				if (arrLeter[i][j] == 0)
					cout << ' ';
				else
				{
					cout << (char)219;
					color = (ConsoleColor)randColorAnim();
					ChangeTextAttr(x, y, color, Black, 10);
				}
					
			}
		}
	}
}

void drawSomeColInSymb(int **arrLeter, int col, int rowFrom, int rowTo, int x, int y)
{
	int counter = 0;
	int inerX;
	ConsoleColor color;
	for (int i = 0; i < col; i++)
	{
		inerX = x;
		GotoXY(inerX, y);
		for (int j = rowFrom; j >= rowTo - 1; j--)
		{
			if (j == rowTo - 1)
			{
				y++;
			}
			else
			{
				if (arrLeter[i][j] == 0)
					WriteChar(inerX--, y, ' ');
				else
				{
					WriteChar(inerX--, y, (char)219);
					color = (ConsoleColor)randColorAnim();
					ChangeTextAttr(x, y, color, Black, 10);
				}
					
			}
		}
	}
}

int** drawMletter(int **getLetter)
{
	const int rowM = 10;
	const int colM = 10;
	int pictLetterM[colM][rowM] = {
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
		{ 1, 1, 0, 0, 1, 1, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
	};

	for (int i = 0; i < col3; i++)
	{
		for (int j = 0; j < row3; j++)
		{
			getLetter[i][j] = pictLetterM[i][j];
		}
	}

	return getLetter;

}

int** drawAletter(int **getLetter)
{
	const int rowA = 10;
	const int colA = 10;
	int pictLetterA[colA][rowA] = {
		{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 },
	};

	for (int i = 0; i < col3; i++)
	{
		for (int j = 0; j < row3; j++)
		{
			getLetter[i][j] = pictLetterA[i][j];
		}
	}

	return getLetter;
}

int** drawTletter(int **getLetter)
{
	const int rowT = 10;
	const int colT = 10;
	int pictLetterT[colT][rowT] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 1, 1, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
	};

	for (int i = 0; i < col3; i++)
	{
		for (int j = 0; j < row3; j++)
		{
			getLetter[i][j] = pictLetterT[i][j];
		}
	}

	return getLetter;
}

int** drawCletter(int **getLetter)
{
	const int rowÑ = 10;
	const int colÑ = 10;
	int pictLetterÑ[colÑ][rowÑ] = {
		{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 },
		{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
	};

	for (int i = 0; i < col3; i++)
	{
		for (int j = 0; j < row3; j++)
		{
			getLetter[i][j] = pictLetterÑ[i][j];
		}
	}

	return getLetter;
}

int** drawHletter(int **getLetter)
{
	const int rowH = 10;
	const int colH = 10;
	int pictLetterH[colH][rowH] = {
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
	};

	for (int i = 0; i < col3; i++)
	{
		for (int j = 0; j < row3; j++)
		{
			getLetter[i][j] = pictLetterH[i][j];
		}
	}

	return getLetter;
}

int** draw3Number(int **getLetter)
{
	const int row3 = 10;
	const int col3 = 10;
	int pictLetter3[col3][row3] = {
		{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 0, 0, 1, 1, 0 },
		{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
	};

	for (int i = 0; i < col3; i++)
	{
		for (int j = 0; j < row3; j++)
		{
			getLetter[i][j] = pictLetter3[i][j];
		}
	}
	
	return getLetter;
}



void wipeLettersSlowly(int x, int y)
{
	Sleep(1500);
	for (int i = 0; i < 11; i++)
	{
		GotoXY(x, y);
		WriteChars(x, y, ' ', 75);
		Sleep(50);
		y++;
	}

}


void drawRect(int lux, int luy, int rdx, int rdy)
{
	int y;
	int x;
	ConsoleColor color;
	for (x = rdx; x >= lux; x--)
	{

		for (y = luy; y <= rdy; y++)
		{
			GotoXY(x, y);
			cout << (char)219;
			color = (ConsoleColor)randColorAnim();
			ChangeTextAttr(x, y, color, Black, 1);
			Sleep(5);
		}
	}
}

void wipeRectRightSide(int lux, int luy, int rdx, int rdy)
{
	int y;
	int x;
	int col = 10;
	int **b;
	int inerY = 5;
	int startX;

	int** a = new int*[col];
	for (int k = 0; k < col; k++)
		a[k] = new int[col];


	for (x = rdx; x >= lux; x--)
	{
		for (y = luy; y <= rdy; y++)
		{
			GotoXY(x, y);
			cout << ' ';
			Sleep(5);
		}
		
		if (x >= 60 && x <= 69)
		{  
			startX = 69;
			b = ptrLettersArray[5](a);

			if (x == startX - 1)
			{
				drawSomeColInSymb(b, col3, 9, 8, startX, inerY);
			}
			else if (x == startX - 2)
			{
				drawSomeColInSymb(b, col3, 8, 7, startX - 1, inerY);
			}
			else if (x == startX - 3)
			{
				drawSomeColInSymb(b, col3, 7, 6, startX - 2, inerY);
			}
			else if (x == startX - 4)
			{
				drawSomeColInSymb(b, col3, 6, 5, startX - 3, inerY);
			}
			else if (x == startX - 5)
			{
				drawSomeColInSymb(b, col3, 5, 4, startX - 4, inerY);
			}
			else if (x == startX - 6)
			{
				drawSomeColInSymb(b, col3, 4, 3, startX - 5, inerY);
			}
			else if (x == startX - 7)
			{
				drawSomeColInSymb(b, col3, 3, 2, startX - 6, inerY);
			}
			else if (x == startX - 8)
			{
				drawSomeColInSymb(b, col3, 2, 1, startX - 7, inerY);
			}
			else if (x == startX - 9)
			{
				drawSomeColInSymb(b, col3, 1, 0, startX - 8, inerY);
			}
		}
		else if ( x >= 50 && x <= 59)
		{
			startX = 59;
			b = ptrLettersArray[4](a);

			if (x == startX - 1)
			{
				drawSomeColInSymb(b, col3, 9, 8, startX, inerY);
			}
			else if (x == startX - 2)
			{
				drawSomeColInSymb(b, col3, 8, 7, startX - 1, inerY);
			}
			else if (x == startX - 3)
			{
				drawSomeColInSymb(b, col3, 7, 6, startX - 2, inerY);
			}
			else if (x == startX - 4)
			{
				drawSomeColInSymb(b, col3, 6, 5, startX - 3, inerY);
			}
			else if (x == startX - 5)
			{
				drawSomeColInSymb(b, col3, 5, 4, startX - 4, inerY);
			}
			else if (x == startX - 6)
			{
				drawSomeColInSymb(b, col3, 4, 3, startX - 5, inerY);
			}
			else if (x == startX - 7)
			{
				drawSomeColInSymb(b, col3, 3, 2, startX - 6, inerY);
			}
			else if (x == startX - 8)
			{
				drawSomeColInSymb(b, col3, 2, 1, startX - 7, inerY);
			}
			else if (x == startX - 9)
			{
				drawSomeColInSymb(b, col3, 1, 0, startX - 8, inerY);
			}


		}
		else if (x >= 40 && x <= 49)
		{
			startX = 49;
			b = ptrLettersArray[3](a);

			if (x == startX - 1)
			{
				drawSomeColInSymb(b, col3, 9, 8, startX, inerY);
			}
			else if (x == startX - 2)
			{
				drawSomeColInSymb(b, col3, 8, 7, startX - 1, inerY);
			}
			else if (x == startX - 3)
			{
				drawSomeColInSymb(b, col3, 7, 6, startX - 2, inerY);
			}
			else if (x == startX - 4)
			{
				drawSomeColInSymb(b, col3, 6, 5, startX - 3, inerY);
			}
			else if (x == startX - 5)
			{
				drawSomeColInSymb(b, col3, 5, 4, startX - 4, inerY);
			}
			else if (x == startX - 6)
			{
				drawSomeColInSymb(b, col3, 4, 3, startX - 5, inerY);
			}
			else if (x == startX - 7)
			{
				drawSomeColInSymb(b, col3, 3, 2, startX - 6, inerY);
			}
			else if (x == startX - 8)
			{
				drawSomeColInSymb(b, col3, 2, 1, startX - 7, inerY);
			}
			else if (x == startX - 9)
			{
				drawSomeColInSymb(b, col3, 1, 0, startX - 8, inerY);
			}
		}
		else if (x >= 30 && x <= 39)
		{
			startX = 39;
			b = ptrLettersArray[2](a);

			if (x == startX - 1)
			{
				drawSomeColInSymb(b, col3, 9, 8, startX, inerY);
			}
			else if (x == startX - 2)
			{
				drawSomeColInSymb(b, col3, 8, 7, startX - 1, inerY);
			}
			else if (x == startX - 3)
			{
				drawSomeColInSymb(b, col3, 7, 6, startX - 2, inerY);
			}
			else if (x == startX - 4)
			{
				drawSomeColInSymb(b, col3, 6, 5, startX - 3, inerY);
			}
			else if (x == startX - 5)
			{
				drawSomeColInSymb(b, col3, 5, 4, startX - 4, inerY);
			}
			else if (x == startX - 6)
			{
				drawSomeColInSymb(b, col3, 4, 3, startX - 5, inerY);
			}
			else if (x == startX - 7)
			{
				drawSomeColInSymb(b, col3, 3, 2, startX - 6, inerY);
			}
			else if (x == startX - 8)
			{
				drawSomeColInSymb(b, col3, 2, 1, startX - 7, inerY);
			}
			else if (x == startX - 9)
			{
				drawSomeColInSymb(b, col3, 1, 0, startX - 8, inerY);
			}
		}
		else if ( x >= 20 && x <= 29)
		{
			startX = 29;
			b = ptrLettersArray[1](a);

			if (x == startX - 1)
			{
				drawSomeColInSymb(b, col3, 9, 8, startX, inerY);
			}
			else if (x == startX - 2)
			{
				drawSomeColInSymb(b, col3, 8, 7, startX - 1, inerY);
			}
			else if (x == startX - 3)
			{
				drawSomeColInSymb(b, col3, 7, 6, startX - 2, inerY);
			}
			else if (x == startX - 4)
			{
				drawSomeColInSymb(b, col3, 6, 5, startX - 3, inerY);
			}
			else if (x == startX - 5)
			{
				drawSomeColInSymb(b, col3, 5, 4, startX - 4, inerY);
			}
			else if (x == startX - 6)
			{
				drawSomeColInSymb(b, col3, 4, 3, startX - 5, inerY);
			}
			else if (x == startX - 7)
			{
				drawSomeColInSymb(b, col3, 3, 2, startX - 6, inerY);
			}
			else if (x == startX - 8)
			{
				drawSomeColInSymb(b, col3, 2, 1, startX - 7, inerY);
			}
			else if (x == startX - 9)
			{
				drawSomeColInSymb(b, col3, 1, 0, startX - 8, inerY);
			}
		}
		else if (x >= 9 && x <= 19) 
		{
			startX = 19;
			b = ptrLettersArray[0](a);

			if (x == startX - 1)
			{
				drawSomeColInSymb(b, col3, 9, 8, startX, inerY);
			}
			else if (x == startX - 2)
			{
				drawSomeColInSymb(b, col3, 8, 7, startX - 1, inerY);
			}
			else if (x == startX - 3)
			{
				drawSomeColInSymb(b, col3, 7, 6, startX - 2, inerY);
			}
			else if (x == startX - 4)
			{
				drawSomeColInSymb(b, col3, 6, 5, startX - 3, inerY);
			}
			else if (x == startX - 5)
			{
				drawSomeColInSymb(b, col3, 5, 4, startX - 4, inerY);
			}
			else if (x == startX - 6)
			{
				drawSomeColInSymb(b, col3, 4, 3, startX - 5, inerY);
			}
			else if (x == startX - 7)
			{
				drawSomeColInSymb(b, col3, 3, 2, startX - 6, inerY);
			}
			else if (x == startX - 8)
			{
				drawSomeColInSymb(b, col3, 2, 1, startX - 7, inerY);
			}
			else if (x == startX - 9)
			{
				drawSomeColInSymb(b, col3, 1, 0, startX - 8, inerY);
			}
		}
	}

	for (int h = 0; h < col; h++)
		delete[] a[h];

	delete[] a;

}

void drawFirstAnimation()
{
	drawRect(5, 5, 70, 15);
	wipeRectRightSide(5, 5, 70, 15);
	wipeLettersSlowly(5, 5);
}
