#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Stack.hpp"
#include "FormSFML.hpp"

using namespace std;
using namespace sf;

void FillInc(vector<int>& mass, int size);
void FillInc(Stack<int>& mass, int size);
void FillDec(vector<int>& mass, int size);
void FillDec(Stack<int>& mass, int size);
void FillRand(vector<int>& mass, int size);
void FillRand(Stack<int>& mass, int size);
int CheckSum(vector<int> mass);
int RunNumber(vector<int> mass);
void PrintMasG(vector<int> mass, Text& text);
void PrintMasG(Stack<int>& mass, form::Label& text);
void OyGraphNum(int i, int MpC, sf::RectangleShape& rOy, vector<sf::Text>& temp, sf::Font &font, double sortDevider, int textStep);