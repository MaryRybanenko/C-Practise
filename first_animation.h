#include"ConsoleLib.h"
#include<iostream>
#include <conio.h>
#include <time.h>


using namespace std;

static const int row3 = 10;
static const int col3 = 10;

//generate random color
inline int randColorAnim()
{
	return 1 + rand() % 15;
}

//draw symbols from array in position x, y, size of each leter 10X10
void placeSymbols(int arrLeter[][10], int col, int row, int x, int y);

//include massive that describe letter and function placeSymbols
int** drawMletter(int **getLetter);
int** drawAletter(int **getLetter);
int** drawTletter(int **getLetter);
int** drawCletter(int **getLetter);
int** drawHletter(int **getLetter);
int** draw3Number(int **getLetter);

//delete all symbols with sleep - 50 ms
void wipeLettersSlowly(int x, int y);

//draw rect. with different colors
void drawRect(int lux, int luy, int rdx, int rdy);

//wipe rect and draw letters slowly
void wipeRectRightSide(int lux, int luy, int rdx, int rdy);

//draw full first  animation
void drawFirstAnimation();

//draw letter by every col.
void drawSomeColInSymb(int **arrLeter, int col, int rowFrom, int rowTo, int x, int y);

//array of pointers to func. which returns letters
static int** (*ptrLettersArray[6]) (int **) =
{
	drawMletter,
	drawAletter,
	drawTletter,
	drawCletter,
	drawHletter,
	draw3Number
};