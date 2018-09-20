#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <clocale>
using namespace std;

// сортировка по дате родения, ключ поиска - год рождения
int N = 5;


struct Man {
	char name[30];
	short int num;
	char position[22];
	char date[10];
} Company[5];

int main() {
	//setlocale(LC_ALL, "rus");
	FILE *f;
	f = fopen("testBase2.dat", "r");
	fread(&Company, sizeof(Company), N, f);
	cout << "   |   Name/Surname/Patronymic    | Num |       Position        | Tel. number\n";
	cout << "---|------------------------------|-----|-----------------------|-------------\n";
	for(int i = 1; i <= N; i++) {
		printf("%2d.| ", i);
		cout << Company[i].name << "| ";
		printf("%3d", Company[i].num);
		cout << " | " << Company[i].position << " |   " << Company[i].date << "\n";
	}
	cout << "\n";
	fclose(f);
	system("pause");
	return 0;
}
