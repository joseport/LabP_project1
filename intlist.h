#ifndef L_H
#define L_H

typedef struct _list{
	int value;
	struct _list *next;
}*intlist;

intlist newlist(int h, intlist rest);
int head(intlist l);
intlist tail(intlist l);
intlist append (intlist primeira, intlist segunda);
int length (intlist l,int cont);
void printlist(intlist l);
int member(intlist l, int x);



#endif