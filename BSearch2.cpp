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

int BSearch2(vector<int>& mass, int& C, int key, int& pos)
{
	C = 0;
	pos = 0;
	int L = 1, R = mass.size() - 1, m = 0;
	bool isFind = false;
	while (L <= R)
	{
		m = (L + R) / 2;
		C++;
		if (mass[m] < key)
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	}
	C++;
	if (mass[m] == key) {
		pos = m;
		isFind = true;
	}
	return isFind;
}
