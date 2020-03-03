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

using namespace sf;

#define ClearField() tArrayOutO.setString("");

void SelectSort(vector<int>& mass, int &M, int &C)
{
	int min;
	M = 0, C = 0;
	for (int i = 0; i < mass.size() - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < mass.size(); j++)
		{
			C++;
			if (mass[j] < mass[min])
			{
				min = j;
			}
		}
		swap(mass[min], mass[i]);
		M += 3;
	}
}

void SelectSortOpt(vector<int>& mass, int& M, int& C)
{
	int min;
	M = 0, C = 0;
	for (int i = 0; i < mass.size() - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < mass.size(); j++)
		{
			C++;
			if (mass[j] < mass[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			M += 3;
			swap(mass[i], mass[min]);
		}
	}

} 

void SelectSortMenu(RenderWindow& window)
{
	vector<int> a(18);

	int M = 0, C = 0;

	Clock time;
	int FillIncIsPressed = 0;

	Font font;
	font.loadFromFile("fonts/Roboto/Roboto-Regular.ttf");
	Text tArrayOutO("", font, 28), tArrayOut("", font, 28), tFillInc("Fill Inc", font, 36), tFillDec("Fill Dec", font, 36),
		tFillRand("FillRand", font, 36), tSort("Sort", font, 36), tSortOpt("SortOpt", font, 36), tSum1("CheckSum: ", font, 36),
		tSeries1("Series: ", font, 36), tSum2("CheckSum: ", font, 36), tSeries2("Series: ", font, 36), tBackToMenu("Menu", font, 36);

	RectangleShape rArrayOutO(Vector2f(800, 50)), rArrayOut(Vector2f(800, 50)), rClearArray(Vector2f(40, 40)), rFillInc(Vector2f(170, 50)),
		rFillDec(Vector2f(170, 50)), rFillRand(Vector2f(170, 50)), rSort(Vector2f(170, 50)), rSortOpt(Vector2f(170, 50)), rSum1(Vector2f(190,50)),
		rSeries1(Vector2f(120, 50)), rSum2(Vector2f(190, 50)), rSeries2(Vector2f(120, 50)), rBackToMenu(Vector2f(170, 50)), rGraphicOut(Vector2f(800, 400));

	Text tSumN1("", font, 36), tSeriesN1("", font, 36), tSumN2("", font, 36), tSeriesN2("", font, 36);
	RectangleShape rSumN1(Vector2f(50,50)), rSeriesN1(Vector2f(50, 50)), rSumN2(Vector2f(50, 50)), rSeriesN2(Vector2f(50, 50));

	RectangleShape rOx(Vector2f(760, 1)), rOy(Vector2f(1, -360));
	rOx.setPosition(Vector2f(455, 649));
	rOy.setPosition(Vector2f(455, 649));

	Text tOx("X", font, 20), tOy("Y", font, 20);

	vector<Text> temp;

	SetOriginOnCenter(tOx);
	tOx.setPosition(rOx.getPosition() + rOx.getSize() + Vector2f(10, 10));

	SetOriginOnCenter(tOy);
	tOy.setPosition(rOy.getPosition() + rOy.getSize() + Vector2f(10, -5));

	VertexArray graph(LineStrip, 350);

	rArrayOut.setPosition(Vector2f(435, 50));
	rArrayOutO.setPosition(Vector2f(435, 145));
	rClearArray.setPosition(Vector2f(378, 100));
	rFillInc.setPosition(Vector2f(50, 50));
	rFillDec.setPosition(Vector2f(50, 145));
	rFillRand.setPosition(Vector2f(50, 240));
	rSort.setPosition(Vector2f(50, 385));
	rSortOpt.setPosition(Vector2f(50, 480));
	rSum1.setPosition(Vector2f(435, 0));
	rSeries1.setPosition(Vector2f(723, 0));
	rSum2.setPosition(Vector2f(435, 208));
	rSeries2.setPosition(Vector2f(723, 208));
	rBackToMenu.setPosition(Vector2f(50, 610));
	rGraphicOut.setPosition(Vector2f(435, 270));

	rSumN1.setPosition(rSum1.getPosition() + Vector2f(50,0) + rSumN1.getSize());
	rSeriesN1.setPosition(rSeries1.getPosition() + Vector2f(50, 0) + rSumN1.getSize());

	rSumN2.setPosition(rSum2.getPosition() + Vector2f(50, 0) + Vector2f(150,0));
	rSeriesN2.setPosition(rSeries2.getPosition() + Vector2f(50, 0) + Vector2f(150, 0));

	SetOriginOnCenter(tFillInc);
	tFillInc.setPosition(rFillInc.getSize() / 2.0f + rFillInc.getPosition());

	SetOriginOnCenter(tFillDec);
	tFillDec.setPosition(rFillDec.getSize() / 2.0f + rFillDec.getPosition());

	SetOriginOnCenter(tFillRand);
	tFillRand.setPosition(rFillRand.getSize() / 2.0f + rFillRand.getPosition());

	SetOriginOnCenter(tSort);
	tSort.setPosition(rSort.getSize() / 2.0f + rSort.getPosition());

	SetOriginOnCenter(tSortOpt);
	tSortOpt.setPosition(rSortOpt.getSize() / 2.0f + rSortOpt.getPosition());
	
	tSum1.setPosition(rSum1.getPosition() + Vector2f(5, 5));

	tSeries1.setPosition(rSeries1.getPosition() + Vector2f(5, 5));

	tSum2.setPosition(rSum2.getPosition() + Vector2f(5, 5));
	
	tSeries2.setPosition(rSeries2.getPosition() + Vector2f(5,5));

	tSumN2.setPosition(rSumN2.getPosition() + Vector2f(5, 5));

	tSeriesN2.setPosition(rSeriesN2.getPosition() + Vector2f(5, 5));

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
		DefaultButtonText(tArrayOutO);
		DefaultButtonText(tFillInc);
		DefaultButtonText(tFillDec);
		DefaultButtonText(tFillRand);
		DefaultButtonText(tSort);
		DefaultButtonText(tSortOpt);
		DefaultButtonText(tSum1);
		DefaultButtonText(tSeries1);
		DefaultButtonText(tSum2);
		DefaultButtonText(tSeries2);
		DefaultButtonText(tBackToMenu);

		DefaultButtonText(tSumN1);
		DefaultButtonText(tSeriesN1);

		DefaultButtonText(tSumN2);
		DefaultButtonText(tSeriesN2);

		DefaultButtonRect(rArrayOut);
		DefaultButtonRect(rArrayOutO);
		DefaultButtonRect(rFillInc);
		DefaultButtonRect(rFillDec);
		DefaultButtonRect(rFillRand);
		DefaultButtonRect(rSort);
		DefaultButtonRect(rSortOpt);
		DefaultButtonRect(rSum1);
		DefaultButtonRect(rSeries1);
		DefaultButtonRect(rSum2);
		DefaultButtonRect(rSeries2);
		DefaultButtonRect(rBackToMenu);
		DefaultButtonRect(rGraphicOut);

		DefaultButtonRect(rSumN1);
		DefaultButtonRect(rSeriesN1);

		DefaultButtonRect(rSumN2);
		DefaultButtonRect(rSeriesN2);


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
		if (IntRect(50, 480, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rSortOpt); menuNum = 5;
		}
		if (IntRect(50, 610, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rBackToMenu); menuNum = 1666;
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
						ClearField();
					}
					if (menuNum == 2)
					{
						FillDec(a, (int)a.size());
						PrintMasG(a, tArrayOut);
						ClearField();
					}
					if (menuNum == 3)
					{
						FillRand(a, (int)a.size());
						PrintMasG(a, tArrayOut);
						ClearField();
					}
					if (menuNum == 4)
					{
						SelectSort(a, M, C);
						tSumN2.setString(to_string(CheckSum(a)));
						tSeriesN2.setString(to_string(RunNumber(a)));
						PrintMasG(a, tArrayOutO);
					}
					if (menuNum == 5)
					{
						SelectSortOpt(a, M, C);
						tSumN2.setString(to_string(CheckSum(a)));
						tSeriesN2.setString(to_string(RunNumber(a)));
						PrintMasG(a, tArrayOutO);
						temp.clear();
						for (int i = 1; i <= 350; ++i)
						{
							FillRand(a, i);
							SelectSortOpt(a, M, C);
							graph[i - 1].position = (Vector2f(i * 2, -(M + C) / 500) + rOx.getPosition());
							OyGraphNum(i, M + C, rOy, temp, font, 500);
							M = 0, C = 0;
						}
					}
					if (menuNum == 1666)
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
		window.draw(rSortOpt);
		window.draw(rSum1);
		window.draw(rSeries1);
		window.draw(rSum2);
		window.draw(rSeries2);
		window.draw(rBackToMenu);
		window.draw(rGraphicOut);

		window.draw(rSumN1);
		window.draw(rSeriesN1);

		window.draw(rSumN2);
		window.draw(rSeriesN2);

		window.draw(tArrayOut);
		window.draw(tArrayOutO);
		window.draw(tFillInc);
		window.draw(tFillDec);
		window.draw(tFillRand);
		window.draw(tSort);
		window.draw(tSortOpt);
		window.draw(tSum1);
		window.draw(tSeries1);
		window.draw(tSum2);
		window.draw(tSeries2);
		window.draw(tBackToMenu);

		window.draw(tSumN1);
		window.draw(tSeriesN1);

		window.draw(tSumN2);
		window.draw(tSeriesN2);

		window.draw(graph);
		window.draw(rOx);
		window.draw(rOy);

		window.display();
	}
}