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
	short int bal;
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
		A[i] = rand() % (2*n);
}

void PrintMas(int A[], int n) {
	for(int i = 1; i <= n; i++)
	    cout << A[i] << " ";
	cout << endl;
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

void LL(vertex *&p);
void LR(vertex *&p);
void RL(vertex *&p);
void RR(vertex *&p);

void AVL(int d, vertex *&p) {
    bool grow;
    if(p == NULL) {
        p = new vertex;
        p->data = d;
        p->left = p->right = NULL;
        p->bal = 0;
        grow = 1;
    }
    else {
        if(p->data > d) {
            AVL(d, p->left);
            if(grow) {    // выросла левая вевть
                if(p->bal > 0) {
                    p->bal = 0;
                    grow = 0;
                }
                else if(p->bal == 0) 
                    p->bal = -1;
                else {
                    if(p->left->bal < 0)
                        LL(p);
                    else
                        LR(p);
                    grow = 0;
                }
            }
        }
        
        else if(p->data < d) {
            AVL(d, p->right);
            if(grow) {    // выросла правая вевть
                if(p->bal < 0) {
                    p->bal = 0;
                    grow = 0;
                }
                else if(p->bal == 0) 
                    p->bal = 1;
                else {
                    if(p->right->bal > 0)
                        RL(p);
                    else
                        RR(p);
                    grow = 0;
                }
            }
        }
    }
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
    	AVL(A[i], root);
   	cout << "\nRecurs:\n";
	Obhod(root);
	cout << endl;
	system("pause");
	return 0;
}

void LL(vertex *&p) {
    vertex *q = p->left;
    q->bal = 0;
    p->bal = 0;
    p->left = q->right;
    q->right = p;
    p = q;
}

void LR(vertex *&p) {
    vertex *q = p->left, *r = p->right;
    if(r->bal < 0)
        p->bal = 1;
    else
        p->bal = 0;
        
    if(r->bal > 0)
        q->bal = -1;
    else
        q->bal = 0;
        
    r->bal = 0;
    p->left = r->right;
    q->right = r->left;
    r->left = q;
    r->right = p;
    p = r;
}

void RR(vertex *&p) {
    vertex *q = p->right;
    q->bal = 0;
    p->bal = 0;
    p->right = q->left;
    q->left = p;
    p = q;
}

void RL(vertex *&p) {
    vertex *q = p->right, *r = p->left;
    if(r->bal > 0)
        p->bal = -1;
    else
        p->bal = 0;
        
    if(r->bal < 0)
        q->bal = 1;
    else
        q->bal = 0;
        
    r->bal = 0;
    p->right = r->left;
    q->left = r->right;
    r->left = p;
    r->right = q;
    p = r;
}











