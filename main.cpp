#include <iostream>
#include <SFML/Graphics.hpp>
#include "menu.hpp"
#include "ArrOperations.hpp"
#include "SelectSort.hpp"

using namespace std;


int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1280, 720), "SortTypes", Style::Default, settings);
	window.setVerticalSyncEnabled(true);

	while(window.isOpen())
	{
		menu(window);
	}
	return 0;
}