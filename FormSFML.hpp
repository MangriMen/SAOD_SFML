#pragma once
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace form {

	class Label {
	public:
		Label(string text_ = "Text", double x_ = 0, double y_ = 0, bool center_ = false, size_t size_ = 20, Color color_ = Color::White) {
			font.loadFromFile("fonts/Roboto/Roboto-Bold.ttf");

			x = x;
			y = y;
			text = text_;
			centered = center_;

			TXT.setFont(font);
			TXT.setCharacterSize(size_);
			TXT.setFillColor(color_);
			TXT.setPosition(x_, y_);
			TXT.setString(text_);

			if (center_) {
				updateTextOrigin();
			}
		}

		string getText();
		void setText(string text_);

		void updateTextOrigin();

		Text display();

	protected:
		double x;
		double y;
		bool centered;

		Font font;
		string text;
		Text TXT;
	};
	class Button: public Label {
	public:
		Button(double x_ = 0, double y_ = 0, double width_ = 200, double height_ = 50, string text_ = "", size_t size_ = 20, Color buttonColor_ = Color(133, 133, 133), Color color_ = Color::White) {
			font.loadFromFile("fonts/Roboto/Roboto-Bold.ttf");

			x = x_;
			y = y_;
			width = width_;
			height = height_;
			text = text_;

			TXT.setFont(font);
			TXT.setCharacterSize(size_);
			TXT.setFillColor(color_);
			TXT.setString(text_);

			FloatRect fRect = TXT.getLocalBounds();
			TXT.setOrigin(fRect.left + fRect.width / 2.0f,
				fRect.top + fRect.height / 2.0f);

			TXT.setPosition(x_ + width_ / 2, y_ + height_ / 2);

			BOX.setSize(Vector2f(width_, height_));
			BOX.setPosition(x_, y_);
			BOX.setFillColor(buttonColor_);
			BOX.setOutlineThickness(2);
			BOX.setOutlineColor(Color(66, 66, 66));
		}
		
		bool select(Vector2i mouse_);

		void setStyle(string style);
		void setPosition(double x_, double y_);

		Text displayText();
		RectangleShape displayButton();

	protected:
		double width;
		double height;

		RectangleShape BOX;
	};
	class ImageButton : public Button {
	public:
		ImageButton(double x_ = 0, double y_ = 0, double width_ = 0, double height_ = 0, string image_ = "", string text_ = "", size_t size_ = 20, Color buttonColor_ = Color(133, 133, 133), Color color_ = Color::White) {
			x = x_;
			y = y_;
			width = width_;
			height = height_;
			text = text_;

			BOX.setSize(Vector2f(width_, height_));
			BOX.setPosition(x_, y_);
			BOX.setFillColor(buttonColor_);
			BOX.setOutlineThickness(2);
			BOX.setOutlineColor(Color(66, 66, 66));

			TEXTURE.loadFromFile(image_);
			SPRITE.setTexture(TEXTURE, true);
			SPRITE.setScale(width_ / SPRITE.getLocalBounds().width, height_ / SPRITE.getLocalBounds().height);
			SPRITE.setPosition(x_, y_);
		}

		Sprite displaySprite();
	private:
		Texture TEXTURE;
		Sprite SPRITE;
	};
	class Input : public Button {
	public:
		Input(double x_ = 0, double y_ = 0, double width_ = 200, double height_ = 50, string text_ = "", size_t size_ = 20, Color buttonColor_ = Color(133, 133, 133), Color color_ = Color::White) {
			x = x_;
			y = y_;
			width = width_;
			height = height_;
			text = text_;
			focus = false;

			TXT.setFont(font);
			TXT.setCharacterSize(size_);
			TXT.setFillColor(color_);
			TXT.setPosition(x_ + 10, y_ + height_ / 4);
			TXT.setString(text_);

			FloatRect fRect = TXT.getLocalBounds();
			TXT.setOrigin(fRect.left + fRect.width / 2.0f,
				fRect.top + fRect.height / 2.0f);

			BOX.setSize(Vector2f(width_, height_));
			BOX.setPosition(x, y);
			BOX.setFillColor(buttonColor_);
			BOX.setOutlineThickness(2);
			BOX.setOutlineColor(Color(66, 66, 66));
		}
		
		void reText(char tmp_);
		bool select();
		bool select(Vector2i mouse_);

		Text displayText();
		RectangleShape displayBOX();
		string readText();

	protected:
		bool focus;
	};
} // namespace form