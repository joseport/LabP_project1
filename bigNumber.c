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
	
	bigNumber retorno=NULL;

	while(primeiro!=NULL && segundo!=NULL){
		s=head(primeiro)+head(segundo)+carry;
		carry=0;
		if (s>=10){
			s-=10;
			carry=1;
		}
		retorno=append(retorno,newlist(s,NULL));
		primeiro=tail(primeiro);
		segundo=tail(segundo);
	}
	if (primeiro==NULL){//primeiro era mais pequeno
		while (segundo!=NULL){
			s=head(segundo)+carry;
			carry=0;
			if (s>=10){
				s-=10;
			}
			carry=0;
			retorno=append(retorno,newlist(s,NULL));
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
			retorno=append(retorno,newlist(s,NULL));
			primeiro=tail(primeiro);
		}
		
	}
	return retorno;

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