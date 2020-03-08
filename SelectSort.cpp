#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "menu.hpp"
#include "ArrOperations.hpp"
#include "Constants.hpp"

using namespace sf;

#define ClearField() tArrayOutO.setString("");

void SelectSort(vector<int>& mass, int &M, int &C)
{
	int min;
	M = 0, C = 0;
	for (int i = 0; i < mass.size() - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < mass.size(); j++)
		{
			C++;
			if (mass[j] < mass[min])
			{
				min = j;
			}
		}
		swap(mass[min], mass[i]);
		M += 3;
	}
}

void SelectSortOpt(vector<int>& mass, int& M, int& C)
{
	int min;
	M = 0, C = 0;
	for (int i = 0; i < mass.size() - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < mass.size(); j++)
		{
			C++;
			if (mass[j] < mass[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			M += 3;
			swap(mass[i], mass[min]);
		}
	}

}