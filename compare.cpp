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
#include "SelectSort.hpp"
#include "BubbleSort.hpp"
#include "ShakerSort.hpp"
#include "InsertionSort.hpp"
#include "Constants.hpp"

using namespace sf;

void CreateTable(vector<int> &mass, vector< vector<Text> > &tFill, Font &font)
{
	vector< vector<int> > tCount(6, vector<int>(6, 0));
	Text tmp ("", font, 26);
	int n = 0, M = 0, C = 0;

	for (int i = 0; i < 5; ++i)
	{
		n = 100 * (i + 1);
		for (int j = 0; j < 6; ++j)
		{
			if (j == 0)
			{
				tmp.setString(to_string(n));
				tFill[i][j] = tmp;
			}
			if (j == 1)
			{
				FillRand(mass, n);
				SelectSort(mass, M, C);
				tCount[i][j] = M + C;
				tmp.setString(to_string(M + C));
				tFill[i][j] = tmp;
			}
			if (j == 2)
			{
				FillRand(mass, n);
				BubbleSort(mass, M, C);
				tCount[i][j] = M + C;
				tmp.setString(to_string(M + C));
				tFill[i][j] = tmp;
			}
			if (j == 3)
			{
				FillRand(mass, n);
				ShakerSort(mass, M, C);
				tCount[i][j] = M + C;
				tmp.setString(to_string(M + C));
				tFill[i][j] = tmp;
			}
			if (j == 4)
			{
				FillRand(mass, n);
				InsertionSort(mass, M, C);
				tCount[i][j] = M + C;
				tmp.setString(to_string(M + C));
				tFill[i][j] = tmp;
			}
		}
	}
}

void CompareMenu(RenderWindow& window)
{
	vector<int> a(18);

	int M = 0, C = 0;

	bool isTable = 0;

	Clock time;

	Font font;
	font.loadFromFile("fonts/Roboto/Roboto-Regular.ttf");
	Text tCompare("Compare", font, 28), tBackToMenu("Menu", font, 36);

	RectangleShape rCompare(Vector2f(170, 50)), rBackToMenu(Vector2f(170, 50)), rGraphicOut(Vector2f(800, 400)), rTable(Vector2f(800,400));

	RectangleShape rOx(Vector2f(760, 1)), rOy(Vector2f(1, -360));
	rOx.setPosition(Vector2f(455, 649));
	rOy.setPosition(Vector2f(455, 649));

	Text tOx("X", font, 20), tOy("Y", font, 20);

	vector<Text> temp1;
	vector<Text> temp2;
	vector<Text> temp3;
	vector<Text> temp4;

	vector< vector<Text> > tFill(5, vector<Text>(6));

	SetOriginOnCenter(tOx);
	tOx.setPosition(rOx.getPosition() + rOx.getSize() + Vector2f(10, 10));

	SetOriginOnCenter(tOy);
	tOy.setPosition(rOy.getPosition() + rOy.getSize() + Vector2f(10, -5));

	VertexArray graph1(LineStrip, (int)ceil(graphPoints / (double)step));
	VertexArray graph2(LineStrip, (int)ceil(graphPoints / (double)step));
	VertexArray graph3(LineStrip, (int)ceil(graphPoints / (double)step));
	VertexArray graph4(LineStrip, (int)ceil(graphPoints / (double)step));

	rCompare.setPosition(Vector2f(50, 270));
	rBackToMenu.setPosition(Vector2f(50, 610));
	rGraphicOut.setPosition(Vector2f(435, 270));
	rTable.setPosition(Vector2f(435, 270));

	SetOriginOnCenter(tCompare);
	tCompare.setPosition(rCompare.getSize() / 2.0f + rCompare.getPosition());

	SetOriginOnCenter(tBackToMenu);
	tBackToMenu.setPosition(rBackToMenu.getSize() / 2.0f + rBackToMenu.getPosition());

	bool isMenu = 1;
	int menuNum = 0;

	while (isMenu)
	{
		Event event;
		menuNum = 0;

		window.clear(Color(34, 34, 38));

		DefaultButtonText(tCompare);
		DefaultButtonText(tBackToMenu);

		DefaultButtonRect(rCompare);
		DefaultButtonRect(rBackToMenu);
		DefaultButtonRect(rGraphicOut);
		DefaultButtonRect(rTable);

		if (IntRect(50, 270, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rCompare); menuNum = 1;
		}
		if (IntRect(435, 270, 800, 400).contains(Mouse::getPosition(window)))
		{
			isTable = true; menuNum = 2;
		}
		else { isTable = false; };
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
						temp1.clear();
						for (int i = 1, j = 0; i <= graphPoints; ++j, i += step)
						{
							FillRand(a, i);
							SelectSort(a, M, C);
							graph1[j].position = (Vector2f(i * 2, -(M + C) / 500) + rOx.getPosition());
							OyGraphNum(i, M + C, rOy, temp1, font, 500);
							graph1[j].color = Color::Cyan;
							M = 0, C = 0;
						}
						temp2.clear();
						for (int i = 1, j = 0; i <= graphPoints; ++j, i += step)
						{
							FillRand(a, i);
							BubbleSort(a, M, C);
							graph2[j].position = (Vector2f(i * 2, -(M + C) / 500) + rOx.getPosition());
							OyGraphNum(i, M + C, rOy, temp2, font, 500);
							graph2[j].color = Color::Red;
							M = 0, C = 0;
						}
						temp3.clear();
						for (int i = 1, j = 0; i <= graphPoints; ++j, i += step)
						{
							FillRand(a, i);
							ShakerSort(a, M, C);
							graph3[j].position = (Vector2f(i * 2, -(M + C) / 500) + rOx.getPosition());
							OyGraphNum(i, M + C, rOy, temp3, font, 500);
							graph3[j].color = Color::Yellow;
							M = 0, C = 0;
						}
						temp4.clear();
						for (int i = 1, j = 0; i <= graphPoints; ++j, i += step)
						{
							FillRand(a, i);
							InsertionSort(a, M, C);
							graph4[j].position = (Vector2f(i * 2, -(M + C) / 500) + rOx.getPosition());
							OyGraphNum(i, M + C, rOy, temp4, font, 500);
							graph4[j].color = Color::White;
							M = 0, C = 0;
						}
						for (int i = 0; i < temp2.size(); i++)
						{
							temp2[i].setPosition(temp2[i].getPosition() + Vector2f(100, 0));
						}
					}
					if (menuNum == 2)
					{
						CreateTable(a, tFill, font);
					}
					if (menuNum == 1666)
					{
						isMenu = false;
						menu(window);
					}
				}
			}
		}

		window.draw(rCompare);
		window.draw(rBackToMenu);
		window.draw(rGraphicOut);

		window.draw(tCompare);
		window.draw(tBackToMenu);

		window.draw(graph1);
		window.draw(graph2);
		window.draw(graph3);
		window.draw(graph4);
		window.draw(rOx);
		window.draw(rOy);
		window.draw(tOx);
		window.draw(tOy);

		/*for (int i = 0; i < temp1.size(); i++)
		{
			temp1[i].setFillColor(Color::Red);
			window.draw(temp1[i]);
		}

		for (int i = 0; i < temp2.size(); i++)
		{
			window.draw(temp2[i]);
		}
*/
		if (isTable)
		{
			window.draw(rTable);
			for (int i = 0; i < 5; ++i)
			{
				for (int j = 0; j < 6; ++j)
				{
					tFill[i][j].setPosition(rTable.getPosition() + Vector2f(50,50) + Vector2f(j * 120, i * 50));
					window.draw(tFill[i][j]);
				}
			}
		}

		window.display();
	}
}