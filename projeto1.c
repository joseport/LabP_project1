#include <stdio.h>
#include <stdlib.h>
#include "bigNumber.h"
#include "fibonacci.h"

#define MAX 99999

int main(){
	long num;
	printf("A continuação faça favor de introduzir um Long para o calculo do seu fibonacci\n");
	scanf("%ld", &num);

	printf("Este é o fibonacci recursivo que reseve um Long e retorna um Long\n \t%ld\n", fibRecursivoLong (num));
	printf("Este é o fibonacci iterativo sem array que receve um Long e retorna um Long\n \t%ld\n", fibForLong1 (num));
	printf("Este é o fibonacci iterativo com array que receve um Long e retorna um Long\n \t%ld\n",fibForLong2 (num));
	printf("Este é o fibonacci iterativo com array que receve um Long e retorna um BigNumber\n \t" );
	printlist(reverseList(bNfibFor1 (num)));
	printf("\n");
	printf("Este é o fibonacci iterativo sem array que receve um Long e retorna um BigNumber\n \t" );
	printlist(reverseList(bNfibFor2(num)));
	printf("\n");

	char s[MAX];
	printf("A continuação faça favor de introduzir um BigNumber para o calculo do seu fibonacci\n Este BigNumber deve ser introduzido como qualquer outro inteiro\n");
	scanf("%s", s);
	bigNumber p=leitura (s);
	printf("Este é o fibonacci recursivo que receve um BigNumber e retorna um BigNumber\n \t" );
	printlist(reverseList(fibRecursivoBn (p)));
	printf("\n");
	printf("Este é o fibonacci iterativo sem array que receve um BigNumber e retorna um BigNumber\n \t" );
	printlist(reverseList(bNfibFor2_2(p)));
	printf("\n");



	return 0;
}
