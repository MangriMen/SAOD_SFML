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

void BinTable(vector<int>& mass, vector< vector<Text> >& tFill, Font& font);
void BinTableAll(vector<int>& mass, vector< vector<Text> >& tFill, Font& font);
void BSearchMenu(RenderWindow& window);