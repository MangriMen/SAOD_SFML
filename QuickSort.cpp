#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "menu.hpp"
#include "ArrOperations.hpp"

void QuickSort(vector<int>& mass, int& M, int& C, int& D, int L, int R) {
	D = 0;
	int x = mass[L], i = L, j = R;
	int k = 0;
	while (i <= j) {
		while (mass[i] < x) { C++; i++;}
		while (mass[j] > x) { C++; j--;}
		C++;
		if (i <= j) {
			swap(mass[i], mass[j]);
			M += 3;
			i++;
			j--;
		}
	}
	C++;
	if (L < j) {
		QuickSort(mass, M, C, D, L, j);
	}
	C++;
	if (i < R) {
		QuickSort(mass, M, C, D, i, R);
	}
	D++;
}