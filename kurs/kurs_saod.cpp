#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <string.h>
using namespace std;
/*
void swap(Man *&a, Man *&b) {
	Man *c;
	c=*a;
	*a=*b;
	*b=c;
}*/

void FillRand(int A[], int n) {
	for(int i=0; i<n; i++)
		A[i]=rand()% 20;
}

void PrintMas(int A[], int n) {
	for(int i=0; i<n; i++)
	    cout<<A[i]<<" ";
	cout<<endl;
}

// сортировка по дате рождения, ключ поиска - год рождения
int N = 4000;

struct Man {
	char name[30];
	short int num;
	char position[22];
	char date[10];
};
/*
void QuickSort(int A[], int *B, int n, int L, int R) {
	int i=L, j=R, x = (L+R)/2;
	while(i<=j) {
		while(i<x) {
			i++;
		}
		while(j>x) {
			j--;
		}
		if(i<=j) {
			swap(A[B[i]], A[B[j]]);
			i++;
			j--;		
		}
	}
	if(L<j)
		QuickSort(A,B,n,L,j);
	if(i<R)
		QuickSort(A,B,n,i,R);
}*/

void HeapSort(Man **Com, int n); 

int main() {
	//setlocale(LC_ALL, "rus");
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

void HeapSort(Man **Com, int n) {
	int i, j;
	Man x, temp;
	int L = n/2;
	while(L > 0) {
		i = L;
		for( ; ; ) {
			x = *Com[i-1];
			j = 2*i;
			if(j > n)
				break;
			if((j < n-1) && (strcmp(Com[j]->date, Com[j-1]->date) <= 0))
				j++;
			if(strcmp(x.date, Com[j-1]->date) < 0)
				break;
			if(strcmp(x.date, Com[j-1]->date) == 0)
			    if(strcmp(x.name, Com[j-1]->name) <= 0)
			        break;
			//swap(A[i-1], A[j-1]);
			temp = *Com[i-1];
            *Com[i-1] = *Com[j-1];
            *Com[j-1] = temp;			
			i = j;
		}
		L--;
	}
	
	int R = n;
	while(R > 0) {
		//swap(A[0], A[R-1]);
		temp = *Com[0];
		*Com[0] = *Com[R-1];
		*Com[R-1] = temp;
		R--;
		i = 1;
		for( ; ; ) {
			x = *Com[i-1];
			j = 2*i;
			if(j > R)
				break;
			if((j < R) && (strcmp(Com[j]->date, Com[j-1]->date) <= 0))
				j++;
			if(strcmp(x.date, Com[j-1]->date) < 0)
				break;
			if(strcmp(x.date, Com[j-1]->date) == 0)
			    if(strcmp(x.name, Com[j-1]->name) <= 0)
			        break;
			//swap(A[i-1], A[j-1]);
			temp = *Com[i-1];
            *Com[i-1] = *Com[j-1];
            *Com[j-1] = temp;
			i = j;
		}
	}
}
