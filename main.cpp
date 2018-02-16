#include"match_3.h"
#include<conio.h>

//void testFieldofRandElem(sElemInfo *src)
//{
//
//	int strInd = 0;
//	for (int i = 0; i < fieldSize; i++)
//	{
//		for (int j = 0; j <= fieldSize; j++)
//		{
//			if (j == fieldSize)
//			{
//				getInfo(initX, initY, color, true);
//			}
//			else
//			{
//				getInfo(initX, initY, color, false);
//				//drawElement(initX, initY, color);
//				initElem(initX, initY, color, src, strInd++);
//			}
//		}
//	}
//
//		drawAllElemFromStruct(src);
//
//}



void main()
{
	srand(time(NULL));
	ShowCursor(false);
	int score = 0;
	char name[20] = "-";
	int x, y;

	drawFirstAnimation();

	do
	{
		system("cls");
		x = 0;
		y = 0;
		allForMainMenu(x, y);

		if (x >= 25 && x <= 40 && y >= 10 && y <= 14)
		{
			if (name[0] == '-')
			{
				system("cls");
				getName(name);
				system("cls");
			}
			system("cls");
			allInterfaceForGame();
			gameCycle(score);
			continue;
		}
		if (x >= 25 && x <= 40 && y >= 15 && y <= 19)
		{
			system("cls");
			allInterfaceForScore();
			GotoXY(26, 13);
			cout << name;
			GotoXY(40, 13);
			cout << score;
			keyForScoreWindow();
			
		}

	} while (!(x >= 25 && x <= 40 && y >= 20 && y <= 24));

	
	/*allInterfaceForGame();
	gameCycle(score);*/

	
	//getch();
}