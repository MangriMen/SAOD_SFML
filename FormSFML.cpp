
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
	Font None;				// ����� ��������� �������������

	class Label {
	public:
		string text;	//�����
	protected:
		double x;		//���������� x
		double y;		//���������� y

		Text TXT;		//������������ �����

	public:
		Label(double _x = 0, double _y = 0, string _text = "�����")
		{
			None.loadFromFile("ttf/None.ttf");			//�������� ������ ������ ���� ������

			x = _x;
			y = _y;
			text = _text;								// ��������� �����
			TXT.setFont(None);							// ��������� �����
			TXT.setCharacterSize(20); 					// � ��������, � �� ������!
			TXT.setColor(Color::White);					// ������������� ���� ���������� ������
			TXT.setPosition(x, y);						// ������� ������
		}
		Text displayText()
		{
			TXT.setString(text);						// ��������� � ��������� ����� ����������� �����
			return TXT;
		}
	};

	class Button : public Label {
	protected:
		double width;		// ������ ������
		double height;		// ������ ������
		RectangleShape BOX;	// ������� ������������� � �������� width, height
	public:
		Button(double _x = 0, double _y = 0, double _width = 150, double _height = 30, string _text = "������")
		{
			None.loadFromFile("ttf/None.ttf");			//�������� ������ ������ ���� ������

			x = _x;
			y = _y;
			width = _width;
			height = _height;
			text = _text;								// ��������� �����
			TXT.setFont(None);							// ��������� �����
			TXT.setCharacterSize(20); 					// � ��������, � �� ������!
			TXT.setColor(Color::White);					// ������������� ���� ���������� ������
			TXT.setPosition(x, y);						// ������� ������

			BOX.setSize(Vector2f(width, height));		// ������ ������
			BOX.setPosition(x, y);						// ���������� ������
			BOX.setFillColor(sf::Color(133, 133, 133));	// ���� ������
			BOX.setOutlineThickness(2);					// ������ X ��������
			BOX.setOutlineColor(Color(66, 66, 66));		// ���� �������
		}
		//�������� ������� �� ������
		bool select(Vector2i _mouse)
		{
			if ((_mouse.x > x&& _mouse.x < x + width) && (_mouse.y > y&& _mouse.y < y + height)) {
				return  true;
			}
			else {
				return false;
			}
		}
		//����� ������
		Text displayText()
		{
			TXT.setString(text);  // ��������� � ��������� ����� ����������� �����
			return TXT;
		}
		//����� ������
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
			text = _text;								// ��������� �����
			focus = false;								// ����� ���� �����

			TXT.setFont(None);							// ��������� �����
			TXT.setCharacterSize(20); 					// � ��������, � �� ������!
			TXT.setColor(Color::Black);					// ������������� ���� ���������� ������
			TXT.setPosition(x, y);						// ������� ������

			BOX.setSize(Vector2f(width, height));		// ������ ���� �����
			BOX.setPosition(x, y);						// ���������� ���� �����
			BOX.setFillColor(Color::White);	// ���� ������
		}
		//����� .reText( char ) �������� ����� ������ ������ ���� ������ Input
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

		// �������� ������ Input
		bool select()
		{
			return focus;
		}

		// ��������� ������ Input
		bool select(Vector2i _mouse)
		{
			if ((_mouse.x > x&& _mouse.x < x + width) && (_mouse.y > y&& _mouse.y < y + height)) { 	//���� ����� ������ ��� �������� Input...
				focus = true;																	   	// ����� true
				text += "|";																		// � ����� ������ �������� | (��� �� �������� ��� input � ������)
			}
			else {																				//...����� ���� ������� ��������� �� ��� ��������, ��...
				if (text.size() > 0) {																// �������� ���������� �������(����� ��������)
					if (text[text.size() - 1] == 124) {													// ���� ������ | ...
						text.erase(text.size() - 1);														// ... �� ������� ���
					}
				}
				focus = false;																		// ������������� ����� false
			}
			return focus;
		}

		//����� ������
		Text displayText()
		{
			TXT.setString(text);						// ��������� � ��������� ����� ����������� �����
			return TXT;
		}

		//����� ���� Input
		RectangleShape displayBOX()
		{
			return BOX;
		}

		//��� ����, ��� �� ������� ����� � ���� Ipnut ���������� ���������  readText() ������� ���������� string
		string readText()
		{
			if (text[text.size() - 1] == 124) { 	// ������� (���� ����) ������ |
				text.erase(text.size() - 1);
			}
			return text;
		}
	};

} /* namespace form */