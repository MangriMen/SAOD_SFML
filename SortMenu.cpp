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
#include "HeapSort.hpp"
#include "Constants.hpp"
#include "compare.hpp"
#include "QuickSort.hpp"
#include "QuickSort2.hpp"
#include "DigitalSort.hpp"

using namespace sf;

void SortMenu(RenderWindow& window, const int SortType)
{
	vector<int> a(18);

	//char alo[12] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
	/*char alo[12] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };

	for (auto i : alo)
		a.push_back(static_cast<int> (i));*/

	int M = 0, C = 0, K = 0, D = 0;

	int textStep = 50;
	double yStep = 500;

	Font font;
	font.loadFromFile("fonts/Roboto/Roboto-Regular.ttf");
	Text tArrayOutO("", font, 28), tArrayOut("", font, 28), tClearArray("C", font, 28),
		tFillInc("Fill Inc", font, 36), tFillDec("Fill Dec", font, 36),
		tFillRand("FillRand", font, 36), tSort("Sort", font, 36), tBackToMenu("Menu", font, 36);

	RectangleShape rArrayOutO(Vector2f(800, 50)), rArrayOut(Vector2f(800, 50)), rClearArray(Vector2f(40, 40)),
		rFillInc(Vector2f(170, 50)), rFillDec(Vector2f(170, 50)),
		rFillRand(Vector2f(170, 50)), rSort(Vector2f(170, 50)), rBackToMenu(Vector2f(170, 50)),
		rGraphicOut(Vector2f(800, 400));

	Text tOx("X", font, 20), tOy("Y", font, 20);

	RectangleShape rOx(Vector2f(760, 1)), rOy(Vector2f(1, -360));
	CreateButton(rOx, tOx, Vector2f(455, 649));
	CreateButton(rOy, tOy, Vector2f(455, 649));

	tOx.setPosition(rOx.getPosition() + rOx.getSize() + Vector2f(10, 10));
	tOy.setPosition(rOy.getPosition() + rOy.getSize() + Vector2f(10, -5));

	vector<Text> temp;

	VertexArray graph(LineStrip, (int)ceil(graphPoints / (double)step));

	VertexArray lines(LineStrip, graphPoints / 50);

	CreateButton(rArrayOut, tArrayOut, Vector2f(435, 50));
	CreateButton(rArrayOutO, tArrayOutO, Vector2f(435, 145));
	CreateButton(rClearArray, tClearArray, Vector2f(435, 50));
	CreateButton(rFillInc, tFillInc, Vector2f(50, 50));
	CreateButton(rFillDec, tFillDec, Vector2f(50, 145));
	CreateButton(rFillRand, tFillRand, Vector2f(50, 240));
	CreateButton(rSort, tSort, Vector2f(50, 385));
	CreateButton(rBackToMenu, tBackToMenu, Vector2f(50, 610));

	rGraphicOut.setPosition(Vector2f(435, 270));

	bool isMenu = 1;
	int menuNum = 0;

	while (isMenu)
	{
		Event event;
		menuNum = 0;

		DefaultMenuBackground();

		DefaultButton(rArrayOut, tArrayOut);
		DefaultButton(rFillInc, tFillInc);
		DefaultButton(rFillDec, tFillDec);
		DefaultButton(rFillRand, tFillRand);
		DefaultButton(rSort, tSort);
		DefaultButton(rBackToMenu, tBackToMenu);

		DefaultButtonRect(rArrayOutO);
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
						//QuickSort(a, M, C, D, 0, a.size() - 1);
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
						if(SortType == 1) SelectSort(a, M, C);
						if(SortType == 2) BubbleSort(a, M, C);
						if(SortType == 3) ShakerSort(a, M, C);
						if(SortType == 4) InsertionSort(a, M, C);
						if (SortType == 5) ShellSort(a, M, C, K, 0);
						if (SortType == 6) HeapSort(a, M, C);
						if (SortType == 7) QuickSort(a, M, C, D, 0, a.size() - 1);
						//if (SortType == 8) QuickSort2(a, M, C, D, 0, a.size() - 1);
						if (SortType == 10) DigitalSort(a, M, C);
						PrintMasG(a, tArrayOutO);
						temp.clear();
						M = 0, C = 0;
						//for (int i = 1, j = 0, l = 0; i <= graphPoints; ++j, i += step)
						//{
						//	FillRand(a, i);
						//	if (SortType == 1) { SelectSort(a, M, C); yStep = 500; textStep = 50; }
						//	if (SortType == 2) { BubbleSort(a, M, C); yStep = 500; textStep = 50; }
						//	if (SortType == 3) { ShakerSort(a, M, C); yStep = 500; textStep = 50; }
						//	if (SortType == 4) { InsertionSort(a, M, C); yStep = 300; textStep = 50; }
						//	if (SortType == 5) { ShellSort(a, M, C, K, 0); yStep = 50; textStep = 50; }
						//	if (SortType == 6) { HeapSort(a, M, C); yStep = 50; textStep = 50; }
						//	if (SortType == 7) { QuickSort(a, M, C, D, 0, a.size() - 1); yStep = 50; textStep = 50; }
						//	if (SortType == 8) { QuickSort2(a, M, C, D, 0, a.size() - 1); yStep = 50; textStep = 50; }
						//	if (SortType == 10) DigitalSort(a, M, C);
						//	graph[j].position = (Vector2f(i * 2, -(M + C) / yStep) + rOx.getPosition());
						//	/*if (i % 50 == 0)
						//	{
						//		lines[l].position = (Vector2f(i * 2, -(M + C) / yStep) + rOx.getPosition());
						//		l += 2;
						//	}	*/
						//	OyGraphNum(i, M + C, rOy, temp, font, yStep, textStep);
						//	M = 0, C = 0, D = 0;
						//}
						a.resize(18);
						tOx.setString("X " + to_string(graphPoints));
						tOy.setString("Y " + to_string(yStep).erase(4, to_string(yStep).size()));
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

		DrawButton(rArrayOut, tArrayOut);
		DrawButton(rArrayOutO, tArrayOutO);
		DrawButton(rFillInc, tFillInc);
		DrawButton(rFillDec, tFillDec);
		DrawButton(rFillRand, tFillRand);
		DrawButton(rSort, tSort);
		DrawButton(rBackToMenu, tBackToMenu);
		window.draw(rGraphicOut);

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