#include <stdio.h>
#include <stdlib.h>
#include "bigNumber.h"

long fibonacci(long num);
bigNumber fibonacciFor (long num);




int main(){
	long num;
	scanf("%ld", &num);
	fibonacciFor(num);
	printlist(fibonacciFor(num));
	return 0;
}

bigNumber fibonacciFor (long num){
	bigNumber a[num];
	if( num<=1) return newBigNumber(num,NULL);
	else{
		a[0]=newBigNumber(0,NULL);
		a[1]=newBigNumber(1,NULL);
		for (int i=2; i<=num; i++){
			bigNumber n=somaAritmetica(a[i-2],a[i-1]);
			a[i]=n;
		}
		return a[num];
	}
}

long fibonacci(long num){
	if(num == 0 || num==1)
		return num;
	else
		return fibonacci(num-1) + fibonacci(num-2);
}