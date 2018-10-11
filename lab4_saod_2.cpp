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

void SDP_add(int d, vertex *&root) {
	vertex **p;
	p = &root;
	while(*p != NULL) {
		if(d < (*p)->data)
		    p = &((*p)->left);
		else if(d >= (*p)->data)
		    p = &((*p)->right);
		else
		    return;
	}
	if(*p == NULL) {
		*p = new vertex;
		(*p)->data = d;
		(*p)->left = NULL;
		(*p)->right = NULL;
	}
}

void SDP_recurs(int d, vertex *&p) {
	if(p == NULL) {
		p = new vertex;
		p->data = d;
		p->left = NULL;
		p->right = NULL;
	}
	else if(d < p->data)
	    SDP_recurs(d, p->left);
	else if(d > p->data)
	    SDP_recurs(d, p->right);
    else
        return;
}

void DelTree(int d, vertex *&root) {
    vertex **p = &root, *q, *r, *s;
    while(*p) {
        if((*p)->data < d)
		    p = &((*p)->right);
		else if((*p)->data > d)
		    p = &((*p)->left);
		else
		    break;
    }
    if(*p) {
        q = *p;
        if(q->left == NULL)
            *p = q->right;
        else if(q->right == NULL)
            *p = q->left;
        else {
            r = q->left;
            s = q;
            if(r->right == NULL) {
                r->right = q->right;
                *p = r;
            }
            else{
                while(r->right) {
                    s = r;
                    r = r->right;
                }
                s->right = r->left;
                r->left = q->left;
                r->right = q->right;
                *p = r;
            }
        }
    }
    delete q;
}

int main() {
	srand(time(NULL));
	int n;
	cin >> n;
	int A[n];
	FillRand(A, n);
	PrintMas(A, n);
	cout << "\n";
    for(int i = 1; i <= n; i++)
    	SDP_recurs(A[i], root);
   	cout << "\nRecurs:\n";
	Obhod(root);
	cout << endl;
	int x;
	
	while(root) {
        cin >> x;
	    DelTree(x, root);
	    Obhod(root);
	    cout << "\n";
    }
	
	//cout << "\n";
	system("pause");
	return 0;
}

