#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "SortMenu.hpp"
#include "SelectSort.hpp"
#include "BubbleSort.hpp"
#include "ShakerSort.hpp"
#include "InsertionSort.hpp"
#include "ShellSort.hpp"
#include "Constants.hpp"
#include "compare.hpp"
#include "BSearch1.hpp"
#include "BSearch2.hpp"
#include "FormSFML.hpp"


void BinTable(vector<int>& mass, vector< vector<Text> >& tFill, Font& font, int key, int pos)
{
	vector< vector<int> > tCount(12, vector<int>(6, 0));
	Text tmp("", font, 16);
	int n = 0, M = 0, C = 0, K = 0;

	for (int i = 0; i < 11; ++i)
	{
		n = 100 * i;
		for (int j = 0; j < 6; ++j)
		{
			if (i == 0)
			{
				tmp.setString("| N |");
				tFill[i][0] = tmp;

				tmp.setString("BinS1");
				tFill[i][1] = tmp;

				tmp.setString("BinS2");
				tFill[i][2] = tmp;

				tmp.setString("Pos");
				tFill[i][3] = tmp;
			}
			else
			{
				if (j == 0)
				{
					tmp.setString(to_string(n));
					tFill[i][j] = tmp;
				}
				if (j == 1)
				{
					FillRand(mass, n);
					InsertionSort(mass, M, C);
					if (BSearch1(mass, C, key, pos))
					{
						tmp.setString(to_string(pos));
						tFill[i][3] = tmp;
					}
					else
					{
						tmp.setString("Not found");
						tFill[i][3] = tmp;
					}
					tCount[i][j] = C;
					tmp.setString(to_string(C));
					tFill[i][j] = tmp;
				}
				if (j == 2)
				{
					BSearch2(mass, C, key, pos);
					tCount[i][j] = C;
					tmp.setString(to_string(C));
					tFill[i][j] = tmp;
				}
			}
		}
	}
}

void BinTableAll(vector<int>& mass, vector< vector<Text> >& tFill, Font& font, int key, int pos)
{
	vector< vector<int> > tCount(6, vector<int>(6, 0));
	Text tmp("", font, 22);
	int n = 0, M = 0, C = 0, K = 0;

	for (int i = 0; i < 6; ++i)
	{
		n = 200 * i;
		for (int j = 0; j < 6; ++j)
		{
			if (i == 0)
			{
				tmp.setString("| N |");
				tFill[i][0] = tmp;

				tmp.setString("BinS1");
				tFill[i][1] = tmp;

				tmp.setString("BinS2");
				tFill[i][2] = tmp;

				tmp.setString("Pos");
				tFill[i][3] = tmp;
			}
			else
			{
				if (j == 0)
				{
					tmp.setString(to_string(n));
					tFill[i][j] = tmp;
				}
				if (j == 1)
				{
					FillRand(mass, n);
					InsertionSort(mass, M, C);
					if (BSearch1(mass, C, key, pos))
					{
						tmp.setString(to_string(pos));
						tFill[i][3] = tmp;
					}
					else
					{
						tmp.setString("Not found");
						tFill[i][3] = tmp;
					}
					tCount[i][j] = C;
					tmp.setString(to_string(C));
					tFill[i][j] = tmp;
				}
				if (j == 2)
				{
					BSearch2(mass, C, key, pos);
					tCount[i][j] = C;
					tmp.setString(to_string(C));
					tFill[i][j] = tmp;
				}
			}
		}
	}
}

void BSearchMenu(RenderWindow& window)
{
	vector<int> a(18);

	int M = 0, C = 0, K = 0, pos = -1;
	size_t aSize = a.size();

	vector< vector<Text> > tFill(12, vector<Text>(12));

	form::Button rKey(420, 156, 170, 50);
	form::Label tKey("Заменить текст", 420, 156);
	form::Input iKey(420, 156, 200, 30);
	iKey.setText("0");

	Font font;
	font.loadFromFile("fonts/Roboto/Roboto-Regular.ttf");
	Text tArrayOutO("", font, 28), tArraySize(to_string(aSize), font, 28), tClearArray("C", font, 28),
		tFillInc("Fill Inc", font, 36), tFillDec("Fill Dec", font, 36),
		tFillRand("FillRand", font, 36), tSort("Sort", font, 36), tBackToMenu("Menu", font, 36);

	RectangleShape rArrayOutO(Vector2f(840, 122)), rArraySize(Vector2f(170, 50)),
		rFillInc(Vector2f(170, 50)), rFillDec(Vector2f(170, 50)),
		rFillRand(Vector2f(170, 50)), rSort(Vector2f(170, 50)), rBackToMenu(Vector2f(120, 40)),
		rGraphicOut(Vector2f(800, 400));

	CircleShape rClearArray(20);

	RectangleShape rBinSearch1(Vector2f(350, 425)), rBinSearch2(Vector2f(350, 425));

	Text tBS("BS", font, 36), tBSAll("BSAll", font, 36);
	RectangleShape rBS(Vector2f(80, 40)), rBSAll(Vector2f(80, 40));

	Text tPos("Pos: ", font, 28);
	/*tKey("Key: ", font, 28),
		rKey(Vector2f(170, 50)),*/
	RectangleShape rPos(Vector2f(340, 50));

	Text tOx("X", font, 20), tOy("Y", font, 20);

	RectangleShape rOx(Vector2f(760, 1)), rOy(Vector2f(1, -360));
	CreateButton(rOx, tOx, Vector2f(440, 623));
	CreateButton(rOy, tOy, Vector2f(440, 623));

	tOx.setPosition(rOx.getPosition() + rOx.getSize() + Vector2f(10, 10));
	tOy.setPosition(rOy.getPosition() + rOy.getSize() + Vector2f(10, -5));

	vector<Text> temp;

	VertexArray graph(LineStrip, (int)ceil(graphPoints / (double)step));

	CreateButton(rArraySize, tArraySize, Vector2f(18, 20));
	CreateButton(rArrayOutO, tArrayOutO, Vector2f(420, 20));
	CreateButton(rClearArray, tClearArray, Vector2f(45, 160));
	CreateButton(rFillInc, tFillInc, Vector2f(198, 20));
	CreateButton(rFillDec, tFillDec, Vector2f(18, 92));
	CreateButton(rFillRand, tFillRand, Vector2f(198, 92));
	CreateButton(rSort, tSort, Vector2f(105, 156));
	CreateButton(rBackToMenu, tBackToMenu, Vector2f(18, 660));

	/*CreateButton(rKey, tKey, Vector2f(420, 156));*/
	CreateButton(rPos, tPos, Vector2f(880, 156));

	CreateButton(rBS, tBS, Vector2f(173, 660));
	CreateButton(rBSAll, tBSAll, Vector2f(288, 660));

	rGraphicOut.setPosition(Vector2f(420, 244));
	rBinSearch1.setPosition(Vector2f(18, 218));
	rBinSearch2.setPosition(Vector2f(18, 218));

	bool isMenu = 1;
	int menuNum = 0, table = 1;

	while (isMenu)
	{
		Event event;
		menuNum = 0;

		DefaultMenuBackground();

		DefaultButton(rArraySize, tArraySize);
		DefaultButton(rFillInc, tFillInc);
		DefaultButton(rFillDec, tFillDec);
		DefaultButton(rFillRand, tFillRand);
		DefaultButton(rSort, tSort);
		DefaultButton(rClearArray, tClearArray);
		DefaultButton(rBackToMenu, tBackToMenu);

		/*DefaultButton(rKey, tKey);*/
		DefaultButton(rPos, tPos);

		if (table != 1)
		{
			DefaultButton(rBS, tBS);
		}
		if (table != 2)
		{
			DefaultButton(rBSAll, tBSAll);
		}



		DefaultButtonRect(rArrayOutO);
		DefaultButtonRect(rGraphicOut);
		DefaultButtonRect(rBinSearch1);
		DefaultButtonRect(rBinSearch2);

		if (IntRect(198, 20, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rFillInc); menuNum = 1;
		}
		if (IntRect(18, 92, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rFillDec); menuNum = 2;
		}
		if (IntRect(198, 92, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rFillRand); menuNum = 3;
		}
		if (IntRect(105, 156, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rSort); menuNum = 4;
		}
		if (IntRect(18, 218, 350, 425).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rBinSearch1); menuNum = 5;
		}
		if (IntRect(45, 160, 40, 40).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rClearArray); menuNum = 7;
		}
		if (IntRect(173, 660, 80, 40).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rBS); menuNum = 8;
		}
		if (IntRect(288, 660, 80, 40).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rBSAll); menuNum = 9;
		}
		if (IntRect(18, 660, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rBackToMenu); menuNum = 6;
		}

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isMenu = false;
				exit(1999);
				window.close();
			}
			if (event.type == Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Vector2i mouse = Mouse::getPosition(window);
					iKey.select(mouse);
					if (menuNum == 1)
					{
						FillInc(a, (int)a.size());
						PrintMasG(a, tArrayOutO);
					}
					if (menuNum == 2)
					{
						FillDec(a, (int)a.size());
						PrintMasG(a, tArrayOutO);
					}
					if (menuNum == 3)
					{
						FillRand(a, (int)a.size());
						PrintMasG(a, tArrayOutO);
					}
					if (menuNum == 4)
					{
						K = stoi(iKey.readText());
						tKey.setText(iKey.readText());
						/*tKey.setString("Key: " + to_string(K));
						UpdateCenter(rKey, tKey);*/
						InsertionSort(a, M, C);
						PrintMasG(a, tArrayOutO);
						if (BSearch1(a, C, K, pos))
						{
							tPos.setString("Pos: " + to_string(pos));
						}
						else
						{
							tPos.setString("Pos: not found");
						}
						UpdateCenter(rPos, tPos);
						temp.clear();
						for (int i = 1, j = 0; i <= graphPoints; ++j, i += step)
						{
							InsertionSort(a, M, C);
							graph[j].position = (Vector2f(i * 2, -(M + C)) + rOx.getPosition());
							OyGraphNum(i, M + C, rOy, temp, font, 1, 50);
							M = 0, C = 0;
						}
					}
					if (menuNum == 5)
					{
						K = stoi(iKey.readText());
						tKey.setText(iKey.readText());
						if (table == 1)
						{
							BinTable(a, tFill, font, K, pos);
						}
						else if (table == 2)
						{
							/*BinTableAll(a, tFill, font, K, pos);*/
						}
					}
					if (menuNum == 7)
					{
						tArrayOutO.setString("");
					}
					if (menuNum == 8)
					{
						HoverButtonRect(rBS);
						table = 1;
						BinTable(a, tFill, font, K, pos);
					}
					if (menuNum == 9)
					{
						HoverButtonRect(rBSAll);
						table = 2;
						BinTable(a, tFill, font, K, pos);
					}
					if (menuNum == 6)
					{
						isMenu = false;
						menu(window);
					}
					SetOriginOnCenter(tArraySize);
					tArraySize.setPosition(rArraySize.getSize() / 2.0f + rArraySize.getPosition() + Vector2f(5, 5));

					SetOriginOnCenter(tArrayOutO);
					tArrayOutO.setPosition(rArrayOutO.getSize() / 2.0f + rArrayOutO.getPosition() + Vector2f(5, 5));
				}
			}
			if (event.type == sf::Event::TextEntered) {
				if (iKey.select()) {
					iKey.reText(event.text.unicode);
				}
			}
		}

		DrawButton(rArraySize, tArraySize);
		DrawButton(rArrayOutO, tArrayOutO);
		DrawButton(rFillInc, tFillInc);
		DrawButton(rFillDec, tFillDec);
		DrawButton(rFillRand, tFillRand);
		DrawButton(rSort, tSort);
		DrawButton(rClearArray, tClearArray);
		DrawButton(rBackToMenu, tBackToMenu);
		window.draw(rGraphicOut);
		window.draw(rBinSearch1);

		DrawButton(rBS, tBS);
		DrawButton(rBSAll, tBSAll);

		/*DrawButton(rKey, tKey);*/
		DrawButton(rPos, tPos);
		window.draw(rKey.displayButton());
		/*window.draw(iKey.displayButton());*/
		window.draw(iKey.displayText());
		//window.draw(tKey.displayText());

		window.draw(graph);
		DrawButton(rOx, tOx);
		DrawButton(rOy, tOy);

		for (int i = 0; i < 11; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				tFill[i][j].setPosition(rBinSearch1.getPosition() + Vector2f(20, 20) + Vector2f(j * 75, i * 37));
				window.draw(tFill[i][j]);
			}
		}

		for (int i = 0; i < temp.size(); i++)
		{
			window.draw(temp[i]);
		}

		window.display();
	}
}