#ifndef HEAD_H_
#define HEAD_H_

struct Man {
	char name[30];
	short int num;
	char position[22];
	char date[10];
};


void FillRand(int A[], int n);
void PrintMas(int A[], int n);
void swap(Man *&a, Man *&b);
void HeapSort(Man **Com, int n);

#endif
