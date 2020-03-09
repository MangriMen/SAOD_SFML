#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "SortMenu.hpp"
#include "SelectSort.hpp"
#include "BubbleSort.hpp"
#include "ShakerSort.hpp"
#include "InsertionSort.hpp"
#include "ShellSort.hpp"
#include "compare.hpp"

void BSearch1(vector<int>& mass, int& C, int key)
{
	int L = 1, R = mass.size(), m = 0;
	bool find;
	while (L <= R)
	{
		m = (L + R) / 2;
		if (mass[m] == key)
		{
			find = true;
		}
		if (mass[m] < key)
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	}
}