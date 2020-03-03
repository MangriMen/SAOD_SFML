#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;


void FillInc(vector<int>& mass, int size)
{
	mass.clear();
	for (int i = 1; i <= size; i++)
	{
		mass.push_back(i);
	}
}

void FillDec(vector<int>& mass, int size)
{
	mass.clear();
	for (int i = size; i > 0; i--)
	{
		mass.push_back(i);
	}
}

void FillRand(vector<int>& mass, int size)
{
	mass.clear();
	for (int i = 0; i < size; i++)
	{
		mass.push_back(rand() % size * 2 - size);
	}
}