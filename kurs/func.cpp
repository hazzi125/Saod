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

void Man::PrintRec(Man *a, int i) {
	printf("%2d.| ", i+1);
	cout << a[i].name << "| ";
	printf("%3d", a[i].num);
	cout << " | " << a[i].position << " |   " << a[i].date << "\n";
}

int Man::Compare(Man *a, Man *b) {
	int temp;
 
	if(a->date[6] > b->date[6])
	    temp = 1;
	else if(a->date[6] < b->date[6])
	    temp = -1;
	else {
		if(a->date[7] > b->date[7])
	        temp = 1;
	    else if(a->date[7] < b->date[7])
	        temp = -1;
	    else {
	    	if(a->date[3] > b->date[3])
	            temp = 1;
	        else if(a->date[3] < b->date[3])
	            temp = -1;
	        else {
	        	if(a->date[4] > b->date[4])
	                temp = 1;
	            else if(a->date[4] < b->date[4])
	                temp = -1;
	            else {
	            	if(a->date[0] > b->date[0])
	                    temp = 1;
	                else if(a->date[0] < b->date[0])
	                    temp = -1;
	                else {
	                	if(a->date[1] > b->date[1])
	            			temp = 1;
	        		    else if(a->date[1] < b->date[1])
	            			temp = -1;
	        			else
	        			    temp = 0;
					}
				}
			}
		}
	}
    return temp;
}

int Man::BinSearch(Man *Com, int n, char str[2]) {
	int L = 1, R = n, m;
	bool find;
	while(L < R) {
		m = (L + R) / 2;
		if(Com[m-1].date[6] < str[0])
		    L = m + 1;
		else if(Com[m-1].date[6] == str[0]) {
			if(Com[m-1].date[7] < str[1])
		        L = m + 1;
		    else
		        R = m;
		}
		else
		    R = m;   
	}
    if((Com[R-1].date[6] == str[0]) && (Com[R-1].date[7] == str[1]))
	    return R-1;
	else {
	    cout << "Not found\n";
	    return -1;
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
