#include <iostream>
#include <SFML/Graphics.hpp>
#include "SortMenu.hpp"
#include "SelectSort.hpp"
#include "BubbleSort.hpp"
#include "ShakerSort.hpp"
#include "InsertionSort.hpp"
#include "ShellSort.hpp"
#include "Constants.hpp"
#include "compare.hpp"
#include "BSearch.hpp"

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
		tInsertionSort("InsertionSort", font, 36), tShellSort("ShellSort", font, 36);
	Text tBSearch("Bin Search", font, 36);
	Text tBubble_Shaker("Compare", font, 36), tExit("Exit", font, 36);

	RectangleShape rSelectSort(Vector2f(200, 50)), rBubbleSort(Vector2f(200, 50)), rShakerSort(Vector2f(200, 50)),
		rInsertionSort(Vector2f(200, 50)), rShellSort(Vector2f(200, 50));
	RectangleShape rBSearch(Vector2f(200, 50));
	RectangleShape rBubble_Shaker(Vector2f(200, 50)), rExit(Vector2f(170, 50));

	CreateButton(rSelectSort, tSelectSort, Vector2f(50, 50));
	CreateButton(rBubbleSort, tBubbleSort, Vector2f(50, 145));
	CreateButton(rShakerSort, tShakerSort, Vector2f(50, 240));
	CreateButton(rInsertionSort, tInsertionSort, Vector2f(50, 335));
	CreateButton(rShellSort, tShellSort, Vector2f(50, 430));
	CreateButton(rBubble_Shaker, tBubble_Shaker, Vector2f(435, 50));
	CreateButton(rExit, tExit, Vector2f(50, 610));

	CreateButton(rBSearch, tBSearch, Vector2f(50, 525));

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
		DefaultButton(rBubble_Shaker, tBubble_Shaker);
		DefaultButton(rExit, tExit);

		DefaultButton(rBSearch, tBSearch);

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
		if (IntRect(435, 50, 200, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rBubble_Shaker); menuNum = 100;
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
		DrawButton(rBubble_Shaker, tBubble_Shaker);
		DrawButton(rExit, tExit);

		DrawButton(rBSearch, tBSearch);

		window.display();
	}
}