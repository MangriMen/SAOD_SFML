#include <iostream>
#include <thread>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "SelectSort.hpp"
#include "BubbleSort.hpp"
#include "ShakerSort.hpp"
#include "compare.hpp"

using namespace sf;

void DefaultButtonText(Text& text)
{
	text.setFillColor(Color::White);
}

void DefaultButtonRect(RectangleShape& shape)
{
	shape.setFillColor(Color(51, 51, 54));
}

void HoverButtonRect(RectangleShape& shape)
{
	shape.setFillColor(Color(68, 68, 70));
}

void SetOriginOnCenter(Text& text) {
	FloatRect tSelectSortFR = text.getLocalBounds();
	text.setOrigin(tSelectSortFR.left + tSelectSortFR.width / 2.0f,
		tSelectSortFR.top + tSelectSortFR.height / 2.0f);
}

void menu(RenderWindow& window) {
	Font font;
	font.loadFromFile("fonts/Roboto/Roboto-Regular.ttf");
	Text tSelectSort("SelectSort", font, 36), tBubbleSort("BubbleSort", font, 36), tShakerSort("ShakerSort", font, 36),
		tBubble_Shaker("Compare", font, 36), tExit("Exit", font, 36);

	RectangleShape rSelectSort(Vector2f(190, 50)), rBubbleSort(Vector2f(190, 50)), rShakerSort(Vector2f(190, 50)),
		rBubble_Shaker(Vector2f(190, 50)), rExit(Vector2f(170, 50));

	rSelectSort.setPosition(Vector2f(50, 50));
	rBubbleSort.setPosition(Vector2f(50, 145));
	rShakerSort.setPosition(Vector2f(50, 240));
	rBubble_Shaker.setPosition(Vector2f(435, 50));
	rExit.setPosition(Vector2f(50, 610));

	SetOriginOnCenter(tSelectSort);
	tSelectSort.setPosition(rSelectSort.getSize() / 2.0f + rSelectSort.getPosition());

	SetOriginOnCenter(tBubbleSort);
	tBubbleSort.setPosition(rBubbleSort.getSize() / 2.0f + rBubbleSort.getPosition());

	SetOriginOnCenter(tShakerSort);
	tShakerSort.setPosition(rShakerSort.getSize() / 2.0f + rShakerSort.getPosition());

	SetOriginOnCenter(tBubble_Shaker);
	tBubble_Shaker.setPosition(rBubble_Shaker.getSize() / 2.0f + rBubble_Shaker.getPosition());

	SetOriginOnCenter(tExit);
	tExit.setPosition(rExit.getSize() / 2.0f + rExit.getPosition());

	bool isMenu = 1;
	int menuNum = 0;

	while (isMenu)
	{
		Event event;
		menuNum = 0;

		window.clear(Color(34, 34, 38));

		DefaultButtonRect(rSelectSort);
		DefaultButtonRect(rBubbleSort);
		DefaultButtonRect(rShakerSort);
		DefaultButtonRect(rBubble_Shaker);
		DefaultButtonRect(rExit);

		DefaultButtonText(tSelectSort);
		DefaultButtonText(tBubbleSort);
		DefaultButtonText(tShakerSort);
		DefaultButtonText(tBubble_Shaker);
		DefaultButtonText(tExit);

		if (IntRect(50, 50, 190, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rSelectSort); menuNum = 1;
		}
		if (IntRect(50, 145, 190, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rBubbleSort); menuNum = 2;
		}
		if (IntRect(50, 240, 190, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rShakerSort); menuNum = 3;
		}
		if (IntRect(435, 50, 190, 50).contains(Mouse::getPosition(window)))
		{
			HoverButtonRect(rBubble_Shaker); menuNum = 4;
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
						SelectSortMenu(window);
					}
					if (menuNum == 2)
					{
						BubbleSortMenu(window);
					}
					if (menuNum == 3)
					{
						ShakerSortMenu(window);
					}
					if (menuNum == 4)
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

		window.draw(rSelectSort);
		window.draw(rBubbleSort);
		window.draw(rShakerSort);
		window.draw(rBubble_Shaker);
		window.draw(rExit);

		window.draw(tSelectSort);
		window.draw(tBubbleSort);
		window.draw(tShakerSort);
		window.draw(tBubble_Shaker);
		window.draw(tExit);

		window.display();
	}
}