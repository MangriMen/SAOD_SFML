#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <sstream>
#include <thread>
#include <SFML/Graphics.hpp>

using namespace std;

void FillInc(vector<int>& mass, int size)
{
	mass.clear();
	for (int i = 1; i <= size; i++)
	{
		mass.push_back(i);
	}
}

void FillDec(vector<int>& mass, int size)
{
	mass.clear();
	for (int i = size; i > 0; i--)
	{
		mass.push_back(i);
	}
}

void FillRand(vector<int>& mass, int size)
{
	mass.clear();
	for (int i = 0; i < size; i++)
	{
		mass.push_back(rand() % size * 2 - size);
	}
}

int CheckSum(vector<int> mass)
{
	int sum = 0;
	for (int i = 0; i < mass.size(); i++)
	{
		sum += mass[i];
	}
	return sum;
}

int RunNumber(vector<int> mass)
{
	cout << endl;
	int t = 0, c = 0;
	for (int i = 0; i < mass.size() - 1; i++)
	{
		if (mass[i] <= mass[i + 1])
		{
			t++;
		}
		else
		{
			c++;
		}
	}
	c++;
	return c;
}


void PrintMasG(vector<int> mass, sf::Text& text)
{
	std::string str;
	std::stringstream result;
	std::copy(mass.begin(), mass.end(), std::ostream_iterator<int>(result, " "));
	str = result.str();
	text.setString(str);
}

void OyGraphNum(int i,int MpC, sf::RectangleShape &rOy, vector<sf::Text> &temp, sf::Font &font, int sortDevider)
{
	if (i % 50 == 0)
	{
		sf::Text tt(to_string(MpC), font, 10);
		tt.setPosition(rOy.getPosition() + sf::Vector2f(-80, -(MpC) / sortDevider));
		temp.push_back(tt);
	}
}