#include <iostream>
#include <SFML/Graphics.hpp>

#include "FormSFML.hpp"

#include "menu.hpp"
#include "ArrOperations.hpp"
#include "Stack.hpp"

using namespace std;
using namespace sf;

void Menu11(RenderWindow& window)
{
	Stack<int> a;

	int M = 0, C = 0, K = 0, D = 0;

	form::Button lArrayOut(605, 50, 550, 50, ""), lCheckSum(435, 120, 200, 50, ""), lSeries(435, 170, 200, 50, "");
	form::Button bClearArray(435, 50, 50, 50, "C"), bFillInc(50, 50, 170, 50, "FillInc"),
		bFillDec(50, 145, 170, 50, "FillDec"), bFillRand(50, 240, 170, 50, "FillRand"),
		bBackToMenu(50, 610, 170, 50, "Menu");

	while (window.isOpen())
	{
		Event event;
		Vector2i mouse = Mouse::getPosition(window);

		DefaultMenuBackground();

		bClearArray.setStyle("default");
		bFillInc.setStyle("default");
		bFillDec.setStyle("default");
		bFillRand.setStyle("default");
		bBackToMenu.setStyle("default");

		if (bClearArray.select(mouse)) {
			bClearArray.setStyle("hover");
		}
		if (bFillInc.select(mouse)) {
			bFillInc.setStyle("hover");
		}
		if (bFillDec.select(mouse)) {
			bFillDec.setStyle("hover");
		}
		if (bFillRand.select(mouse)) {
			bFillRand.setStyle("hover");
		}
		if (bBackToMenu.select(mouse)) {
			bBackToMenu.setStyle("hover");
		}

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				exit(1999);
				window.close();
			}
			if (event.type == Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					if (bClearArray.select(mouse)) {
						lArrayOut.setText("");
						lCheckSum.setText("CheckSum: ");
						lSeries.setText("Series: ");
					}
					if (bFillInc.select(mouse)) {
						FillInc(a, 18);
						PrintMasG(a, lArrayOut);
						lCheckSum.setText("CheckSum: " + to_string(a.checkSum()));
						lSeries.setText("Series: " + to_string(a.runNumber()));
					}
					if (bFillDec.select(mouse)) {
						FillDec(a, 18);
						PrintMasG(a, lArrayOut);
						lCheckSum.setText("CheckSum: " + to_string(a.checkSum()));
						lSeries.setText("Series: " + to_string(a.runNumber()));
					}
					if (bFillRand.select(mouse)) {
						FillRand(a, 18);
						PrintMasG(a, lArrayOut);
						lCheckSum.setText("CheckSum: " + to_string(a.checkSum()));
						lSeries.setText("Series: " + to_string(a.runNumber()));
					}
					if (bBackToMenu.select(mouse)) {
						menu(window);
					}
				}
			}
		}

		window.draw(lArrayOut.displayButton());
		window.draw(lArrayOut.displayText());

		window.draw(lCheckSum.displayButton());
		window.draw(lCheckSum.displayText());
		
		window.draw(lSeries.displayButton());
		window.draw(lSeries.displayText());

		window.draw(bClearArray.displayButton());
		window.draw(bClearArray.displayText());

		window.draw(bFillInc.displayButton());
		window.draw(bFillInc.displayText());

		window.draw(bFillDec.displayButton());
		window.draw(bFillDec.displayText());

		window.draw(bFillRand.displayButton());
		window.draw(bFillRand.displayText());

		window.draw(bBackToMenu.displayButton());
		window.draw(bBackToMenu.displayText());

		window.display();
	}
}