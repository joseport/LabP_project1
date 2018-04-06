#include "intlist.h"
#include "bigNumber.h"
#include "fibonacci.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 9999

bigNumber bNfibFor1 (long num){
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

bigNumber bNfibFor2 (long num){
	bigNumber anterior, anteriorDois, retorno;
	if (num<=1) return newBigNumber(num,NULL);
	else{
		anterior = newBigNumber(1,NULL);
		anteriorDois = newBigNumber(0,NULL);
		for (int i = 2; i <=num; i++)
		{
			retorno= somaAritmetica(anterior,anteriorDois);
			anteriorDois=anterior;
			anterior=retorno;
		}
	}
	return retorno;
}

bigNumber fibRecursivoBn (bigNumber num){
	if(comparation(num,newBigNumber(0,NULL))==0 || comparation(num,newBigNumber(1,NULL))==0)
		return num;
	else
		return somaAritmetica(fibRecursivoBn(subtracaoAritmetica(num,newBigNumber(1,NULL))), fibRecursivoBn(subtracaoAritmetica(num,newBigNumber(2,NULL))));
}

bigNumber bNfibFor2_2 (bigNumber num){
	bigNumber anterior, anteriorDois, retorno;
	if (comparation(num,newBigNumber(1,NULL))<=0) return num;
	else{
		anterior = newBigNumber(1,NULL);
		anteriorDois = newBigNumber(0,NULL);
		for (bigNumber i=newBigNumber(2,NULL); comparation(i,num)<=0; somaAritmetica(i,newBigNumber(1,NULL)))
		{
			retorno= somaAritmetica(anterior,anteriorDois);
			anteriorDois=anterior;
			anterior=retorno;
		}
	}
	return retorno;
}



long fibForLong2 (long num){
	long a[num];
	if( num<=1) return num;
	else{
		a[0]=0;
		a[1]=1;
		for (int i=2; i<=num; i++){
			long n=a[i-2]+a[i-1];
			a[i]=n;
		}
		return a[num];
	}
}

long fibForLong1 (long num){
	long anterior, anteriorDois, retorno;
	if (num<=1) return num;
	else{
		anterior = 1;
		anteriorDois = 0;
		for (int i = 2; i <=num; i++)
		{
			retorno=anterior+anteriorDois;
			anteriorDois=anterior;
			anterior=retorno;
		}
	}
	return retorno;
}

long fibRecursivoLong (long num){
	if(num == 0 || num==1)
		return num;
	else
		return fibRecursivoLong(num-1) + fibRecursivoLong(num-2);
}