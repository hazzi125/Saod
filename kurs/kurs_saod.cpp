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
	//setlocale(LC_ALL, "rus");
	int N = 100;
	Man *Company = new Man[N];
	Company->Init(Company, N);
	
	Man *B[N];
	for(int i = 0; i < N; i++)
	    B[i] = &Company[i];
	    
    Company->HeapSort(B, N);
    Company->PrintBase(Company, N);

	cout << "\n";
	char str[2];
	cin >> str;
	int i = Company->BinSearch(Company, N, str);
	if(i >= -1)
	    Company->PrintRec(Company, i);
	cout << "\n";
	system("pause");
	return 0;
}
