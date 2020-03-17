
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
#include <string>

using namespace std;
using namespace sf;

namespace form {
	Font None;				// Шрифт первичная инициализация

	class Label {
	public:
		string text;	//Текст
	protected:
		double x;		//Координата x
		double y;		//Координата y

		Text TXT;		//Отображаемый текст

	public:
		Label(double _x = 0, double _y = 0, string _text = "Текст")
		{
			None.loadFromFile("ttf/None.ttf");			//передаем нашему шрифту файл шрифта

			x = _x;
			y = _y;
			text = _text;								// загружает текст
			TXT.setFont(None);							// загружаем фрифт
			TXT.setCharacterSize(20); 					// в пикселях, а не точках!
			TXT.setColor(Color::White);					// устанавливаем цвет выводимого текста
			TXT.setPosition(x, y);						// позиция текста
		}
		Text displayText()
		{
			TXT.setString(text);						// загружаем в выводимый текст загружаемый текст
			return TXT;
		}
	};

	class Button : public Label {
	protected:
		double width;		// Ширина Кнопки
		double height;		// Высота Кнопки
		RectangleShape BOX;	// Создаем прямоугольник с размером width, height
	public:
		Button(double _x = 0, double _y = 0, double _width = 150, double _height = 30, string _text = "Кнопка")
		{
			None.loadFromFile("ttf/None.ttf");			//передаем нашему шрифту файл шрифта

			x = _x;
			y = _y;
			width = _width;
			height = _height;
			text = _text;								// загружает текст
			TXT.setFont(None);							// загружаем фрифт
			TXT.setCharacterSize(20); 					// в пикселях, а не точках!
			TXT.setColor(Color::White);					// устанавливаем цвет выводимого текста
			TXT.setPosition(x, y);						// позиция текста

			BOX.setSize(Vector2f(width, height));		// размер кнопки
			BOX.setPosition(x, y);						// координаты кнопки
			BOX.setFillColor(sf::Color(133, 133, 133));	// цвет кнопки
			BOX.setOutlineThickness(2);					// Контур X пикселей
			BOX.setOutlineColor(Color(66, 66, 66));		// Цвет контура
		}
		//Проверка нажатия на кнопку
		bool select(Vector2i _mouse)
		{
			if ((_mouse.x > x&& _mouse.x < x + width) && (_mouse.y > y&& _mouse.y < y + height)) {
				return  true;
			}
			else {
				return false;
			}
		}
		//Вывод Текста
		Text displayText()
		{
			TXT.setString(text);  // загружаем в выводимый текст загружаемый текст
			return TXT;
		}
		//Вывод кнопки
		RectangleShape displayButton()
		{
			return BOX;
		}


	};

	class Input : public Button {
	protected:
		bool focus;
	public:
		Input(double _x = 0, double _y = 0, double _width = 150, double _height = 30, string _text = "")
		{
			x = _x;
			y = _y;
			width = _width;
			height = _height;
			text = _text;								// загружает текст
			focus = false;								// фокус поля ввода

			TXT.setFont(None);							// загружаем фрифт
			TXT.setCharacterSize(20); 					// в пикселях, а не точках!
			TXT.setColor(Color::Black);					// устанавливаем цвет выводимого текста
			TXT.setPosition(x, y);						// позиция текста

			BOX.setSize(Vector2f(width, height));		// размер поля ввода
			BOX.setPosition(x, y);						// координаты поля ввода
			BOX.setFillColor(Color::White);	// цвет кнопки
		}
		//метод .reText( char ) изменяет текст внутри класса Типа данных Input
		void reText(char _tmp)
		{
			text.erase(text.size() - 1);

			if (_tmp != 8) {
				text += _tmp;
			}
			else {
				if (text.size() > 0) {
					text.erase(text.size() - 1);
				}

			}
			text += "|";
			TXT.setString(text);
		}

		// Проверка Фокуса Input
		bool select()
		{
			return focus;
		}

		// Установка Фокуса Input
		bool select(Vector2i _mouse)
		{
			if ((_mouse.x > x&& _mouse.x < x + width) && (_mouse.y > y&& _mouse.y < y + height)) { 	//Если нажат клаиша над объектом Input...
				focus = true;																	   	// Фокус true
				text += "|";																		// В конец строки добаляем | (что бы понимать что input в фокусе)
			}
			else {																				//...Иначе если нажатие произошло не над объектом, то...
				if (text.size() > 0) {																// проверка последнего символа(иначе вылетает)
					if (text[text.size() - 1] == 124) {													// если символ | ...
						text.erase(text.size() - 1);														// ... то удаляем его
					}
				}
				focus = false;																		// устанавливаем фокус false
			}
			return focus;
		}

		//Вывод Текста
		Text displayText()
		{
			TXT.setString(text);						// загружаем в выводимый текст загружаемый текст
			return TXT;
		}

		//Вывод фона Input
		RectangleShape displayBOX()
		{
			return BOX;
		}

		//Для того, что бы считать текст с поля Ipnut необходимо пременить  readText() который возвращает string
		string readText()
		{
			if (text[text.size() - 1] == 124) { 	// удаляем (если есть) символ |
				text.erase(text.size() - 1);
			}
			return text;
		}
	};

} /* namespace form */