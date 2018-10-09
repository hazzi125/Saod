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
	//setlocale(LC_ALL, "rus");
	int N = 4000;
	Man *Company = new Man[N];
	Company->Init(Company, N);
	
	Man *B[N];
	for(int i = 0; i < N; i++)
	    B[i] = &Company[i];
	    
    Company->HeapSort(B, N);
    Company->PrintBase(Company, N);

	cout << "\n";
	system("pause");
	return 0;
}
