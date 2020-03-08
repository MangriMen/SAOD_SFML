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

using namespace std;

void InsertionSort(vector<int>& mass, int& M, int& C)
{
	M = 0, C = 0;
	int t = 0, j = 0;
	for (int i = 1; i < mass.size(); i++)
	{
		t = mass[i];
		j = i - 1;
		M++;
		while (j >= 0 && t < mass[j])
		{
			mass[j + 1] = mass[j];
			j = j - 1;
			M ++;
			C++;
		}
		if (!(j >= 0 && t < mass[j]))
		{
			M++;
			C++;
		}
		mass[j + 1] = t;
	}
}