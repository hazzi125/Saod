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
