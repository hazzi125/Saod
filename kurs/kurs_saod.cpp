#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <string.h>
using namespace std;

// сортировка по дате родения, ключ поиска - год рождения
int N = 4000;

struct Man {
	char name[30];
	short int num;
	char position[22];
	char date[10];
};

int main() {
	//setlocale(LC_ALL, "rus");
	Man *Company = new Man[N];
	FILE *f;
	bool flag;
	f = fopen("testBase2.dat", "rb");
	fread(Company, sizeof(*Company), N, f);

	cout << "   |   Name/Surname/Patronymic    | Num |       Position        | Tel. number\n";
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

	cout << "\n";
	fclose(f);
	system("pause");
	return 0;
}
