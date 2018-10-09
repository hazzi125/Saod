#include "head.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <string.h>

using namespace std;

void FillRand(int A[], int n) {
	for(int i=0; i<n; i++)
		A[i]=rand()% 20;
}

void PrintMas(int A[], int n) {
	for(int i=0; i<n; i++)
	    cout<<A[i]<<" ";
	cout<<endl;
}

void swap(Man *&a, Man *&b) {
	Man temp;
	temp = *a;
    *a = *b;
	*b = temp;
}

void Man::Init(Man *a, int n) {
    FILE *f;
    f = fopen("testBase2.dat", "rb");
    fread(a, sizeof(*a), n, f);
    fclose(f);
}

void Man::PrintBase(Man *a, int n) {
    cout << "   |   Name/Surname/Patronymic    | Num |       Position        |    Date\n";
	cout << "---|------------------------------|-----|-----------------------|-------------\n";
	bool flag;
	int k = 0;
	while(k < n) {
		for(int i = 0; i < 20; i++) {
			printf("%2d.| ", k+1);
			cout << a[k].name << "| ";
			printf("%3d", a[k].num);
			cout << " | " << a[k].position << " |   " << a[k].date << "\n";
			k++;
	    }
	    cout << "\nDo you want to print 20 more records? 1/0 ";
		cin >> flag;
		cout << "\n";
		if(flag == 0) {
			break;
		}
	}
}

void Man::HeapSort(Man **Com, int n) {
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
			    //if(strcmp(x.name, Com[j-1]->name) >= 0)
			        break;
			        
			swap(Com[i-1], Com[j-1]);		
			i = j;
		}
		L--;
	}
	
	int R = n;
	while(R > 0) {
		swap(Com[0], Com[R-1]);
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
			    //if(strcmp(x.name, Com[j-1]->name) >= 0)
			        break;
			        
			swap(Com[i-1], Com[j-1]);
			i = j;
		}
	}
}
