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

void ShellSort(vector<int>& mass, int& M, int& C)
{
	M = 0; C = 0;
	int j = 0, t = 0;
	for (int k = mass.size() / 2; k > 0; k--)
	{
		C++;
		for (int i = k; i < mass.size(); i++)
		{
			C++;
			t = mass[i];
			j = i - k;

			while (j >= 0 && t < mass[j])
			{
				mass[j + k] = mass[j];
				j = j - k;
				M += 3;
			}
			mass[j + k] = t;
		}
	}
	/*for (int step = mass.size() / 2; step > 0; step /= 2)
	{
		C++;
		for (int i = step; i < mass.size(); i++)
		{
			for (j = i - step; j >= 0 && mass[j] > mass[j + step]; j -= step)
			{
				swap(mass[j], mass[j + step]);
				M++;
			}
		}
	}*/
}