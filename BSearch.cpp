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


void BSearchMenu(RenderWindow& window)
{
	vector<int> a(18);

	int M = 0, C = 0, K = 0;
	size_t aSize = a.size();

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

	rGraphicOut.setPosition(Vector2f(420, 244));
	rBinSearch1.setPosition(Vector2f(18, 218));
	rBinSearch2.setPosition(Vector2f(18, 218));

	bool isMenu = 1;
	int menuNum = 0;

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
						InsertionSort(a, M, C);
						PrintMasG(a, tArrayOutO);
						temp.clear();
						for (int i = 1, j = 0; i <= graphPoints; ++j, i += step)
						{
							InsertionSort(a, M, C);
							graph[j].position = (Vector2f(i * 2, -(M + C)) + rOx.getPosition());
							OyGraphNum(i, M + C, rOy, temp, font, 1);
							M = 0, C = 0;
						}
					}
					if (menuNum == 7)
					{
						tArrayOutO.setString("");
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

		window.draw(graph);
		DrawButton(rOx, tOx);
		DrawButton(rOy, tOy);

		for (int i = 0; i < temp.size(); i++)
		{
			window.draw(temp[i]);
		}

		window.display();
	}
}