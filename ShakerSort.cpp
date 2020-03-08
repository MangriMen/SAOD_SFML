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

void ShakerSort(vector<int>& mass, int& M, int& C)
{
	int R = mass.size() - 1, L = 0, k = mass.size();
	M = 0;
	C = 0;
	while (L < R) {
		for (int i = R; i > L; --i) {
			C++;
			if (mass[i] < mass[i - 1]) {
				swap(mass[i], mass[i - 1]);
				M += 3;
				k = i;
			}
		}
		L = k;
		for (int j = L; j < R; ++j) {
			C++;
			if (mass[j] > mass[j + 1]) {
				swap(mass[j], mass[j + 1]);
				M += 3;
				k = j;
			}
		}
		R = k;
	}
}