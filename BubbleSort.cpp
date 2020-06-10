#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "menu.hpp"
#include "ArrOperations.hpp"
#include "Constants.hpp"

using namespace sf;

void BubbleSort(vector<int>& mass, int &M, int &C)
{
	M = 0, C = 0;
	for (int i = 0; i < mass.size() - 1; ++i)
	{
		for (int j = 0; j < mass.size() - i - 1; ++j)
		{
			if (mass[j] > mass[j + 1])
			{
				swap(mass[j], mass[j + 1]);
			}
		}
	}
}