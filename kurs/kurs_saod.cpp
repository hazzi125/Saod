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
	int N = 4000;
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
	
	code *symb = new code[n_symb];
	int cx = 0;
	Company->Coding_Fano(cx, N, symb, Company);
	
	system("pause");
	return 0;
}
