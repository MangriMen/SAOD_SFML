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
#include "HeapSort.hpp"
#include "Constants.hpp"
#include "compare.hpp"
#include "menu.hpp"
#include "QuickSort.hpp"

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

void CreateTableHeap(vector<int>& mass, vector< vector<Text> >& tFill, Font& font)
{
	vector< vector<int> > tCount(6, vector<int>(6, 0));
	Text tmp("", font, 26);
	int n = 0, M = 0, C = 0, K = 0, D = 0;

	for (int i = 0; i < 6; ++i)
	{
		n = 100 * i;
		for (int j = 0; j < 6; ++j)
		{
			if (i == 0)
			{
				tmp.setString("| N |");
				tFill[i][0] = tmp;

				tmp.setString("Increment");
				tFill[i][1] = tmp;

				tmp.setString("Decrement");
				tFill[i][2] = tmp;

				tmp.setString("Random");
				tFill[i][3] = tmp;

				tmp.setString("");
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
					FillInc(mass, n);
					HeapSort(mass, M, C);
					tCount[i][j] = M + C;
					tmp.setString(to_string(M + C));
					tFill[i][j] = tmp;
				}
				if (j == 2)
				{
					FillDec(mass, n);
					HeapSort(mass, M, C);
					tCount[i][j] = M + C;
					tmp.setString(to_string(M + C));
					tFill[i][j] = tmp;
				}
				if (j == 3)
				{
					FillRand(mass, n);
					HeapSort(mass, M, C);
					tCount[i][j] = M + C;
					tmp.setString(to_string(M + C));
					tFill[i][j] = tmp;
					tmp.setString(to_string(K));
				}
				if (j == 4)
				{
					tmp.setString("");
					tFill[i][j] = tmp;
				}
			}
		}
	}
}

void CreateTableQuick(vector<int>& mass, vector< vector<Text> >& tFill, Font& font)
{
	vector< vector<int> > tCount(6, vector<int>(6, 0));
	Text tmp("", font, 26);
	int n = 0, M = 0, C = 0, K = 0, D = 0;

	for (int i = 0; i < 6; ++i)
	{
		n = 100 * i;
		for (int j = 0; j < 6; ++j)
		{
			if (i == 0)
			{
				tmp.setString("| N |");
				tFill[i][0] = tmp;

				tmp.setString("Increment");
				tFill[i][1] = tmp;

				tmp.setString("Decrement");
				tFill[i][2] = tmp;

				tmp.setString("Random");
				tFill[i][3] = tmp;

				tmp.setString("");
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
					M = 0, C = 0;
					FillInc(mass, n);
					QuickSort(mass, M, C, D, 0, mass.size() - 1);
					tCount[i][j] = M + C;
					tmp.setString(to_string(M + C));
					tFill[i][j] = tmp;
				}
				if (j == 2)
				{
					M = 0, C = 0;
					FillDec(mass, n);
					QuickSort(mass, M, C, D, 0, mass.size() - 1);
					tCount[i][j] = M + C;
					tmp.setString(to_string(M + C));
					tFill[i][j] = tmp;
				}
				if (j == 3)
				{
					M = 0, C = 0;
					FillRand(mass, n);
					QuickSort(mass, M, C, D, 0, mass.size() - 1);
					tCount[i][j] = M + C;
					tmp.setString(to_string(M + C));
					tFill[i][j] = tmp;
					tmp.setString(to_string(K));
				}
				if (j == 4)
				{
					tmp.setString("");
					tFill[i][j] = tmp;
				}
			}
		}
	}
}

void CompareMenu(RenderWindow& window)
{
	int M = 0, C = 0, K = 0, D = 0;
	int yStep = 500;
	vector<int> a(18);

	Font font;
	font.loadFromFile("fonts/Roboto/Roboto-Regular.ttf");

	Text tCompare("Compare", font, 28), tBackToMenu("Menu", font, 36);
	RectangleShape rCompare(DefaultSize), rBackToMenu(DefaultSize), rGraphicOut(Vector2f(800, 400)), rTable(Vector2f(800,400));

	Text tDefault("Default", font, 28), tInsertVsShell("InsVsShell", font, 28), tKnutCompare("KnutCompare", font, 28),
		tHeapVsShell("HeapVsShell", font, 28), tQuickSort("QuickSort", font, 28);
	RectangleShape rDefault(DefaultSize), rInsertVsShell(DefaultSize), rKnutCompare(DefaultSize), rHeapVsShell(DefaultSize), rQuickSort(DefaultSize);

	CreateButton(rDefault, tDefault, Vector2f(435, 170));
	CreateButton(rInsertVsShell, tInsertVsShell, Vector2f(655, 170));
	CreateButton(rKnutCompare, tKnutCompare, Vector2f(875, 170));
	CreateButton(rHeapVsShell, tHeapVsShell, Vector2f(435, 100));
	CreateButton(rQuickSort, tQuickSort, Vector2f(655, 100));

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
	rGraphicOut.setPosition(Vector2f(435, 270));
	rTable.setPosition(Vector2f(435, 270));

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
			DefaultButton(rDefault, tDefault);

		if (table != 2)
			DefaultButton(rInsertVsShell, tInsertVsShell);

		if (table != 3)
			DefaultButton(rKnutCompare, tKnutCompare);

		if (table != 4)
			DefaultButton(rHeapVsShell, tHeapVsShell);

		if (table != 5)
			DefaultButton(rQuickSort, tQuickSort);
		
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
		if (IntRect(435, 100, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rHeapVsShell); menuNum = 6;
		}
		if (IntRect(655, 100, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rQuickSort); menuNum = 7;
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
						yStep = 50;
						temp1.clear();
						for (int i = 1, j = 0; i <= graphPoints; ++j, i += step)
						{
							FillRand(a, i);
							ShellSort(a, M, C, K, 0);
							graph1[j].position = (Vector2f(i * 2, -(M + C) / yStep) + rOx.getPosition());
							OyGraphNum(i, M + C, rOy, temp1, font, yStep, 50);
							graph1[j].color = Color::Cyan;
							M = 0, C = 0;
						}
						temp2.clear();
						for (int i = 1, j = 0; i <= graphPoints; ++j, i += step)
						{
							FillRand(a, i);
							HeapSort(a, M, C);
							graph2[j].position = (Vector2f(i * 2, -(M + C) / yStep) + rOx.getPosition());
							OyGraphNum(i, M + C, rOy, temp2, font, yStep, 50);
							graph2[j].color = Color::Red;
							M = 0, C = 0;
						}
						temp3.clear();
						for (int i = 1, j = 0; i <= graphPoints; ++j, i += step)
						{
							FillRand(a, i);
							QuickSort(a, M, C, D, 0, a.size() - 1);
							graph3[j].position = (Vector2f(i * 2, -(M + C) / yStep) + rOx.getPosition());
							OyGraphNum(i, M + C, rOy, temp3, font, yStep, 50);
							graph3[j].color = Color::Green;
							M = 0, C = 0;
						}
						/*temp4.clear();
						for (int i = 1, j = 0; i <= graphPoints; ++j, i += step)
						{
							FillRand(a, i);
							InsertionSort(a, M, C);
							graph4[j].position = (Vector2f(i * 2, -(M + C) / 500) + rOx.getPosition());
							OyGraphNum(i, M + C, rOy, temp4, font, 500);
							graph4[j].color = Color::White;
							M = 0, C = 0;
						}*/
						for (int i = 0; i < temp2.size(); i++)
						{
							temp1[i].setPosition(temp1[i].getPosition() + Vector2f(-100, 0));
						}
						for (int i = 0; i < temp2.size(); i++)
						{
							temp2[i].setPosition(temp2[i].getPosition() + Vector2f(-50, 0));
						}
						tOx.setString("X " + to_string(graphPoints));
						tOy.setString("Y " + to_string(yStep));
					}
					if (menuNum == 2)
					{
						if (table == 1)
						{
							CreateTable(a, tFill, font);
						}
						else if (table == 2)
						{
							CreateTableInsVShell(a, tFill, font);
						}
						else if (table == 3)
						{
							CreateTableKnut(a, tFill, font);
						}
						else if (table == 4)
						{
							CreateTableHeap(a, tFill, font);
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
					if (menuNum == 6)
					{
						HoverButtonRect(rHeapVsShell);
						table = 4;
						CreateTableHeap(a, tFill, font);
					}
					if (menuNum == 7)
					{
						HoverButtonRect(rQuickSort);
						table = 5;
						CreateTableQuick(a, tFill, font);
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
		DrawButton(rHeapVsShell, tHeapVsShell);
		DrawButton(rQuickSort, tQuickSort);

		window.draw(graph1);
		window.draw(graph2);
		window.draw(graph3);
		window.draw(graph4);
		DrawButton(rOx, tOx);
		DrawButton(rOy, tOy);

		for (int i = 0; i < temp1.size(); i++)
		{
			temp1[i].setFillColor(Color::Cyan);
			window.draw(temp1[i]);
		}

		for (int i = 0; i < temp2.size(); i++)
		{
			temp2[i].setFillColor(Color::Red);
			window.draw(temp2[i]);
		}

		for (int i = 0; i < temp3.size(); i++)
		{
			temp3[i].setFillColor(Color::Green);
			window.draw(temp3[i]);
		}

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