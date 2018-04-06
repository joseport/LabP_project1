#include "bigNumber.h"
#include "intlist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


bigNumber somaAritmetica(bigNumber primeiro, bigNumber segundo){
	if (primeiro==NULL) return segundo;
	if (segundo==NULL) return primeiro;
	int s=0;
	int carry=0;
	
	bigNumber retorno=NULL;//newBigNumber(0,NULL);

	while(primeiro!=NULL && segundo!=NULL){
		s=head(primeiro)+head(segundo)+carry;
		carry=0;
		if (s>=10){
			s-=10;
			carry=1;
		}
		bigNumber k = newBigNumber(s,NULL);
		retorno=append(retorno,k);
		primeiro=tail(primeiro);//eliminar o primeiro elemento
		segundo=tail(segundo);//eliminar o primeiro elemento
	}

	if (primeiro==NULL && segundo==NULL){ // os dois tinham o mesmo tamanho 
		if (carry > 0){ //soma so pode ser 0 ou 1
			retorno=append(retorno,newBigNumber(carry,NULL));
		}
		return retorno;
	}

	else if (primeiro==NULL){//primeiro era mais pequeno
		while (segundo!=NULL){
			s=head(segundo)+carry;
			carry=0;
			if (s>=10){
				s-=10;
			}
			carry=0;
			bigNumber k = newBigNumber(s,NULL);
			retorno=append(retorno,k);
			segundo=tail(segundo);
		}
	}
	else if (segundo==NULL){//primeiro era maior
		while (primeiro!=NULL){
			s=head(primeiro)+carry;
			carry=0;
			if (s>=10){
				s-=10;
			}
			carry=0;
			bigNumber k = newBigNumber(s,NULL);
			retorno=append(retorno,k);
			primeiro=tail(primeiro);
		}
		
	}
	return retorno;

}

bigNumber subtracaoAritmetica(bigNumber primeiro, bigNumber segundo){
	int res=comparation(primeiro,segundo);
	bigNumber retorno=NULL;
	switch (res) {
		case 0:
			retorno=newBigNumber(0,NULL);
			break;
		case 1:
			retorno = subtracao(primeiro,segundo);
			break;
		case -1:
			retorno = subtracao(segundo,primeiro);
		//	retorno=reverseList(retorno);
		//	retorno = append(newBigNumber(head(retorno)*-1,NULL),tail(retorno));
		//	retorno=reverseList(retorno);
			break;
		default:
		 	printf("ERROR\n");
			exit(-1);
	}
	return retorno;
}


bigNumber subtracao(bigNumber primeiro,bigNumber segundo){
	if (primeiro==NULL) return segundo;
	if (segundo==NULL) return primeiro;
	int numero1=0;
	int numero2=0;
	int carry=0;
	int s=0;
	int flag=0;

	bigNumber retorno=NULL;//newBigNumber(0,NULL);

	while (primeiro!=NULL && segundo!=NULL) {
		numero1=head(primeiro);
		numero2=head(segundo);


		s=numero1-numero2-carry;
		if(s<0){
			s+=10;
			carry=1;
		}
		else
			carry=0;


		bigNumber k = newBigNumber(s,NULL);
		retorno=append(retorno,k);
		primeiro=tail(primeiro);//eliminar o primeiro elemento
		segundo=tail(segundo);//eliminar o primeiro elemento

	}
	if (primeiro==NULL && segundo==NULL){ // os dois tinham o mesmo tamanho
		if (carry > 0){ //subtacao so pode ser 0 ou 1
			retorno=append(retorno,newBigNumber(carry,NULL));
		}
		return retorno;
	}
	else if (primeiro==NULL){//primeiro era mais pequeno
		while (segundo!=NULL){
			s=head(segundo)-carry;
			carry=0;
			if (s<0){
				s*=-1;
				carry=1;
			}

			bigNumber k = newBigNumber(s,NULL);
			retorno=append(retorno,k);
			segundo=tail(segundo);
		}
	}
	else if (segundo==NULL){//primeiro era maior
		while (primeiro!=NULL){
			s=head(primeiro)-carry;
			carry=0;
			if (s<0){
				s*=-1;
				carry=1;
			}

			bigNumber k = newBigNumber(s,NULL);
			retorno=append(retorno,k);
			primeiro=tail(primeiro);
		}

	}

	return retorno;
}


bigNumber multAritmeticaBnInt(bigNumber primeiro, int segundo){ //usa a soma para multiplicar
	if (comparation(primeiro,newBigNumber(0,NULL))==0 || segundo==0 ){ //se algum deles for 0
		return newBigNumber(0,NULL);
	}
	bigNumber retorno = primeiro;
	int cont=1;
	while (cont<segundo){
		retorno=somaAritmetica(retorno,primeiro);
		cont++;
	}
	return retorno;

}

bigNumber multAritmetica(bigNumber primeiro, bigNumber segundo){ //usa a soma para multiplicar
	printlist(primeiro);
	printf("\n");
	printlist(segundo);
	printf("\n");

	if (primeiro==NULL || segundo==NULL) return newBigNumber(0,NULL);
	int l=length(segundo,0);
	bigNumber a[l];
	for (int i = 0; i <l; i++){
		a[i]=multAritmeticaBnInt(primeiro,head(segundo));
		segundo=tail(segundo);
	}
	int i=1;

	bigNumber retorno=a[0];

	while(i<l){
		bigNumber n=a[i];
		for (int r = 0; r <i; r++)
		{
			n=append( newBigNumber(0,NULL) ,n);
		}
		retorno=somaAritmetica(n,retorno);
		i++;
	}
	return retorno;

}

int comparation(bigNumber valor1, bigNumber valor2){
	int tamanho1=length(valor1,0);
  	int tamanho2=length(valor2,0);
	valor1=reverseList(valor1);
	valor2=reverseList(valor2);
	while(head(valor1)==0 && tamanho1>1){
		valor1=tail(valor1);
		tamanho1--;
	}
	while(head(valor2)==0 && tamanho2>1){
		valor2=tail(valor2);
		tamanho2--;
	}
  	if(tamanho1!=tamanho2){
    	if(tamanho1<tamanho2)
				return -1;

			return 1;
	}

  	for(int i=0;i<tamanho1;i++){
    	int temp1=head(valor1);
	    int temp2=head(valor2);
    	if(temp1>temp2){
      		return 1;
    	}
			else if(temp1<temp2)
				return -1;
    	valor1=tail(valor1);
    	valor2=tail(valor2);
  	}
  	return 0;

}

bigNumber leitura (char s[]){
  int tamanho=strlen(s);
  bigNumber number=NULL;


  for(int i=0;i<tamanho;i++){
    char c = s[i];
    int valor = atoi(&c);
    number=newBigNumber(valor,number);

  }
  return number;

}

bigNumber newBigNumber(int h, bigNumber rest){
	return newlist(h, rest);
}
