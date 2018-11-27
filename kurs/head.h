#ifndef HEAD_H_
#define HEAD_H_
#include <iostream>
#include <cstdio>

struct list {
    char name[30];
	short int num;
	char position[22];
	char date[10];
	short int number;
	list *next, *prew;
};

struct tree {
    char name[30];
	short int num;
	char position[22];
	char date[10];
	short int number;
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
    int Compare(Man *a, Man *b);
    void HeapSort(Man *&Com, int n);
    void PrintList(list *&head);
    void BinSearch(Man *Com, list *&head, list *&tail, int n, char str[2]);
    //void CreateTree(Man *&Com, int L, int R, tree *&p);
    //void SDP(Man *&Com, tree *&p, int i);
    void CreateTree(list *&p_head, list *&p_tail, tree *&pt);
    void SDP(list *&pl, tree *&pt);
    void Obhod(tree *p);
};

void FillRand(int A[], int n);
void PrintMas(int A[], int n);
void swap(Man *&a, Man *&b);

#endif
