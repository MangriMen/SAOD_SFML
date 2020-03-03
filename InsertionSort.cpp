#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "menu.hpp"
#include "ArrOperations.hpp"
#include "Constants.hpp"

using namespace std;

void InsertionSort(vector<int>& mass, int& M, int& C)
{
	int t = 0, j = 0;
	for (int i = 1; i < mass.size(); i++)
	{
		C++;
		t = mass[i];
		j = i - 1;

		while (j > 0 && t < mass[j])
		{
			mass[j + 1] = mass[j];
			j = j - 1;
			M += 3;
		}
		mass[j + 1] = t;
	}
}

void InsertionSortMenu(RenderWindow& window)
{
	vector<int> a(18);

	int M = 0, C = 0;

	Clock time;

	Font font;
	font.loadFromFile("fonts/Roboto/Roboto-Regular.ttf");
	Text tArrayOutO("", font, 28), tArrayOut("", font, 28), tFillInc("Fill Inc", font, 36), tFillDec("Fill Dec", font, 36),
		tFillRand("FillRand", font, 36), tSort("Sort", font, 36), tBackToMenu("Menu", font, 36);

	RectangleShape rArrayOutO(Vector2f(800, 50)), rArrayOut(Vector2f(800, 50)), rClearArray(Vector2f(40, 40)), rFillInc(Vector2f(170, 50)),
		rFillDec(Vector2f(170, 50)), rFillRand(Vector2f(170, 50)), rSort(Vector2f(170, 50)), rBackToMenu(Vector2f(170, 50)),
		rGraphicOut(Vector2f(800, 400));

	RectangleShape rOx(Vector2f(760, 1)), rOy(Vector2f(1, -360));
	rOx.setPosition(Vector2f(455, 649));
	rOy.setPosition(Vector2f(455, 649));

	Text tOx("X", font, 20), tOy("Y", font, 20);

	vector<Text> temp;

	SetOriginOnCenter(tOx);
	tOx.setPosition(rOx.getPosition() + rOx.getSize() + Vector2f(10, 10));

	SetOriginOnCenter(tOy);
	tOy.setPosition(rOy.getPosition() + rOy.getSize() + Vector2f(10, -5));

	VertexArray graph(LineStrip, (int)ceil(graphPoints / (double)step));

	rArrayOut.setPosition(Vector2f(435, 50));
	rArrayOutO.setPosition(Vector2f(435, 145));
	rClearArray.setPosition(Vector2f(378, 100));
	rFillInc.setPosition(Vector2f(50, 50));
	rFillDec.setPosition(Vector2f(50, 145));
	rFillRand.setPosition(Vector2f(50, 240));
	rSort.setPosition(Vector2f(50, 385));
	rBackToMenu.setPosition(Vector2f(50, 610));
	rGraphicOut.setPosition(Vector2f(435, 270));

	SetOriginOnCenter(tFillInc);
	tFillInc.setPosition(rFillInc.getSize() / 2.0f + rFillInc.getPosition());

	SetOriginOnCenter(tFillDec);
	tFillDec.setPosition(rFillDec.getSize() / 2.0f + rFillDec.getPosition());

	SetOriginOnCenter(tFillRand);
	tFillRand.setPosition(rFillRand.getSize() / 2.0f + rFillRand.getPosition());

	SetOriginOnCenter(tSort);
	tSort.setPosition(rSort.getSize() / 2.0f + rSort.getPosition());

	SetOriginOnCenter(tBackToMenu);
	tBackToMenu.setPosition(rBackToMenu.getSize() / 2.0f + rBackToMenu.getPosition());

	bool isMenu = 1;
	int menuNum = 0;

	while (isMenu)
	{
		Event event;
		menuNum = 0;

		window.clear(Color(34, 34, 38));

		DefaultButtonText(tArrayOut);
		DefaultButtonText(tFillInc);
		DefaultButtonText(tFillDec);
		DefaultButtonText(tFillRand);
		DefaultButtonText(tSort);
		DefaultButtonText(tBackToMenu);

		DefaultButtonRect(rArrayOut);
		DefaultButtonRect(rArrayOutO);
		DefaultButtonRect(rFillInc);
		DefaultButtonRect(rFillDec);
		DefaultButtonRect(rFillRand);
		DefaultButtonRect(rSort);
		DefaultButtonRect(rBackToMenu);
		DefaultButtonRect(rGraphicOut);

		if (IntRect(50, 50, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rFillInc); menuNum = 1;
		}
		if (IntRect(50, 145, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rFillDec); menuNum = 2;
		}
		if (IntRect(50, 240, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rFillRand); menuNum = 3;
		}
		if (IntRect(50, 385, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rSort); menuNum = 4;
		}
		if (IntRect(50, 610, 170, 50).contains(Mouse::getPosition(window)))
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
						PrintMasG(a, tArrayOut);
						tArrayOutO.setString("");
					}
					if (menuNum == 2)
					{
						FillDec(a, (int)a.size());
						PrintMasG(a, tArrayOut);
						tArrayOutO.setString("");
					}
					if (menuNum == 3)
					{
						FillRand(a, (int)a.size());
						PrintMasG(a, tArrayOut);
						tArrayOutO.setString("");
					}
					if (menuNum == 4)
					{
						InsertionSort(a, M, C);
						PrintMasG(a, tArrayOutO);
						temp.clear();
						for (int i = 1, j = 0; i < graphPoints; ++j, i += step)
						{
							FillRand(a, i);
							InsertionSort(a, M, C);
							graph[j].position = (Vector2f(i * 2, -(M + C) / 500) + rOx.getPosition());
							OyGraphNum(i, M + C, rOy, temp, font, 500);
							M = 0, C = 0;
						}
					}
					if (menuNum == 6)
					{
						isMenu = false;
						menu(window);
					}
					SetOriginOnCenter(tArrayOut);
					tArrayOut.setPosition(rArrayOut.getSize() / 2.0f + rArrayOut.getPosition() + Vector2f(5, 5));

					SetOriginOnCenter(tArrayOutO);
					tArrayOutO.setPosition(rArrayOutO.getSize() / 2.0f + rArrayOutO.getPosition() + Vector2f(5, 5));
				}
			}
		}

		window.draw(rArrayOut);
		window.draw(rArrayOutO);
		window.draw(rFillInc);
		window.draw(rFillDec);
		window.draw(rFillRand);
		window.draw(rSort);
		window.draw(rBackToMenu);
		window.draw(rGraphicOut);

		window.draw(tArrayOut);
		window.draw(tArrayOutO);
		window.draw(tFillInc);
		window.draw(tFillDec);
		window.draw(tFillRand);
		window.draw(tSort);
		window.draw(tBackToMenu);

		window.draw(graph);
		window.draw(rOx);
		window.draw(rOy);
		window.draw(tOx);
		window.draw(tOy);

		for (int i = 0; i < temp.size(); i++)
		{
			window.draw(temp[i]);
		}

		window.display();
	}
}