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

using namespace std;
using namespace sf;

void ShakerSort(vector<int>& mass, int& M, int& C);
void ShakerSortMenu(RenderWindow& window);