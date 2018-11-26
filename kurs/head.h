#ifndef HEAD_H_
#define HEAD_H_
#include <iostream>
#include <cstdio>

struct list {
    char name[30];
	short int num;
	char position[22];
	char date[10];
	list *next;
	int number;
};

struct tree {
    char name[30];
	short int num;
	char position[22];
	char date[10];
	tree *left, *right;
};

class Man {
private:
	char name[30];
	short int num;
	char position[22];
	char date[10];

public:
    void Init(Man *a, int n);
    void PrintBase(Man *a, int n);
    void PrintRec(Man *a, int i);
    int Compare(Man *a, Man *b, bool field);
    void HeapSort(Man *&Com, int n, bool field);
    void PrintList(list *&head);
    void BinSearch(Man *Com, list *&head, list *&tail, int n, char str[2]);
    void CreateTree(Man *&Com, int L, int R, tree *&p);
    void SDP(Man *&Com, tree *&p, int i);
    void Obhod(tree *p);
};

void FillRand(int A[], int n);
void PrintMas(int A[], int n);
void swap(Man *&a, Man *&b);

#endif
