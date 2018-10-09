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
	FILE *f;
	bool flag;
	f = fopen("testBase2.dat", "rb");
	fread(Company, sizeof(*Company), N, f);
	
	
	Man *B[N];
	for(int i = 0; i < N; i++)
	    B[i] = &Company[i];
    HeapSort(B, N);
    
    
	cout << "   |   Name/Surname/Patronymic    | Num |       Position        |    Date\n";
	cout << "---|------------------------------|-----|-----------------------|-------------\n";
	
	int k = 0;
	while(k < N) {
		for(int i = 0; i < 20; i++) {
			printf("%2d.| ", k+1);
			cout << Company[k].name << "| ";
			printf("%3d", Company[k].num);
			cout << " | " << Company[k].position << " |   " << Company[k].date << "\n";
			k++;
	    }
	    cout << "\nDo you want to print 20 more records? 1/0 ";
		cin >> flag;
		cout << "\n";
		if(flag == 0) {
			break;
		}
	}

    fclose(f);
	cout << "\n";
	system("pause");
	return 0;
}
