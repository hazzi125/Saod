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
};

void FillRand(int A[], int n);

void PrintMas(int A[], int n);

void swap(Man *&a, Man *&b);

void HeapSort(Man **Com, int n);

#endif
