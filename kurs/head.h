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

struct code {
	char c;
	float p;
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
    int Compare(char *str1, char *str2);
    void HeapSort(Man *&Com, int n);
    void PrintList(list *&head);
    void BinSearch(Man *Com, list *&head, list *&tail, int n, char str[2]);
    void CreateTree(list *&p_head, list *&p_tail, tree *&pt);
    void SDP(list *&pl, tree *&pt);
    void Obhod(tree *pt);
    void TreeSearch(char *str, tree *&pt);
    void Calculate_Probs(int n, int n_symb, code *&symb, Man *Com);
};

void swap(Man *&a, Man *&b);
void InsertSort(code *a, int n);

#endif
