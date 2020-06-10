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

void swap(int* x, int* y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void shift(vector<int>& mass, int i, int n, int& M, int& C) {
    int max;
    while (i * 2 + 1 < n) {
        C++;
        if ((i * 2 + 1 == n - 1) || (mass[i * 2 + 1] > mass[i * 2 + 2]))
            max = i * 2 + 1;
        else
            max = i * 2 + 2;
        C++;
        if (mass[i] < mass[max]) {
            swap(&mass[i], &mass[max]);
            i = max;
            M += 3;
        }
        else break;
    }
}

void HeapSort(vector<int>& mass, int& M, int& C)
{
    M = 0, C = 0;
    for (int i = mass.size() / 2 - 1; i >= 0; --i) {
        shift(mass, i, mass.size(), M, C);
    }

    for (int i = mass.size() - 1; i > 0; --i) {
        swap(&mass[0], &mass[i]);
        M +=3 ;
        shift(mass, 0, i, M, C);
    }
}