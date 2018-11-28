#include "func.cpp"
#include "head.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <string.h>

using namespace std;
// сортировка по дате рождения, ключ поиска - год рождения

int main() {
	int N = 2000;
	Man *Company = new Man[N];
	Company->Init(Company, N);
    Company->HeapSort(Company, N);
    Company->PrintBase(Company, N);

    int flag = 1;
    while(flag == 1) {
		cout << "\nWhat year interested you? ";
		char str[2];
		cin >> str;
		list *head, *tail;
		cout << "\n";
		Company->BinSearch(Company, head, tail, N, str);
		cout << "\nDo you want to find another person? 1/0 ";
		cin >> flag;
	}
	cout << "\nBuy\n\n";
	system("pause");
	return 0;
}
