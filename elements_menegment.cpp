#include"match_3.h"

void getInfo(int &srcX, int &srcY, int &color, bool newLine)
{
	color = randColor();
	if (newLine)
	{
		srcY += 2;
		srcX = 28;
	}
	else
	{
		srcX += 2;
	}

}

void initElem(int x, int y, int color, sElemInfo *src, int indexSrc)
{
	src[indexSrc].x = x;
	src[indexSrc].y = y;
	src[indexSrc].color = color;
}


int  getPressedPos(int &srcX, int &srcY)
{
	DWORD dwOldMode, dwMode, dwNumRead;

	// Сохраняем текущий режим ввода для будущего восстановления при выходе из программы
	GetConsoleMode(hStdIn, &dwOldMode);
	// Включаем получение событий от мыши
	dwMode = ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdIn, dwMode);

	INPUT_RECORD irInBuf[128];
	char strBuffer[20];
	COORD mousePos;
	DWORD mouseButtonState;

	// Цикл обработки событий консоли
	while (1)
	{
		// Ожидание событий
		ReadConsoleInput(hStdIn, irInBuf, 128, &dwNumRead);

		// Обработка полученных событий
		for (DWORD i = 0; i < dwNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
				// События мыши
			case MOUSE_EVENT:
				//// Координаты мыши
				mousePos = irInBuf[i].Event.MouseEvent.dwMousePosition;

				//// Мышь переместили
				//if (irInBuf[i].Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
				//{
				//	sprintf(strBuffer, "[%2d, %2d]", mousePos.X, mousePos.Y);
				//	WriteStr(0, 0, strBuffer);
				//}

				// Состояние кнопок мыши
				mouseButtonState = irInBuf[i].Event.MouseEvent.dwButtonState;

				// Нажата левая кнопка мыши
				if (mouseButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					srcX = mousePos.X;
					srcY = mousePos.Y;
					return 1;
				}
			}
		}
	}
}

int  getMovedPos(int &srcX, int &srcY)
{
	DWORD dwOldMode, dwMode, dwNumRead;

	// Сохраняем текущий режим ввода для будущего восстановления при выходе из программы
	GetConsoleMode(hStdIn, &dwOldMode);
	// Включаем получение событий от мыши
	dwMode = ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdIn, dwMode);

	INPUT_RECORD irInBuf[128];
	char strBuffer[20];
	COORD mousePos;
	DWORD mouseButtonState;

	// Цикл обработки событий консоли
	while (1)
	{
		// Ожидание событий
		ReadConsoleInput(hStdIn, irInBuf, 128, &dwNumRead);

		// Обработка полученных событий
		for (DWORD i = 0; i < dwNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
				// События мыши
			case MOUSE_EVENT:
				// Координаты мыши
				mousePos = irInBuf[i].Event.MouseEvent.dwMousePosition;

				// Состояние кнопок мыши
				mouseButtonState = irInBuf[i].Event.MouseEvent.dwButtonState;

				// Нажата левая кнопка мыши с перемещением
				if (mouseButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && irInBuf[i].Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
				{
					srcX = mousePos.X;
					srcY = mousePos.Y;
				}
				else
				{
					return 1;
				}

			}
		}
	}
}

int dirDetectMouse(int &startX, int &startY, int &finishX, int &finishY)
{
	int result = 0;
	// 1 - righr
	// 2 - down
	// 3 - left
	// 4 - up
	if (startX < finishX && startY == finishY)
	{
		result = 1;
	}
	else if (startX == finishX && startY < finishY)
	{
		result = 2;
	}
	else if(startX > finishX && startY == finishY)
	{
		result = 3;
	}
	else if(startX == finishX && startY > finishY)
	{
		result = 4;
	}

	return result;
}

void changeColorAndDraw(sElemInfo *src, int pressedIndex, int nextIndex)
{
	int tempColor = src[pressedIndex].color;
	src[pressedIndex].color = src[nextIndex].color;
	src[nextIndex].color = tempColor;

	Sleep(100);
	drawElement(src[nextIndex].x, src[nextIndex].y, src[nextIndex].color);
	Sleep(50);
	drawElement(src[pressedIndex].x, src[pressedIndex].y, src[pressedIndex].color);
}

int detectPressedElemIndex(sElemInfo *src, int pressedX, int pressedY)
{
	int result = -1;
	for (int i = 0; i < strSize; i++)
	{
		if (pressedX == src[i].x && pressedY == src[i].y)
		{
			result = i;
			break;
		}
	}

	return result;
}

int defineMatchedColorSeq(sElemInfo *src, int presIndex, int direction)
{
	int result = 0;

	switch (direction)
	{
	case RIGHT:
		if (src[presIndex].color == src[presIndex + arr2[0]].color && src[presIndex].color == src[presIndex + arr2[1]].color)
		{
			result = 2;
		}
		else if (src[presIndex].color == src[presIndex + arr3[0]].color && src[presIndex].color == src[presIndex + arr3[1]].color)
		{
			result = 3;
		}
		else if (src[presIndex].color == src[presIndex + arr6[0]].color && src[presIndex].color == src[presIndex + arr6[1]].color)
		{
			result = 6;
		}
		else if (src[presIndex].color == src[presIndex + arr14[0]].color && src[presIndex].color == src[presIndex + arr14[1]].color)
		{
			result = 14;
		}
		else
		{
			result = -1;
		}
		break;
	case DOWN:
		if (src[presIndex].color == src[presIndex + arr7[0]].color && src[presIndex].color == src[presIndex + arr7[1]].color)
		{
			result = 7;
		}
		else if (src[presIndex].color == src[presIndex + arr11[0]].color && src[presIndex].color == src[presIndex + arr11[1]].color)
		{
			result = 11;
		}
		else if (src[presIndex].color == src[presIndex + arr12[0]].color && src[presIndex].color == src[presIndex + arr12[1]].color)
		{
			result = 12;
		}
		else if (src[presIndex].color == src[presIndex + arr16[0]].color && src[presIndex].color == src[presIndex + arr16[1]].color)
		{
			result = 16;
		}
		else
		{
			result = -1;
		}
		break;
	case LEFT:
		if (src[presIndex].color == src[presIndex + arr1[0]].color && src[presIndex].color == src[presIndex + arr1[1]].color)
		{
			result = 1;
		}
		else if (src[presIndex].color == src[presIndex + arr4[0]].color && src[presIndex].color == src[presIndex + arr4[1]].color)
		{
			result = 4;
		}
		else if (src[presIndex].color == src[presIndex + arr5[0]].color && src[presIndex].color == src[presIndex + arr5[1]].color)
		{
			result = 5;
		}
		else if (src[presIndex].color == src[presIndex + arr13[0]].color && src[presIndex].color == src[presIndex + arr13[1]].color)
		{
			result = 13;
		}
		else
		{
			result = -1;
		}
		break;
	case UP:
		if (src[presIndex].color == src[presIndex + arr8[0]].color && src[presIndex].color == src[presIndex + arr8[1]].color)
		{
			result = 8;
		}
		else if (src[presIndex].color == src[presIndex + arr9[0]].color && src[presIndex].color == src[presIndex + arr9[1]].color)
		{
			result = 9;
		}
		else if (src[presIndex].color == src[presIndex + arr10[0]].color && src[presIndex].color == src[presIndex + arr10[1]].color)
		{
			result = 10;
		}
		else if (src[presIndex].color == src[presIndex + arr15[0]].color && src[presIndex].color == src[presIndex + arr15[1]].color)
		{
			result = 15;
		}
		else
		{
			result = -1;
		}
		break;
	default:
		break;
	}

	return result;
}

void indexesOfLeftElements(int sequencNumber, int baseIndex, int &nextInd1, int &nextInd2)
{
	switch (sequencNumber)
	{
	case 1:
		nextInd1 = baseIndex + arr1[0];
		nextInd2 = baseIndex + arr1[1];
		break;
	case 2:
		nextInd1 = baseIndex + arr2[0];
		nextInd2 = baseIndex + arr2[1];
		break;
	case 3:
		nextInd1 = baseIndex + arr3[0];
		nextInd2 = baseIndex + arr3[1];
		break;
	case 4:
		nextInd1 = baseIndex + arr4[0];
		nextInd2 = baseIndex + arr4[1];
		break;
	case 5:
		nextInd1 = baseIndex + arr5[0];
		nextInd2 = baseIndex + arr5[1];
		break;
	case 6:
		nextInd1 = baseIndex + arr6[0];
		nextInd2 = baseIndex + arr6[1];
		break;
	case 7:
		nextInd1 = baseIndex + arr7[0];
		nextInd2 = baseIndex + arr7[1];
		break;
	case 8:
		nextInd1 = baseIndex + arr8[0];
		nextInd2 = baseIndex + arr8[1];
		break;
	case 9:
		nextInd1 = baseIndex + arr9[0];
		nextInd2 = baseIndex + arr9[1];
		break;
	case 10:
		nextInd1 = baseIndex + arr10[0];
		nextInd2 = baseIndex + arr10[1];
		break;
	case 11:
		nextInd1 = baseIndex + arr11[0];
		nextInd2 = baseIndex + arr11[1];
		break;
	case 12:
		nextInd1 = baseIndex + arr12[0];
		nextInd2 = baseIndex + arr12[1];
		break;
	case 13:
		nextInd1 = baseIndex + arr13[0];
		nextInd2 = baseIndex + arr13[1];
		break;
	case 14:
		nextInd1 = baseIndex + arr14[0];
		nextInd2 = baseIndex + arr14[1];
		break;
	case 15:
		nextInd1 = baseIndex + arr15[0];
		nextInd2 = baseIndex + arr15[1];
		break;
	case 16:
		nextInd1 = baseIndex + arr16[0];
		nextInd2 = baseIndex + arr16[1];
		break;
	}
}

void setNewColors(sElemInfo *src, int ind1, int ind2, int ind3)
{
	src[ind1].color = randColor();
	src[ind2].color = randColor();
	src[ind3].color = randColor();

}

bool checkClickDiapason(sElemInfo *src, int pressX, int pressY)
{
	bool result = false;
	for (int i = 0; i < strSize; i++)
	{
		if (pressX == src[i].x && pressY == src[i].y)
		{
			result = true;
			break;
		}
	}
	
	return result;
}

int getIndexbyXYVal(sElemInfo *src, int x, int y)
{
	int result = -1;
	for (int i = 0; i < strSize; i++)
	{
		if (src[i].x == x && src[i].y == y)
		{
			result = i;
			break;
		}
	}

	return result;
}

bool ifColorsMatch(sElemInfo *src, int ind1, int ind2, int ind3)
{
	bool result = false;
	if (src[ind1].color == src[ind2].color && src[ind1].color == src[ind3].color)
	{
		result = true;
	}
	return result;
}

void checkUnplanedMatches(sElemInfo *src, int baseElemInd)
{
	const int size = 8;
	int checkedElemInd[size];
	int xCoordMod[size] = {0, 0, 2, 4, 0, 0, -2, -4};
	int yCoordMod[size] = {-2, -4, 0, 0, 2, 4, 0, 0};
	int colorsVal[size / 2] = { -1, -1, -1, -1 };

	for (int i = 0; i < size; i++)
	{
		checkedElemInd[i] = getIndexbyXYVal(src, src[baseElemInd].x + xCoordMod[i], src[baseElemInd].y + yCoordMod[i]);
	}

	for (int i = 0, j = 0; i < size; i+=2)
	{
		if (checkedElemInd[i] != -1 && checkedElemInd[i + 1] != -1)
		{
			if (ifColorsMatch(src, baseElemInd, checkedElemInd[i], checkedElemInd[i + 1]))
			{
				colorsVal[j] = src[baseElemInd].color;
			}
		}
	}

	bool colorChange = false;
	for (int i = 0; i < size/2; i++)
	{
		if (colorsVal[i] != -1)
		{
			colorChange = true;
			break;
		}

	}
	
	if (colorChange == true)
	{
		bool generRightColor = false;
		do
		{
			src[baseElemInd].color = randColor();

			if (src[baseElemInd].color != colorsVal[0] && src[baseElemInd].color != colorsVal[1] && src[baseElemInd].color != colorsVal[2] && src[baseElemInd].color != colorsVal[3])
			{
				generRightColor = true;
			}

		} while (generRightColor == false);

	}
	
}

bool checkExistenceOfSequence(sElemInfo *src)
{
	bool result = false;
	const int size = 4;
	int check[size];
	for (int i = 0; i < strSize; i++)
	{
		check[0] = defineMatchedColorSeq(src, i, 1);
		check[1] = defineMatchedColorSeq(src, i, 2);
		check[2] = defineMatchedColorSeq(src, i, 3);
		check[3] = defineMatchedColorSeq(src, i, 4);

		for (int j = 0; j < size; j++)
		{
			if (check[j] != -1)
			{
				result = true;
				break;
			}
		}

		if (result == true)
		{
			GotoXY(1, 1);
			cout << i;
			break;
		}
	}

	return result;
}

void generateRandomSequence(int &ind1, int &ind2, int &ind3)
{
	bool flag = false;
	do
	{
		int randSeq = 1 + rand() % 15;
		ind1 = rand() % 63;
		indexesOfLeftElements(randSeq, ind1, ind2, ind3);

		if (ind2 >= 0 && ind2 <= 63 && ind3 >= 0 && ind3 <= 63)
		{
			flag = true;
		}
	} while (flag == false);
	
}

void setTheSameColors(sElemInfo *src, int ind1, int ind2, int ind3)
{
	int newColor = randColor();

	src[ind1].color = newColor;
	src[ind2].color = newColor;
	src[ind3].color = newColor;

}

void createNewSequence(sElemInfo *src)
{
	int ind1;
	int ind2;
	int ind3;

	generateRandomSequence(ind1, ind2, ind3);
	setTheSameColors(src, ind1, ind2, ind3);
}

void getName(char *name)
{
	WriteStr(25, 10, "Enter name:");
	GotoXY(27, 12);
	cin >> name;
}

void timer(int x, int y, int &minutes)
{

	int mySec = 0;

	if (mySec == 59)
	{
		minutes++;
		mySec = 0;
	}
	GotoXY(x, y);
	printf("%02d:%02d\n", minutes, mySec);

	Sleep(1000);
	mySec++;
		
	

}