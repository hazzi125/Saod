#include "func.cpp"
#include "head.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <string.h>

using namespace std;
// ���������� �� ���� ��������, ���� ������ - ��� ��������

int main() {
	//setlocale(LC_ALL, "");
	int N = 4000;
	Man *Company = new Man[N];
	Company->Init(Company, N);
	
	Man *B[N];
	for(int i = 0; i < N; i++)
	    B[i] = &Company[i];
	    
    Company->HeapSort(B, N);
    Company->PrintBase(Company, N);

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
