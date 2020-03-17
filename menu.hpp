#pragma once
#include <iostream>
#include <algorithm>
#include <sstream>
#include <thread>
#include <SFML/Graphics.hpp>

#define DefaultMenuBackground() window.clear(Color(34, 34, 38));
#define DrawButton(button, text) window.draw(button); window.draw(text);
#define DefaultButton(button, text) DefaultButtonRect(button); DefaultButtonText(text);

using namespace sf;

void menu(RenderWindow& window);
void DefaultButtonText(Text& text);
void DefaultButtonRect(RectangleShape& shape);
void DefaultButtonRect(CircleShape& shape);
void HoverButtonRect(RectangleShape& shape);
void HoverButtonRect(CircleShape& shape);
void SetOriginOnCenter(Text& text);
void CreateButton(RectangleShape& button, Text& text, Vector2f position);
void CreateButton(CircleShape& button, Text& text, Vector2f position);