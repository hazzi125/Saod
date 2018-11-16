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
	int flag;
	cout << "\nDo you want to print 20 more records? 1/0 ";
	cin >> flag;
	cout << "\n";
    cout << "     |   Name/Surname/Patronymic    | Num |       Position        |    Date\n";
	cout << "-----|------------------------------|-----|-----------------------|-------------";
	int k = 0;
	do {
		if(flag == 0)
			break;
		else if (flag == 1) {
			for(int i = 0; i < 20; i++) {
				printf("%4d.| ", k+1);
				cout << a[k].name << "| ";
				printf("%3d", a[k].num);
				cout << " | " << a[k].position << " |   " << a[k].date << "\n";
				k++;
		    }
		}
		else {
			while(k < n) {
				printf("%4d.| ", k+1);
				cout << a[k].name << "| ";
				printf("%3d", a[k].num);
				cout << " | " << a[k].position << " |   " << a[k].date << "\n";
				k++;
		    }
		    break;
		}
		cout << "\nDo you want to print 20 more records? 1/0 ";
		cin >> flag;
		cout << "\n";
	} while(k < n);
}

void Man::PrintRec(Man *a, int i) {
	printf("%4d.| ", i+1);
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

void Man::PrintList(list *&head) {
	list *p;
	for(p = head; p; p = p->next) {
		printf("%4d.| ", p->number);
		cout << p->name << "| ";
		printf("%3d", p->num);
		cout << " | " << p->position << " |   " << p->date << "\n";
	}
	cout << endl;
}

void Man::BinSearch(Man *Com, list *&head, list *&tail, int n, char str[2]) {
	list *p;
	head = tail = NULL;
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
    if((Com[R-1].date[6] == str[0]) && (Com[R-1].date[7] == str[1])) {
	    while((Com[R-1].date[6] == str[0]) && (Com[R-1].date[7] == str[1])) {
	    	p = new list;
	    	
	    	strcpy(p->date, Com[R-1].date);
	    	p->num = Com[R-1].num;
	    	strcpy(p->position, Com[R-1].position);
	    	strcpy(p->name, Com[R-1].name);
	    	p->next = NULL;
	    	p->number = R;
	    	
			if(head != NULL)
			    tail->next = p;
			else
			    head = p;
			tail = p;
	    	R++;
		}
		PrintList(head);
	}
	else {
	    cout << "Not found\n\n";
	}    
}

void Man::HeapSort(Man *&Com, int n) {
	int i, j;
	Man *x;
	int L = n/2;
	while(L > 0) {
		i = L;
		for( ; ; ) {
			x = &Com[i-1];
			j = 2*i;
			if(j > n)
				break;
			if((j < n-1) && (Compare(&Com[j], &Com[j-1]) >= 0))
				j++;
			if(Compare(x, &Com[j-1]) >= 0)
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
			x = &Com[i-1];
			j = 2*i;
			if(j > R)
				break;
			if((j < R) && (Compare(&Com[j], &Com[j-1]) >= 0))
				j++;
			if(Compare(x, &Com[j-1]) > 0)
				break;
			        
			swap(Com[i-1], Com[j-1]);
			i = j;
		}
	}
}
