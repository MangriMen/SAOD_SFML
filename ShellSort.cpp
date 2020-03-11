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

void ShellSort(vector<int>& mass, int& M, int& C, int& K, int shellStep)
{
	M = 0; C = 0, K = 0;
	int j = 0, t = 0;
	vector<int> h;
	h.push_back(1);
	for (int i = 1; i < (int)log2(mass.size()) - 1; i++)
	{
		h.push_back(2 * h[i - 1]+ 1);
	}
	if (shellStep == 0)
	{
		for (int k = log2(mass.size()) - 1; k > 0; k--)
		{
			K++;
			for (int i = h[k-1]; i < mass.size(); i++)
			{
				M++;
				C++;
				t = mass[i];
				j = i - h[k-1];
				while (j >= 0 && t < mass[j])
				{
					mass[j + h[k-1]] = mass[j];
					j = j - h[k-1];
					M++;
				}
				if (!(j >= 0 && t < mass[j]))
				{
					C++;
				}
				M++;
				mass[j + h[k-1]] = t;
			}
		}
	}
	else
	{
		for (int k =(int) mass.size()/shellStep; k > 0; k /= shellStep)
		{
			K++;
			for (int i = k; i < mass.size(); i++)
			{
				M++;
				C++;
				t = mass[i];
				j = i - k;

				while (j >= 0 && t < mass[j])
				{
					mass[j + k] = mass[j];
					j = j - k;
					M ++;
				}
				M++;
				mass[j + k] = t;
			}
		}
	/*	for (int step = mass.size() / 2; step > 0; step /= 2)
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
}