#include"match_3.h"

void drawElement(int x, int y, int color)
{
	char element = 219;
	GotoXY(x, y);
	cout << element;
	ChangeTextAttr(x, y, (ConsoleColor)color, Black, 1);
}

void drawAllElemFromStruct(sElemInfo *src)
{
	for (int i = 0; i < strSize; i++)
	{
		drawElement(src[i].x, src[i].y, src[i].color);
	}
}

void wipeElem(int wipeX, int wipeY)
{
	GotoXY(wipeX, wipeY);
	cout << ' ';
}

int wipe3Elements(sElemInfo *src, int ind1, int ind2, int ind3)
{
	Sleep(300);
	wipeElem(src[ind1].x, src[ind1].y);
	wipeElem(src[ind2].x, src[ind2].y);
	wipeElem(src[ind3].x, src[ind3].y);

	return 1;
}

void drawElemWithNewColors(sElemInfo *src, int ind1, int ind2, int ind3)
{
	Sleep(300);
	drawElement(src[ind1].x, src[ind1].y, src[ind1].color);
	drawElement(src[ind2].x, src[ind2].y, src[ind2].color);
	drawElement(src[ind3].x, src[ind3].y, src[ind3].color);
}

void drawMenuButton(int startPosX, int startPosY)
{
	int widthBut = 14;
	WriteChar(startPosX, startPosY, LeftTop);
	WriteChars(startPosX + 1, startPosY, Horz, widthBut-1);
	WriteChar(startPosX + widthBut, startPosY, RightTop);

	WriteChar(startPosX, ++startPosY, Vert);
	WriteChars(startPosX + 1, startPosY, ' ', widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, Vert);

	WriteChar(startPosX, ++startPosY, LeftBottom);
	WriteChars(startPosX + 1, startPosY, Horz, widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, RightBottom);
}

void drawPressedButton(int startPosX, int startPosY)
{
	int widthBut = 14;
	WriteChar(startPosX, startPosY, LeftTop);
	ChangeTextAttr(startPosX, startPosY, DarkGray, Black, widthBut + 1);
	WriteChars(startPosX + 1, startPosY, Horz, widthBut - 1);
	ChangeTextAttr(startPosX, startPosY, DarkGray, Black, widthBut + 1);
	WriteChar(startPosX + widthBut, startPosY, RightTop);
	ChangeTextAttr(startPosX, startPosY, DarkGray, Black, widthBut + 1);


	WriteChar(startPosX, ++startPosY, Vert);
	ChangeTextAttr(startPosX, startPosY, DarkGray, Black, widthBut + 1);
	WriteChars(startPosX + 1, startPosY, ' ', widthBut - 1);
	ChangeTextAttr(startPosX, startPosY, DarkGray, Black, widthBut + 1);
	WriteChar(startPosX + widthBut, startPosY, Vert);
	ChangeTextAttr(startPosX, startPosY, DarkGray, Black, widthBut + 1);


	WriteChar(startPosX, ++startPosY, LeftBottom);
	ChangeTextAttr(startPosX, startPosY, DarkGray, Black, widthBut + 1);
	WriteChars(startPosX + 1, startPosY, Horz, widthBut - 1);
	ChangeTextAttr(startPosX, startPosY, DarkGray, Black, widthBut + 1);
	WriteChar(startPosX + widthBut, startPosY, RightBottom);
	ChangeTextAttr(startPosX, startPosY, DarkGray, Black, widthBut + 1);

}

void drawMassageBox(int startPosX, int startPosY)
{
	int widthBut = 14;
	WriteChar(startPosX, startPosY, LeftTop);
	WriteChars(startPosX + 1, startPosY, Horz, widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, RightTop);

	WriteChar(startPosX, ++startPosY, Vert);
	WriteChars(startPosX + 1, startPosY, ' ', widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, Vert);

	WriteChar(startPosX, ++startPosY, Vert);
	WriteChars(startPosX + 1, startPosY, ' ', widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, Vert);

	WriteChar(startPosX, ++startPosY, Vert);
	WriteChars(startPosX + 1, startPosY, ' ', widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, Vert);

	WriteChar(startPosX, ++startPosY, LeftBottom);
	WriteChars(startPosX + 1, startPosY, Horz, widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, RightBottom);
}


void setLable(int destPosX, int destPosY, char* lable)
{
	GotoXY(destPosX, destPosY);
	cout << lable;
}

void setPressedLable(int destPosX, int destPosY, char* lable)
{
	GotoXY(destPosX, destPosY);
	cout << lable;
	ChangeTextAttr(destPosX, destPosY, DarkGray, Black, 15);

}

void ButBack(int posX, int posY)
{
	drawMenuButton(posX, posY);
	setLable(posX + 5, posY + 1, "BACK");
}

void butBackPressed(int posX, int posY)
{
	drawPressedButton(posX, posY);
	setPressedLable(posX + 5, posY + 1, "BACK");
}

void butExit(int posX, int posY)
{
	drawMenuButton(posX, posY);
	setLable(posX + 5, posY + 1, "EXIT");
}

void butExitPressed(int posX, int posY)
{
	drawPressedButton(posX, posY);
	setPressedLable(posX + 5, posY + 1, "EXIT");
}

void scoreField()
{
	int x = 5;
	int y = 5;
	drawMassageBox(x, y);
	setLable(x + 4, y + 1, "Score");
}

void messageField()
{
	int x = 5;
	int y = 10;
	drawMassageBox(x, y);
	setLable(x + 3, y + 1, "Message");
}

void timerField()
{
	int x = 5;
	int y = 15;
	drawMassageBox(x, y);
	setLable(x + 5, y + 1, "Time");
}

void allInterfaceForGame()
{
	scoreField();
	messageField();
	//timerField();
	ButBack(50, 4);
	butExit(50, 7);
}

void mainMenuInterface()
{
	int x = 25;
	int y = 10;

	drawMenuButton(x, y);
	setLable(x+4, y+1, "START");

	drawMenuButton(x, y+5);
	setLable(x+4, y+6, "SCORE");

	drawMenuButton(x, y+10);
	setLable(x+5, y+11, "EXIT");

}

void pressedMainMenuItem(int &outerX, int &outerY)
{
	int inerX;
	int inerY;
	getPressedPos(inerX, inerY);

	int x = 25;
	int y = 10;

	if ( inerX >= 25 && inerX <= 40 && inerY >= 10 && inerY <= 14)
	{
		drawPressedButton(x, y);
		setPressedLable(x + 4, y + 1, "START");

		outerX = inerX;
		outerY = inerY;
	}
	if (inerX >= 25 && inerX <= 40 && inerY >= 15 && inerY <= 19)
	{
		drawPressedButton(x, y + 5);
		setPressedLable(x + 4, y + 6, "SCORE");

		outerX = inerX;
		outerY = inerY;
	}
	if (inerX >= 25 && inerX <= 40 && inerY >= 20 && inerY <= 24)
	{
		drawPressedButton(x, y + 10);
		setPressedLable(x + 5, y + 11, "EXIT");

		outerX = inerX;
		outerY = inerY;
	}
}

void scoreTable(int &startPosX, int &startPosY)
{
	int widthBut = 20;
	WriteChar(startPosX, startPosY, LeftTop);
	WriteChars(startPosX + 1, startPosY, Horz, widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, RightTop);

	WriteChar(startPosX, ++startPosY, Vert);
	WriteChars(startPosX + 1, startPosY, ' ', widthBut - 1);
	WriteChar(startPosX + (widthBut - 7), startPosY-1, (char)203);
	WriteChar(startPosX + (widthBut - 7), startPosY, Vert);
	WriteChar(startPosX + widthBut, startPosY, Vert);


	WriteChar(startPosX, ++startPosY, LeftBottom);
	WriteChars(startPosX + 1, startPosY, Horz, widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, RightBottom);
	WriteChar(startPosX + (widthBut - 7), startPosY, (char)202);

}
void titleScoreTable(int &startPosX, int &startPosY)
{
	int widthBut = 20;
	WriteChar(startPosX, startPosY, LeftTop);
	WriteChars(startPosX + 1, startPosY, Horz, widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, RightTop);

	WriteChar(startPosX, ++startPosY, Vert);
	WriteChars(startPosX + 1, startPosY, ' ', widthBut - 1);
	WriteChar(startPosX + (widthBut - 7), startPosY - 1, (char)203);
	WriteChar(startPosX + (widthBut - 7), startPosY, Vert);
	WriteChar(startPosX + widthBut, startPosY, Vert);


	WriteChar(startPosX, ++startPosY, (char)204);
	WriteChars(startPosX + 1, startPosY, Horz, widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, (char)185);
	WriteChar(startPosX + (widthBut - 7), startPosY, (char)206);

}
void chainScoreTable(int &startPosX, int &startPosY)
{
	int widthBut = 20;

	WriteChar(startPosX, ++startPosY, Vert);
	WriteChars(startPosX + 1, startPosY, ' ', widthBut - 1);
	WriteChar(startPosX + (widthBut - 7), startPosY - 1, (char)206);
	WriteChar(startPosX + (widthBut - 7), startPosY, Vert);
	WriteChar(startPosX + widthBut, startPosY, Vert);


	WriteChar(startPosX, ++startPosY, (char)204);
	WriteChars(startPosX + 1, startPosY, Horz, widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, (char)185);
	WriteChar(startPosX + (widthBut - 7), startPosY, (char)206);

}

void endScoreTable(int &startPosX, int &startPosY)
{
	int widthBut = 20;

	WriteChar(startPosX, ++startPosY, Vert);
	WriteChars(startPosX + 1, startPosY, ' ', widthBut - 1);
	WriteChar(startPosX + (widthBut - 7), startPosY - 1, (char)206);
	WriteChar(startPosX + (widthBut - 7), startPosY, Vert);
	WriteChar(startPosX + widthBut, startPosY, Vert);


	WriteChar(startPosX, ++startPosY, LeftBottom);
	WriteChars(startPosX + 1, startPosY, Horz, widthBut - 1);
	WriteChar(startPosX + widthBut, startPosY, RightBottom);
	WriteChar(startPosX + (widthBut - 7), startPosY, (char)202);

}

void drawTableForScore()
{
	int scx = 25;
	int scy = 10;

	titleScoreTable(scx, scy);
	endScoreTable(scx, scy);

	setLable(30, 11, "Name");
	setLable(39, 11, "Points");
}

void allInterfaceForScore()
{
	ButBack(50, 4);
	butExit(50, 7);
	drawTableForScore();
}

void scoreMessage(int score)
{
	int mx = 7;
	int my = 12;

	if (score == 5)
	{
		WriteStr(mx, my, "Good!!!");
	}
	else if (score == 10)
	{
		WriteStr(mx, my, "          ");
		WriteStr(mx, my, "Great!!!");
	}
	else if (score == 15)
	{
		WriteStr(mx, my, "            ");
		WriteStr(mx, my, "Wonderful!!!");
	}
	else if (score == 20)
	{
		WriteStr(mx, my, "                ");
		WriteStr(mx, my, "Incredibly!!!");
	}
}