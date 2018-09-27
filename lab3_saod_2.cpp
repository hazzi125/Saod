#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <clocale>
#include <stdio.h>
using namespace std;

int k = 0, s = 0;

struct vertex {
	int data;
	vertex *right;
	vertex *left;
};

vertex *root;

int max(int x1, int x2) {
	if(x1 < x2)
	    return x2;
	else if(x1 > x2)
	    return x1;
	else
	    return x1;
}

void Obhod(vertex *p) {
	if(p != NULL) {
		Obhod(p->left);
		cout << p->data << " ";
		Obhod(p->right);
	}
}

void Size(vertex *p) {
	if(p != NULL) {
		k++;
		Size(p->left);
		Size(p->right);
	}
}

int Height(vertex *p) {
	int hl = 0, hr = 0;
	if(p != NULL) {
		if(p->left)
		    hl = Height(p->left);
		if(p->right)
		    hr = Height(p->right);
	}
	return (max(hl, hr) + 1);
}

void Sum(vertex *p) {
	if(p != NULL) {
		s += p->data;
		Sum(p->left);
		Sum(p->right);
	}
}

int SumHeight(vertex *p, int L) {
    int sd;
    if(p == NULL) 
        sd = 0;
    else
        sd = L + SumHeight(p->left, L+1) + SumHeight(p->right, L+1);
    return sd;	
}

void FillInc(int A[], int n) {
	for(int i = 1; i <= n; i++)
		A[i] = i;
}

void FillRand(int A[], int n) {
	for(int i = 1; i <= n; i++)
		A[i] = rand() % n;
}

void PrintMas(int A[], int n) {
	for(int i = 1; i <= n; i++)
	    cout << A[i] << " ";
	cout << endl;
}

vertex *ISDP(int L, int R, int A[]) {
	int m;
	vertex *p;
	if(L <= R) {
		m = (L + R) / 2;
		p = new vertex;
		p->data = A[m];
		p->left = ISDP(L, m-1, A);
		p->right = ISDP(m+1, R, A);
		return p;
	}
	else
	    return NULL;
}

void SDP_add(int d, vertex *root) {
	vertex **p;
	p = &root;
	while(*p != NULL) {
		if(d < (*p)->data)
		    p = &((*p)->left);
		else if(d > (*p)->data)
		    p = &((*p)->right);
		else
		    break;
	}
	if(*p == NULL) {
		*p = new vertex;
		(*p)->data = d;
		(*p)->left = (*p)->right = NULL;
	}
}

void SDP_recurs(int d, vertex *&p) {
	if(p == NULL) {
		p = new vertex;
		p->data = d;
		p->left = p->right = NULL;
	}
	else if(d < p->data)
	    SDP_recurs(d, p->left);
	else if(d > p->data)
	    SDP_recurs(d, p->right);
}

int main() {
	srand(time(NULL));
	int n;
	cin >> n;
	int A[n];
	FillRand(A, n);
	PrintMas(A, n);
	cout << "\n";
	root = ISDP(1, n, A);
	/*
	Size(root);
	Sum(root);
	cout << " n = 100 | Size | Sum | Height | Sr. height\n";
	cout << "---------|------|-----|--------|------------\n";
	printf("   ISDP  |%4d  |%4d |%5d   | %5d\n", k, s, Height(root), SumHeight(root, 1)/k);*/
	
    for(int i = 1; i <= n; i++) 
    	SDP_add(A[i], root);
	Obhod(root);
	
	cout << "\n";
	system("pause");
	return 0;
}

