#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <clocale>
using namespace std;

// ���������� �� ���� �������, ���� ������ - ��� ��������
const int N = 20;


struct Man {
	char name[30];
	short int num;
	char position[22];
	char date[10];
} Company[N];

int main() {
	//setlocale(LC_ALL, "rus");
	FILE *f;
	f = fopen("testBase2.dat", "r");
	fread(&Company, sizeof(Company), 1, f);
	cout << "   |   Name/Surname/Patronymic    | Num |       Position        | Tel. number\n";
	cout << "---|------------------------------|-----|-----------------------|-------------\n";
	for(int i = 0; i < N; i++) {
		printf("%2d.| ", i+1);
		cout << Company[i].name << "| ";
		printf("%3d", Company[i].num);
		cout << " | " << Company[i].position << " |   " << Company[i].date << "\n";
	}
	cout << "\n";
	fclose(f);
	system("pause");
	return 0;
}
