#include <iostream>
#include <SFML/Graphics.hpp>
#include "SortMenu.hpp"
#include "SelectSort.hpp"
#include "BubbleSort.hpp"
#include "ShakerSort.hpp"
#include "InsertionSort.hpp"
#include "ShellSort.hpp"
#include "ShellSort.hpp"
#include "IndexSort.hpp"
#include "Constants.hpp"
#include "compare.hpp"
#include "BSearch.hpp"
#include "Menu11.hpp"
#include "DigitalSort.hpp"

using namespace sf;

void DefaultButtonText(Text& text)
{
	text.setFillColor(Color::White);
}

void DefaultButtonRect(RectangleShape& shape)
{
	shape.setFillColor(Color(51, 51, 54));
}

void DefaultButtonRect(CircleShape& shape)
{
	shape.setFillColor(Color(51, 51, 54));
}

void HoverButtonRect(RectangleShape& shape)
{
	shape.setFillColor(Color(68, 68, 70));
}

void HoverButtonRect(CircleShape& shape)
{
	shape.setFillColor(Color(68, 68, 70));
}

void SetOriginOnCenter(Text& text) {
	FloatRect FRect = text.getLocalBounds();
	text.setOrigin(FRect.left + FRect.width / 2.0f,
		FRect.top + FRect.height / 2.0f);
}

void UpdateCenter(RectangleShape button, Text& text)
{
	SetOriginOnCenter(text);
	text.setPosition(button.getSize() / 2.0f + button.getPosition());
}

void UpdateCenter(CircleShape button, Text& text)
{
	SetOriginOnCenter(text);
	text.setPosition(Vector2f(button.getRadius(), button.getRadius()) + button.getPosition());
}

void CreateButton(RectangleShape& button, Text& text, Vector2f position)
{
	button.setPosition(position);
	SetOriginOnCenter(text);
	text.setPosition(button.getSize() / 2.0f + button.getPosition());
}

void CreateButton(CircleShape& button, Text& text, Vector2f position)
{
	button.setPosition(position);
	SetOriginOnCenter(text);
	text.setPosition(Vector2f(button.getRadius(), button.getRadius()) + button.getPosition());
}

void CreateButton(RectangleShape& button, Vector2f position)
{
	button.setPosition(position);
}

void menu(RenderWindow& window) {
	Font font;
	font.loadFromFile("fonts/Roboto/Roboto-Regular.ttf");

	Text tSelectSort("SelectSort", font, 36), tBubbleSort("BubbleSort", font, 36), tShakerSort("ShakerSort", font, 36),
		tInsertionSort("InsertionSort", font, 36), tShellSort("ShellSort", font, 36), tHeapSort("HeapSort", font, 36), tQuickSort("QuickSort", font, 36), tQuickSort2("QuickSort2", font, 36);
	Text tBSearch("Bin Search", font, 36), tIndexSort("Index Sort", font, 36), tDigitalSort("Digital Sort", font, 36);
	Text tCompare("Compare", font, 36), tExit("Exit", font, 36);
	Text tMenu11("Menu11", font, 36);

	RectangleShape rSelectSort(Vector2f(200, 50)), rBubbleSort(Vector2f(200, 50)), rShakerSort(Vector2f(200, 50)),
		rInsertionSort(Vector2f(200, 50)), rShellSort(Vector2f(200, 50)), rHeapSort(Vector2f(200,50)),
		rQuickSort(Vector2f(200,50)), rQuickSort2(Vector2f(200, 50)), rDigitalSort(Vector2f(200,50));
	RectangleShape rBSearch(Vector2f(200, 50)), rIndexSort(Vector2f(200, 50));
	RectangleShape rCompare(Vector2f(200, 50)), rExit(Vector2f(170, 50));
	RectangleShape rMenu11(Vector2f(200, 50));

	CreateButton(rSelectSort, tSelectSort, Vector2f(50, 50));
	CreateButton(rBubbleSort, tBubbleSort, Vector2f(50, 145));
	CreateButton(rShakerSort, tShakerSort, Vector2f(50, 240));
	CreateButton(rInsertionSort, tInsertionSort, Vector2f(50, 335));
	CreateButton(rShellSort, tShellSort, Vector2f(50, 430));
	CreateButton(rHeapSort, tHeapSort, Vector2f(435, 145));
	CreateButton(rQuickSort, tQuickSort, Vector2f(435, 240));
	CreateButton(rQuickSort2, tQuickSort2, Vector2f(435, 335));
	CreateButton(rDigitalSort, tDigitalSort, Vector2f(685, 145));
	CreateButton(rMenu11, tMenu11, Vector2f(435, 430));
	CreateButton(rCompare, tCompare, Vector2f(435, 50));
	CreateButton(rExit, tExit, Vector2f(50, 610));

	CreateButton(rBSearch, tBSearch, Vector2f(50, 525));
	CreateButton(rIndexSort, tIndexSort, Vector2f(435, 525));

	bool isMenu = 1;
	int menuNum = 0;

	while (isMenu)
	{
		Event event;
		menuNum = 0;

		DefaultMenuBackground();

		DefaultButton(rSelectSort, tSelectSort);
		DefaultButton(rBubbleSort, tBubbleSort);
		DefaultButton(rShakerSort, tShakerSort);
		DefaultButton(rInsertionSort, tInsertionSort);
		DefaultButton(rShellSort, tShellSort);
		DefaultButton(rHeapSort, tHeapSort);
		DefaultButton(rQuickSort, tQuickSort);
		DefaultButton(rQuickSort2, tQuickSort2);
		DefaultButton(rMenu11, tMenu11);
		DefaultButton(rDigitalSort, tDigitalSort);
		DefaultButton(rCompare, tCompare);
		rCompare.setFillColor(Color(69, 90, 100));
		DefaultButton(rExit, tExit);
		DefaultButton(rBSearch, tBSearch);
		DefaultButton(rIndexSort, tIndexSort);

		if (IntRect(50, 50, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rSelectSort); menuNum = 1;
		}
		if (IntRect(50, 145, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rBubbleSort); menuNum = 2;
		}
		if (IntRect(50, 240, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rShakerSort); menuNum = 3;
		}
		if (IntRect(50, 335, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rInsertionSort); menuNum = 4;
		}
		if (IntRect(50, 430, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rShellSort); menuNum = 5;
		}
		if (IntRect(50, 535, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rBSearch); menuNum = 6;
		}
		if (IntRect(435, 535, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rIndexSort); menuNum = 7;
		}
		if (IntRect(435, 145, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rHeapSort); menuNum = 8;
		}
		if (IntRect(435, 240, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rQuickSort); menuNum = 9;
		}
		if (IntRect(435, 335, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rQuickSort2); menuNum = 10;
		}
		if (IntRect(435, 435, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rMenu11); menuNum = 11;
		}
		if (IntRect(685, 145, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rDigitalSort); menuNum = 13;
		}
		if (IntRect(435, 50, 200, 50).contains(Mouse::getPosition(window)))
		{
			rCompare.setFillColor(Color(84, 110, 122));; menuNum = 100;
		}
		if (IntRect(50, 620, 170, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rExit); menuNum = 1666;
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
						SortMenu(window, 1);
					}
					if (menuNum == 2)
					{
						SortMenu(window, 2);
					}
					if (menuNum == 3)
					{
						SortMenu(window, 3);
					}
					if (menuNum == 4)
					{
						SortMenu(window, 4);
					}
					if (menuNum == 5)
					{
						SortMenu(window, 5);
					}
					if (menuNum == 6)
					{
						BSearchMenu(window);
					}
					if (menuNum == 7)
					{
						IndexSortMenu();
					}
					if (menuNum == 8)
					{
						SortMenu(window, 6);
					}
					if (menuNum == 9)
					{
						SortMenu(window, 7);
					}
					if (menuNum == 10)
					{
						SortMenu(window, 8);
					}
					if (menuNum == 11) {
						Menu11(window);
					}
					if (menuNum == 13) {
						SortMenu(window, 10);
					}
					if (menuNum == 100)
					{
						CompareMenu(window);
					}
					if (menuNum == 1666)
					{
						isMenu = false;
						exit(1666);
						window.close();
					}
				}
			}
		}
		
		DrawButton(rSelectSort, tSelectSort);
		DrawButton(rBubbleSort, tBubbleSort);
		DrawButton(rShakerSort, tShakerSort);
		DrawButton(rInsertionSort, tInsertionSort);
		DrawButton(rShellSort, tShellSort);
		DrawButton(rHeapSort, tHeapSort);
		DrawButton(rQuickSort, tQuickSort);
		DrawButton(rQuickSort2, tQuickSort2);
		DrawButton(rDigitalSort, tDigitalSort);
		DrawButton(rMenu11, tMenu11);
		DrawButton(rCompare, tCompare);
		DrawButton(rExit, tExit);

		DrawButton(rBSearch, tBSearch);
		DrawButton(rIndexSort, tIndexSort);

		window.display();
	}
}