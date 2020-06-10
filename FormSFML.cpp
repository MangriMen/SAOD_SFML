#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "FormSFML.hpp"

using namespace std;
using namespace sf;

string form::Label::getText()
{
	return text;
}

void form::Label::setText(string text_)
{
	text = text_;
}

void form::Label::updateTextOrigin()
{
	FloatRect fRect = TXT.getLocalBounds();
	TXT.setOrigin(fRect.left + fRect.width / 2.0f,
		fRect.top + fRect.height / 2.0f);
}

Text form::Label::display() {
	if (centered)
	{
		updateTextOrigin();
	}
	TXT.setString(text);
	return TXT;
}

bool form::Button::select(Vector2i mouse_)
{
	if ((mouse_.x > x && mouse_.x < x + width) &&
		mouse_.y > y && mouse_.y < y + height) {
		return true;
	}
	else {
		return false;
	}
}

void form::Button::setStyle(string style_)
{
	if (style_ == "default") {
		BOX.setFillColor(Color(133, 133, 133));
	}
	else if (style_ == "hover") {
		BOX.setFillColor(Color(84, 110, 122));
	}
}

void form::Button::setPosition(double x_, double y_)
{
	BOX.setPosition(x_, y_);
}

Text form::Button::displayText()
{
	updateTextOrigin();
	TXT.setString(text);
	return TXT;
}

RectangleShape form::Button::displayButton()
{
	return BOX;
}

void form::Input::reText(char tmp_)
{
	text.erase(text.size() - 1);
	if (tmp_ != 8) {
		text += tmp_;
	}
	else {
		if (text.size() > 0) {
			text.erase(text.size() - 1);
		}
	}
	text += "|";
	TXT.setString(text);
}

bool form::Input::select()
{
	return focus;
}

bool form::Input::select(Vector2i mouse_)
{
	if ((mouse_.x > x && mouse_.x < x + width) &&
		(mouse_.y > y && mouse_.y < y + height)) {
		focus = true;
		text += "|";
	}
	else {
		if (text.size() > 0) {
			if (text[text.size() - 1] == 124) {
				text.erase(text.size() - 1);
			}
		}
		focus = false;
	}
	return true;
}

Text form::Input::displayText()
{
	TXT.setString(text);
	return TXT;
}

RectangleShape form::Input::displayBOX()
{
	return BOX;
}

string form::Input::readText()
{
	if (text[text.size() - 1] == '|') {
		text.erase(text.size() - 2);
	}
	
	return text;
}

Sprite form::ImageButton::displaySprite()
{
	return SPRITE;
}
