#include <iostream>
#include <vector>
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
#include "menu.hpp"

using namespace sf;

void CreateTable(vector<int> &mass, vector< vector<Text> > &tFill, Font &font)
{
	vector< vector<int> > tCount(6, vector<int>(6, 0));
	Text tmp ("", font, 26);
	int n = 0, M = 0, C = 0, K = 0;

	for (int i = 0; i < 6; ++i)
	{
		n = 100 * i;
		for (int j = 0; j < 6; ++j)
		{
			if (i == 0)
			{
				tmp.setString("| N |");
				tFill[i][0] = tmp;

				tmp.setString("SelectSort");
				tFill[i][1] = tmp;

				tmp.setString("BubbleSort");
				tFill[i][2] = tmp;

				tmp.setString("ShakerSort");
				tFill[i][3] = tmp;

				tmp.setString("InsertionSort");
				tFill[i][4] = tmp;
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
					tmp.setString(to_string(K));
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
}


void CreateTableInsVShell(vector<int>& mass, vector< vector<Text> >& tFill, Font& font)
{
	vector< vector<int> > tCount(6, vector<int>(6, 0));
	Text tmp("", font, 26);
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

				tmp.setString("K-sort");
				tFill[i][1] = tmp;

				tmp.setString("Insertion");
				tFill[i][2] = tmp;

				tmp.setString("Shell");
				tFill[i][3] = tmp;
			}
			else
			{
				if (j == 0)
				{
					tmp.setString(to_string(n));
					tFill[i][j] = tmp;
				}
				if (j == 2)
				{
					FillRand(mass, n);
					InsertionSort(mass, M, C);
					tCount[i][j] = M + C;
					tmp.setString(to_string(M + C));
					tFill[i][j] = tmp;
				}
				if (j == 3)
				{
					FillRand(mass, n);
					ShellSort(mass, M, C, K, 2);
					tCount[i][j] = M + C;
					tmp.setString(to_string(M + C));
					tFill[i][j] = tmp;
					tmp.setString(to_string(K));
					tFill[i][1] = tmp;
				}
			}
		}
	}
}

void CreateTableKnut(vector<int>& mass, vector< vector<Text> >& tFill, Font& font)
{
	vector< vector<int> > tCount(10, vector<int>(10, 0));
	Text tmp("", font, 26);
	int n = 0, M = 0, C = 0, K = 0;

	for (int i = 0; i < 6; ++i)
	{
		n = 200 * i;
		for (int j = 0; j < 9; ++j)
		{
			if (i == 0)
			{
				tmp.setString("| N |");
				tFill[i][0] = tmp;

				tmp.setString("K-Knut");
				tFill[i][1] = tmp;

				tmp.setString("Shell");
				tFill[i][2] = tmp;

				tmp.setString("K-another");
				tFill[i][3] = tmp;

				tmp.setString("Shell");
				tFill[i][4] = tmp;
			}
			else
			{
				if (j == 0)
				{
					tmp.setString(to_string(n));
					tFill[i][j] = tmp;
				}
				if (j == 2)
				{
					FillRand(mass, n);
					ShellSort(mass, M, C, K, 0);
					tCount[i][j] = M + C;
					tmp.setString(to_string(M + C));
					tFill[i][j] = tmp;
					tmp.setString(to_string(K));
					tFill[i][j-1] = tmp;
				}
				if (j == 4)
				{
					FillRand(mass, n);
					ShellSort(mass, M, C, K, 2);
					tCount[i][j] = M + C;
					tmp.setString(to_string(M + C));
					tFill[i][j] = tmp;
					tmp.setString(to_string(K));
					tFill[i][j-1] = tmp;
				}
			}
		}
	}
}

void CompareMenu(RenderWindow& window)
{
	int M = 0, C = 0;
	vector<int> a(18);

	Font font;
	font.loadFromFile("fonts/Roboto/Roboto-Regular.ttf");

	Text tCompare("Compare", font, 28), tBackToMenu("Menu", font, 36);
	RectangleShape rCompare(DefaultSize), rBackToMenu(DefaultSize), rGraphicOut(Vector2f(800, 400)), rTable(Vector2f(800,400));

	Text tDefault("Default", font, 28), tInsertVsShell("InsVsShell", font, 28), tKnutCompare("KnutCompare", font, 28);
	RectangleShape rDefault(DefaultSize), rInsertVsShell(DefaultSize), rKnutCompare(DefaultSize);

	CreateButton(rDefault, tDefault, Vector2f(435, 170));
	CreateButton(rInsertVsShell, tInsertVsShell, Vector2f(655, 170));
	CreateButton(rKnutCompare, tKnutCompare, Vector2f(875, 170));

	Text tOx("X", font, 20), tOy("Y", font, 20);
	RectangleShape rOx(Vector2f(760, 1)), rOy(Vector2f(1, -360));

	CreateButton(rOx, tOx, Vector2f(455, 649));
	CreateButton(rOy, tOy, Vector2f(455, 649));
	tOx.setPosition(rOx.getPosition() + rOx.getSize() + Vector2f(10, 10));
	tOy.setPosition(rOy.getPosition() + rOy.getSize() + Vector2f(10, -5));

	vector< vector<Text> > tFill(10, vector<Text>(10));
	vector<Text> temp1, temp2, temp3, temp4;

	VertexArray graph1(LineStrip, (int)ceil(graphPoints / (double)step)),
		graph2(LineStrip, (int)ceil(graphPoints / (double)step)),
		graph3(LineStrip, (int)ceil(graphPoints / (double)step)),
		graph4(LineStrip, (int)ceil(graphPoints / (double)step));

	CreateButton(rCompare, tCompare, Vector2f(50, 270));
	CreateButton(rBackToMenu, tBackToMenu, Vector2f(50, 610));
	CreateButton(rGraphicOut, Vector2f(435, 270));
	CreateButton(rTable, Vector2f(435, 270));

	bool isMenu = 1, isTable = 0;
	int menuNum = 0, table = 0;

	while (isMenu)
	{
		Event event;
		menuNum = 0;

		DefaultMenuBackground();

		DefaultButton(rCompare, tCompare);
		DefaultButton(rBackToMenu, tBackToMenu);
		if (table != 1)
		{
			DefaultButton(rDefault, tDefault);
		}
		if (table != 2)
		{
			DefaultButton(rInsertVsShell, tInsertVsShell);
		}
		if (table != 3)
		{
			DefaultButton(rKnutCompare, tKnutCompare);
		}
		
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
		if (IntRect(435, 170, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rDefault); menuNum = 3;
		}
		if (IntRect(655, 170, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rInsertVsShell); menuNum = 4;
		}
		if (IntRect(875, 170, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rKnutCompare); menuNum = 5;
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
						if (table == 1)
						{
							CreateTable(a, tFill, font);
						}
						if (table == 2)
						{
							CreateTableInsVShell(a, tFill, font);
						}
						if (table == 3)
						{
							CreateTableKnut(a, tFill, font);
						}
					}
					if (menuNum == 3)
					{
						HoverButtonRect(rDefault);
						table = 1;
						CreateTable(a, tFill, font);
					}
					if (menuNum == 4)
					{
						HoverButtonRect(rInsertVsShell);
						table = 2;
						CreateTableInsVShell(a, tFill, font);
					}
					if (menuNum == 5)
					{
						HoverButtonRect(rKnutCompare);
						table = 3;
						CreateTableKnut(a, tFill, font);
					}
					if (menuNum == 1666)
					{
						isMenu = false;
						menu(window);
					}
				}
			}
		}
		window.draw(rGraphicOut);
		DrawButton(rCompare, tCompare);
		DrawButton(rBackToMenu, tBackToMenu);

		DrawButton(rDefault, tDefault);
		DrawButton(rInsertVsShell, tInsertVsShell);
		DrawButton(rKnutCompare, tKnutCompare);

		window.draw(graph1);
		window.draw(graph2);
		window.draw(graph3);
		window.draw(graph4);
		DrawButton(rOx, tOx);
		DrawButton(rOy, tOy);

		/*for (int i = 0; i < temp1.size(); i++)
		{
			temp1[i].setFillColor(Color::Red);
			window.draw(temp1[i]);
		}

		for (int i = 0; i < temp2.size(); i++)
		{
			window.draw(temp2[i]);
		}*/

		if (isTable)
		{
			window.draw(rTable);
			for (int i = 0; i < 6; ++i)
			{
				for (int j = 0; j < 6; ++j)
				{
					tFill[i][j].setPosition(rTable.getPosition() + Vector2f(50,50) + Vector2f(j * 140, i * 50));
					window.draw(tFill[i][j]);
				}
			}
		}

		window.display();
	}
}