#pragma once
#include <iostream>
#include <algorithm>
#include <sstream>
#include <thread>
#include <SFML/Graphics.hpp>

using namespace sf;

void menu(RenderWindow& window);
void DefaultButtonText(Text& text);
void DefaultButtonRect(RectangleShape& shape);
void HoverButtonRect(RectangleShape& shape);
void SetOriginOnCenter(Text& text);