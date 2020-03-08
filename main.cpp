#include <iostream>
#include <SFML/Graphics.hpp>
#include "menu.hpp"

using namespace std;
using namespace sf;

int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(1280, 720), "SortTypes", Style::Default, settings);
	window.setVerticalSyncEnabled(true);

	while(window.isOpen())
	{
		menu(window);
	}

	return 0;
}