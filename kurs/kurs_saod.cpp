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
	int N = 4000;
	tree *root = NULL;
	Man *Company = new Man[N];
	Company->Init(Company, N);
    Company->HeapSort(Company, N, 0);
    //Company->PrintBase(Company, N);
    
    Company->CreateTree(Company, 0, N-1, root);
    Company->Obhod(root);

    bool flag = 1;
    while(flag) {
		cout << "\nWhat year interested you? ";
		char str[2];
		cin >> str;
		list *head, *tail;
		cout << "\n";
		Company->BinSearch(Company, head, tail, N, str);
		cout << "Do you want to find another person? 1/0 ";
		cin >> flag;
	}
	cout << "\n";
	system("pause");
	return 0;
}
