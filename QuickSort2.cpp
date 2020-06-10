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

int partition(vector<int>&mass, int& M, int& C, int L, int R) {
	//int z = mass[R];
	//int i = (L - 1);
	//for (int j = L; j <= R - 1; j++)
	//{
	//	//Ñ++;
	//	if (mass[j] < z)
	//	{
	//		++i;
	//		swap(mass[i], mass[j]);
	//	}
	//}
	//swap(mass[i + 1], mass[R]);
	//return (i + 1);
	return 1;
}

void QuickSort2(vector<int>& mass, int& M, int& C, int& D, int L, int R) {
	//D = 0;
	//int x = mass[L], i = L, j = R;
	//if (L < R) {
	//	//int part = partition(mass, M, C, L, part - 1);
	//	C++;
	//	QuickSort2(mass, M, C, D, L, part - 1);
	//	QuickSort2(mass, M, C, D, part + 1, R);
	//	//if (j - L > R - i) {
	//	//	QuickSort2(mass, M, C, D, L, part - 1);
	//	//	//R = j;
	//	//}
	//	//else {
	//	//	QuickSort2(mass, M, C, D, part + 1, R);
	//	//	//L = i;
	//	//}
	//}
	//D++;
}