#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

struct Teleman {
public:
	string Name;
	string MiddleName;
	string Surname;
	int Number;

	void TeleLine() {
		cout << Surname << " " << Name << " " << MiddleName << " " << Number << endl;
	}
};

void ShellSort(Teleman* a, int size, bool wts, vector<int>& vec) {

	int j = 0, h = (int)log2(sizeof(a)) - 1;
	Teleman t;
	int* StepArr = (int*)new int[h];
	vec.clear();
	cout << endl;
	for (int i = 0; i < size; ++i)
	{
		vec.push_back(i);
		cout << i;
	}
	cout << endl;

	StepArr[0] = 1;
	for (int i = 1; i < h; ++i) {
		StepArr[i] = (2 * StepArr[i - 1] + 1);
	}
	for (int k = h; k > 0; k--) {
		for (int i = StepArr[k - 1]; i < size; i++) {
			t = a[vec[i]];
			j = i - StepArr[k - 1];

			if (wts)
				while (j >= 0 && t.Surname < a[j].Surname) {
					vec[j + StepArr[k - 1]] = vec[j];
					j -= StepArr[k - 1];
					
				}
			else
				while (j >= 0 && t.Number > a[j].Number) {
					vec[j + StepArr[k - 1]] = vec[j];
					j -= StepArr[k - 1];
				}
		}
	}
}

int IndexSortMenu() {
	srand(time(NULL));
	const int TSize = 4;
	string someName[4]{ "Feodor", "Peotr", "Bogdan", "Viktor" };
	string someMiddleName[4]{ "Petrovich","Sidorovich","Artyomovich","Grigorievich" };
	string someSurname[4]{ "Petrov","Chernikov","Vetrov","Ivanov" };
	vector<int> SurnameSort;
	vector<int> NumberSort;

	Teleman* arr = new Teleman[TSize];
	for (int i = 0; i < TSize; ++i) {
		i[arr].Name = someName[rand() % 4];
		i[arr].MiddleName = someMiddleName[rand() % 4];
		i[arr].Surname = someSurname[rand() % 4];
		i[arr].Number = 2670000 + rand() % 9001;
	}

	cout << "Unsorted one:" << endl << "=====================" << endl;
	for (int i = 0; i < TSize; ++i) {
		arr[i].TeleLine();
	}
	cout << "=====================" << endl << endl;

	Teleman* tsbs = new Teleman[TSize];
	for (int i = 0; i < TSize; ++i) {
		tsbs[i] = arr[i];
	}
	ShellSort(tsbs, TSize, 1, SurnameSort);
	cout << "Sorted by surnames:" << endl << "=====================" << endl;
	for (int i = 0; i < SurnameSort.size(); ++i)
	{
		cout << SurnameSort[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < TSize; ++i)
	{
		tsbs[SurnameSort[i]].TeleLine();
	}
	/*for (int i = 0; i < TSize; ++i) {
		tsbs[i].TeleLine();
	}*/
	cout << "=====================" << endl << endl;

	Teleman* tsbn = new Teleman[TSize];
	for (int i = 0; i < TSize; ++i) {
		tsbn[i] = arr[i];
	}
	/*ShellSort(tsbn, TSize, 0, NumberSort);
	cout << "Sorted by number:" << endl << "=====================" << endl;
	for (int i = 0; i < TSize; ++i) {
		tsbn[i].TeleLine();
	}
	cout << "=====================" << endl << endl;*/

	delete[] arr;
	delete[] tsbs;

	return 0;
}