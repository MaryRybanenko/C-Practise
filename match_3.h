#include<iostream>
#include<ctime>
#include<conio.h>
#include "first_animation.h"


#include"ConsoleLib.h"

using namespace std;

struct sElemInfo
{
	int x;
	int y;
	int color;
};

enum eDirections
{
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3,
	UP = 4
};

////////////global variables////////////
static const int strSize = 64;
//static sElemInfo allElements[strSize];
static int fieldSize = 8;
static int color;
///////////////////////////////////////

/////////var_for_drawing_buttons//////
static const unsigned char LeftTop = 201;
static const unsigned char Horz = 205;
static const unsigned char Vert = 186;
static const unsigned char RightTop = 187;
static const unsigned char LeftBottom = 200;
static const unsigned char RightBottom = 188;
//////////////////////////////////////

//////arrays for detecting matching elements
//seq. type 1:
//X
//X
//0X
static int arr1[2] = { -17, -9 };
//seq. type 2:
//0X
//0X
//X
static int arr2[2] = { -15, -7 };
//seq. type 3:
//X
//0X
//0X
static int arr3[2] = { 9, 17 };
//seq. type 4:
//0X
//X
//X
static int arr4[2] = { 7, 15 };
//seq. type 5:
//X
//0X
//X
static int arr5[2] = { -9, 7 };
//seq. type 6:
//0X
//X
//0X
static int arr6[2] = { -7, 9 };
//seq. type 7:
// X
//X X 
static int arr7[2] = { 7, 9 };
//seq. type 8:
//X X
// X 
static int arr8[2] = { -9, -7 };
//seq. type 9:
// XX
//X 
static int arr9[2] = { -6, -7 };
//seq. type 10:
//XX
//  X 
static int arr10[2] = { -9, -10 };
//seq. type 11:
//X
// XX 
static int arr11[2] = { 9, 10 };
//seq. type 12:
//  X
//XX 
static int arr12[2] = { 6, 7 };
//seq. type 13:
//XX0X
static int arr13[2] = { -3, -2 };
//seq. type 14:
//X0XX
static int arr14[2] = { 2, 3 };
//seq. type 15:
//X
//X
//0
//X
static int arr15[2] = { -16, -24};
//seq. type 16:
//X
//0
//X
//X
static int arr16[2] = { 16, 24 };


//////////////////////////////////////////

/*********************management*******************************************/

//generate random color
inline int randColor()
{
	return 1 + rand() % 4;
}

//generate information for each element
void getInfo(int &srcX, int &srcY, int &color, bool newLine);
//assigns value for each element of structure sElemeInfo
void initElem(int x, int y, int color, sElemInfo *src, int indexSrc);
//return mouse-clicked position
int  getPressedPos(int &srcX, int &srcY);
//return position after mouse-moving with clicked left button
int  getMovedPos(int &srcX, int &srcY);
//detecting direction of mouse-moving 
int dirDetectMouse(int &startX, int &startY, int &finishX, int &finishY);
//if element was pressed, return it index
int detectPressedElemIndex(sElemInfo *src, int pressedX, int pressedY);
//find 2 remained elements for full match3 sequence
int defineMatchedColorSeq(sElemInfo *src, int presIndex, int direction);
//return 2 left elements from sequences
void indexesOfLeftElements(int sequencNumber, int baseIndex, int &nextInd1, int &nextInd2);
//set new colors for elements
void setNewColors(sElemInfo *src, int ind1, int ind2, int ind3);

//return true if at least one sequence found
bool checkExistenceOfSequence(sElemInfo *src);
//return indexes of new sequences if function checkExistenceOfSequence didn`t find any sequences for matching
void generateRandomSequence(int &ind1, int &ind2, int &ind3);
// generate one random color and change value of elements by indexes
void setTheSameColors(sElemInfo *src, int ind1, int ind2, int ind3);
//it`s generateRandomSequence + setTheSameColors
void createNewSequence(sElemInfo *src);
// save player name
void getName(char *name);
//set time in pos (x, y)
void timer(int x, int y, int &minutes);


/*********************rendering*******************************************/

//draw one element
void drawElement(int x, int y, int color);
//draw all elements use structure info
void drawAllElemFromStruct(sElemInfo *src);
// draw elements with new colors
void drawElemWithNewColors(sElemInfo *src, int ind1, int ind2, int ind3);
// draw button without lable
void drawMenuButton(int startPosX, int startPosY);
// draw button as a pressed
void drawPressedButton(int startPosX, int startPosY);
//additional field for score/massages/timer 
void drawMassageBox(int startPosX, int startPosY);
//set lable 
void setLable(int destPosX, int destPosY, char* lable);
//set pressed lable 
void setPressedLable(int destPosX, int destPosY, char* lable);
// wipe off element on position (wipeX, wipeY);
void wipeElem(int wipeX, int wipeY);
//wipe 3 elements with indexes 
int wipe3Elements(sElemInfo *src, int ind1, int ind2, int ind3);
//draw pressed button - back to main menu 
void butBackPressed(int posX, int posY);
//draw pressed button EXIT
void butExitPressed(int posX, int posY);
//check, if user click out of game field
bool checkClickDiapason(sElemInfo *src, int pressX, int pressY);

//return index of element from structure by coordinate values
int getIndexbyXYVal(sElemInfo *src, int x, int y);
//check if elements with flashed values of indexes has the same values of color
bool ifColorsMatch(sElemInfo *src, int ind1, int ind2, int ind3);
//check the sequences of elements that shouldn`t be the same
void checkUnplanedMatches(sElemInfo *src, int baseElemInd);

//1.draw button - back to main menu 
void ButBack(int posX, int posY);
//2. draw button exit
void butExit(int posX, int posY);
//3. draw field where it will be displayed score
void scoreField();
//4. draw field for same massages
void messageField();
//5. field for timer
void timerField();
//6. all functions from 1 to 5 
void allInterfaceForGame();

//draw all that needed for main menu
void mainMenuInterface();

//1. draw score table
void scoreTable(int &startPosX, int &startPosY);
//2. draw start of table
void titleScoreTable(int &startPosX, int &startPosY);
//3. draw next field for score remembering
void chainScoreTable(int &startPosX, int &startPosY);
//4. end of score table
void endScoreTable(int &startPosX, int &startPosY);
//5. all table - ???
void drawTableForScore();
//6. table with buttons
void allInterfaceForScore();

//
void scoreMessage(int score);

/*********************common functions*******************************************/

//create field of random elements, if no matches make 2 sequences
void formFieldofRandElem(sElemInfo *src, bool ifNoMatches);
//change color (also in struct. data) between elements
void changeColorAndDraw(sElemInfo *src, int pressedIndex, int nextIndex);
//checks on mismatching contiguous going elements
void checkAllField(sElemInfo *src);
//in order to reach this window press start
void gameCycle(int &score);
// get pressed position from the main menu and redraw buttons as a pressed
void pressedMainMenuItem(int &outerX, int &outerY);
//re
void allForMainMenu(int &x, int &y);
//fixes keystroke for score window
void keyForScoreWindow();

