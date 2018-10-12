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

int Man::Compare(Man *a, Man *b) {
	char ch1[3], ch2[3];
	int temp;;
	ch1[0] = a->date[6];
	ch1[1] = a->date[7];
	
	ch2[0] = b->date[6];
	ch2[1] = b->date[7];
 
	temp = strcmp(ch1, ch2);
	
	if(temp != 0)
	    return temp;
	
	else {
		ch1[0] = a->date[3];
	    ch1[1] = a->date[4];
	
	    ch2[0] = b->date[3];
	    ch2[1] = b->date[4];
	    
	    temp = strcmp(ch1, ch2);
	    if(temp != 0)
	        return temp;
	    
	    else {
	    	ch1[0] = a->date[0];
	        ch1[1] = a->date[1];
	
	        ch2[0] = b->date[0];
	        ch2[1] = b->date[1];
	         
	        temp = strcmp(ch1, ch2);
	        return temp;
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
			if((j < n-1) && (Compare(Com[j], Com[j-1]) >= 0))
				j++;
			if(Compare(&x, Com[j-1]) >= 0)
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
			if((j < R) && (Compare(Com[j], Com[j-1]) >= 0))
				j++;
			if(Compare(&x, Com[j-1]) > 0)
				break;
			        
			swap(Com[i-1], Com[j-1]);
			i = j;
		}
	}
}
