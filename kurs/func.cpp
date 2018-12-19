#include "head.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <string.h>
#include <cmath>

using namespace std;

void swap(Man *&a, Man *&b) {
	Man temp;
	temp = *a;
    *a = *b;
	*b = temp;
}

void InsertSort(code *a, int n) {
    int i, j, k = 0;
    code t;
    for (i = 1; i < n; i++) {
        t = a[i];
        j = i - 1;
        while (j >= 0 && a[j].p < t.p) {
            a[j + 1] = a[j];
            j = j -1;
        }
        a[j+1] = t;
    }
}

void Man::Init(Man *a, int n) {
    FILE *f;
    f = fopen("testBase2.dat", "rb");
    fread(a, sizeof(*a), n, f);
    fclose(f);
}

void Man::PrintBase(Man *a, int n) {
	int flag = 1;
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

bool tree_find;

void Man::BinSearch(Man *Com, list *&head, list *&tail, int n, char str[2]) {
	list *p;
	head = tail = NULL;
	int L = 1, R = n, m;
	bool find;
	int flag_tree;
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
	    	
			if(head) {
				p->prew = tail;
			    tail->next = p;
			}
			else {
				p->prew = NULL;
			    head = p;
			}
			tail = p;
	    	R++;
		}
		PrintList(head);
		
		cout << "Do you want to create tree? 1/0 ";
		cin >> flag_tree;
		cout << "\n";
		if(flag_tree == 1) {
			tree *root = NULL;
			Com->CreateTree(head, tail, root);
			Com->Obhod(root);
			cout << "\nWhat name interested you? ";
			char str[22];
			cin >> str;
			cout << "\n";
			tree_find = 0;
			Com->TreeSearch(str, root);
		}
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

int wes, summa;

void Man::SDP(list *&pl, tree *&pt) {
	if(pt == NULL) {
		pt = new tree;
		strcpy(pt->date, pl->date);
	    pt->num = pl->num;
	    strcpy(pt->position, pl->position);
	    strcpy(pt->name, pl->name);
	    pt->number = pl->number;
		pt->left = pt->right = NULL;
	}
	else if(strcmp(pl->position, pt->position) < 0)
	    SDP(pl, pt->left);
	else if(strcmp(pl->position, pt->position) >= 0)
	    SDP(pl, pt->right);
}

void Man::CreateTree(list *&p_head, list *&p_tail, tree *&pt) {
	wes = summa = 0;
	list *pl;
	if(p_head->number <= p_tail->number) {
		for(pl = p_head; pl != p_tail->next; pl = pl->next) {
			wes += pl->num;
		}
		for(pl = p_head; pl != p_tail; pl = pl->next) {
			if((summa < wes/2) && (summa + pl->num >= wes/2))
			    break;
			summa += pl->num;
		}
		SDP(pl, pt);
		if(pl->prew != NULL)
		    this->CreateTree(p_head, pl->prew, pt);
	    if(pl->next != NULL)
		    this->CreateTree(pl->next, p_tail, pt);
	}
}

void Man::Obhod(tree *pt) {
	if(pt) {
		Obhod(pt->left);
		printf("%4d.| ", pt->number);
		cout << pt->name << "| ";
		printf("%3d", pt->num);
		cout << " | " << pt->position << " |   " << pt->date << "\n";
		Obhod(pt->right);
	}
}

void Man::TreeSearch(char *str, tree *&pt) {
	if(pt) {
		int temp = Compare(str, pt->position);
		if(temp == 0) {
			TreeSearch(str, pt->left);
			tree_find = 1;
	        printf("%4d.| ", pt->number);
			cout << pt->name << "| ";
			printf("%3d", pt->num);
			cout << " | " << pt->position << " |   " << pt->date << "\n";
			TreeSearch(str, pt->right);
	    }
		else if(temp < 0)
		    TreeSearch(str, pt->left);
		else if(temp > 0)
	        TreeSearch(str, pt->right);
	}
	else if(!tree_find){
		cout << "Elem was not find\n";
	}
}

int Man::Compare(char *str1, char *str2) {
	int temp = 0;
	for(int i = 0; str1[i] != '\0'; i++) {
		if(str1[i] == '_')
		    str1[i] = ' ';
		if(str1[i] > str2[i]) {
			temp = 1;
			break;
		}
		else if(str1[i] < str2[i]) {
			temp = -1;
			break;
		}
		else
		    temp = 0;
	}
	return temp;
}

void Man::Coding_Fano(int &cx, int n, code *&symb, Man *Com) {
	for(int i = 0; i < n_symb; i++) {
		symb[i].c = i+32;
	}
	int k = (30 + 3 + 22 + 10) * n;
	char s[4];
    int count;
	cx = 0;
	
    for(int i = 0; i < n_symb; i++) {
    	count = 0;
		for(int j = 0; j < n; j++) {
			for(int l = 0; l < 30; l++) {
				if(Com[j].name[l] == symb[i].c)
			        count++;
			}
			
			itoa(Com[j].num, s, 10);
			for(int l = 0; l < 10; l++) {
				if(s[l] == symb[i].c)
			        count++;
			}
			
			for(int l = 0; l < 22; l++) {
				if(Com[j].position[l] == symb[i].c)
			        count++;
			}
			
			for(int l = 0; l < 10; l++) {
				if(Com[j].date[l] == symb[i].c)
			        count++;
			}
		}
		if(count) {
		    symb[i].p = (float) (count) / k;
		    cx++;
		}
		else
		    symb[i].p = 0;
	}
	
	InsertSort(symb, n_symb);
	cout << "\n";
	
	Fano(0, cx-1, 0, symb);
	
	cout << "Symbol | Probability |  Length  | Code word\n";
	cout << "-------|-------------|----------|------------\n";
	for(int i = 0; i < cx; i++) {
		printf("%4c   |", symb[i].c);
		printf(" %9f   |", symb[i].p);
		printf("%6d    |", Length[i]);
	    for(int j = 0; j <= Length[i]; j++)
	        cout << C[i][j];

	    cout << "\n";
	}
	cout << "\n";
	float med_length = 0;
	float entropy = 0;
	float sum_p = 0;
	for(int i = 0; i < cx; i++) {
		med_length += symb[i].p * Length[i];
		entropy += symb[i].p * log2(symb[i].p);
		sum_p += symb[i].p;
	}
	entropy *= (-1);
	cout << "\n" << cx << "\n";
	cout << "Sum of probabilities = " << sum_p << "\n";
	cout << "Medium length = " << med_length << "\n";
	cout << "Entropy = " << entropy << "\n\n\n";
	
	cout << "Medium L >= Entropy\n";
	cout << "Medium L < Entropy + 1\n\n";
	
	int flag = 1;
	do {
		this->PrintCode(Com, symb, cx);
		cout << "\nDo you want to coding a next record? 1/0 ";
		cin >> flag;
		
	} while(flag);
}

int m = 0;
float sl = 0, sr = 0;

int Med(int L, int R, code *symb) {
	sl = 0;
	for(int i = L; i < R; i++)
	    sl += symb[i].p;
	sr = symb[R].p;
	m = R;
	while(sl >= sr) {
		m--;
		sl -= symb[m].p;
		sr += symb[m].p;
	}
	return m;
}

void Fano(int L, int R, int k, code *symb) {
	if(L < R) {
		k++;
		int m = Med(L, R, symb);
		for(int i = L; i <= R; i++) {
			if(i <= m) {
				C[i][k] = '0';
				Length[i]++;
			}
			else {
				C[i][k] = '1';
				Length[i]++;
			}
		}
		Fano(L, m, k, symb);
		Fano(m+1, R, k, symb);
	}
}

void Man::PrintCode(Man *Com, code *symb, int cx) {
	int x;
	cout << "What record interests you? ";
	cin >> x;
	if((x > 0) && (x <= 4000)) {
		printf("\n%4d.| ", x);
		x--;
		cout << Com[x].name << "| ";
		printf("%3d", Com[x].num);
		cout << " | " << Com[x].position << " |   " << Com[x].date << "\n\n";
		
		cout << "Name: ";
		for(int i = 0; i < 30; i++) {
			for(int j = 0; j < cx; j++) {
				if(Com[x].name[i] == symb[j].c) {
					for(int k = 0; k <= Length[j]; k++)
					    cout << C[j][k];	    
					cout << " ";
				}
			}
		}
		
		cout << "\n\nNumber: ";
		char s[3];
		itoa(Com[x].num, s, 10);
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < cx; j++) {
				if(s[i] == symb[j].c) {
					for(int k = 0; k <= Length[j]; k++)
					    cout << C[j][k];	    
					cout << " ";
				}
			}
		}
		
		cout << "\n\nPosition: ";
		for(int i = 0; i < 22; i++) {
			for(int j = 0; j < cx; j++) {
				if(Com[x].position[i] == symb[j].c) {
					for(int k = 0; k <= Length[j]; k++)
					    cout << C[j][k];	    
					cout << " ";
				}
			}
		}
		
		cout << "\n\nDate: ";
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < cx; j++) {
				if(Com[x].date[i] == symb[j].c) {
					for(int k = 0; k <= Length[j]; k++)
					    cout << C[j][k];	    
					cout << " ";
				}
			}
		}
		cout << "\n";
	}
	
	else {
		cout << "\nYou entered wrong value. Try again";
	}
}
