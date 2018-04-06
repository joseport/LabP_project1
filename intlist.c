#include "intlist.h"
#include <stdlib.h>
#include <stdio.h>

intlist reverseList(intlist lista){
	intlist retorno=NULL;
	while (lista!=NULL) {
		retorno=append(newlist(head(lista),NULL),retorno);
		lista=tail(lista);
	}
	return retorno;
}

intlist newlist(int h, intlist rest){
	intlist l = malloc(sizeof(intlist));
	if (l==NULL){
		printf("No memory available\n");
		abort();
	}
	l->value = h;
	l->next = rest;
	return l;
}

int head(intlist l){
	if (l==NULL){
		printf("head Lista vazia\n");
		exit(-1);
	}
	return l->value;
}

intlist tail(intlist l){
	if (l==NULL){
		printf("tail Lista vazia\n");
		exit(-1);
	}
	return l->next;
}

intlist append (intlist primeira, intlist segunda){
	if (primeira!=NULL){
		return newlist(head(primeira),append(tail(primeira),segunda));
	}
	return segunda;
}


int length (intlist l,int cont){
	if (l!=NULL)
		cont=length(tail(l),cont+1);
	return cont;
}

void printlist(intlist l){
	printf("%d ", head(l));
	if (tail(l)!=NULL)
		printlist(tail(l));
}

int member(intlist l, int x){
	intlist s=l;
	while(s!=NULL){
		if (head(s)==x) return 1;
		s=tail(s);
	}
	return -1;
}