#include"match_3.h"


void formFieldofRandElem(sElemInfo *src, bool ifNoMatches)
{
	int initX = 28;
	int initY = 8;

	int strInd = 0;
	for (int i = 0; i < fieldSize; i++)
	{
		for (int j = 0; j <= fieldSize; j++)
		{
			if (j == fieldSize)
			{
				getInfo(initX, initY, color, true);
			}
			else
			{
				getInfo(initX, initY, color, false);
				drawElement(initX, initY, color);
				initElem(initX, initY, color, src, strInd++);
			}
		}
	}

	if (ifNoMatches)
	{
		src[19].color = Red;
		src[27].color = Red;
		src[36].color = Red;

		src[49].color = Yellow;
		src[56].color = Yellow;
		src[58].color = Yellow;

		for (int i = 0; i < strSize; i++)
		{
			drawElement(src[i].x, src[i].y, src[i].color);

		}

	}
}

void checkAllField(sElemInfo *src)
{
	for (int i = 0; i < strSize; i++)
	{
		checkUnplanedMatches(src, i);
	}

	drawAllElemFromStruct(src);
}

void gameCycle(int &score)
{
	sElemInfo allElements[strSize];

	int pressX = 0;
	int pressY = 0;

	int moveX = 0;
	int moveY = 0;

	int pressedElem;
	int changeElem;

	int direction;
	int sequence;

	int nextInd1;
	int nextInd2;

	bool stopGame;
	int minutes = 0;

	int mx = 7;
	int my = 12;

	formFieldofRandElem(allElements, true);
	checkAllField(allElements);
	do
	{
		//timer(7, 18, minutes);
		stopGame = false;
		getPressedPos(pressX, pressY);
		if (pressX > 50 && pressX < 65 && pressY > 7 && pressY < 9)
		{
			stopGame = true;
			butExitPressed(50, 7);
			Sleep(200);
			exit(0);
		}
		if (pressX > 50 && pressX < 65 && pressY > 4 && pressY < 6)
		{
			stopGame = true;
			butBackPressed(50, 4);
			Sleep(200);
			break;
		}

		if (!checkClickDiapason(allElements, pressX, pressY))
		{
			
			WriteStr(mx, my, "No matches");
			Sleep(2000);
			WriteStr(mx, my, "          ");
			continue;
		}

		getMovedPos(moveX, moveY);

		if (!checkClickDiapason(allElements, moveX, moveY))
		{
			WriteStr(mx, my, "No matches");
			Sleep(2000);
			WriteStr(mx, my, "          ");
			continue;
		}

		pressedElem = detectPressedElemIndex(allElements, pressX, pressY);
		changeElem = detectPressedElemIndex(allElements, moveX, moveY);

		direction = dirDetectMouse(pressX, pressY, moveX, moveY);
		sequence = defineMatchedColorSeq(allElements, pressedElem, direction);
		if (sequence == -1)
		{
			WriteStr(mx, my, "No matches");
			Sleep(3000);
			WriteStr(mx, my, "          ");
			continue;
		}
		else
		{
			int x = 11;
			int y = 8;

			score++;
			WriteStr(x, y, "   ");
			GotoXY(x, y);
			cout << score;

			scoreMessage(score);
		}

		changeColorAndDraw(allElements, pressedElem, changeElem);

		indexesOfLeftElements(sequence, pressedElem, nextInd1, nextInd2);

		wipe3Elements(allElements, changeElem, nextInd1, nextInd2);
		setNewColors(allElements, changeElem, nextInd1, nextInd2);

		drawElemWithNewColors(allElements, changeElem, nextInd1, nextInd2);

		bool result = checkExistenceOfSequence(allElements);
		if (result == false)
		{
			createNewSequence(allElements);
			drawAllElemFromStruct(allElements);
		}

		checkAllField(allElements);
	} while (stopGame == false);
}

void allForMainMenu(int &x, int &y)
{
	mainMenuInterface();
	pressedMainMenuItem(x, y);
}

void keyForScoreWindow()
{
	int pressX = 0;
	int pressY = 0;

	while (true)
	{
		getPressedPos(pressX, pressY);
		if (pressX > 50 && pressX < 65 && pressY > 7 && pressY < 9)
		{
			butExitPressed(50, 7);
			Sleep(200);
			exit(0);
		}
		if (pressX > 50 && pressX < 65 && pressY > 4 && pressY < 6)
		{
			butBackPressed(50, 4);
			Sleep(200);
			return;
		}
	}
	
}


//for git practise