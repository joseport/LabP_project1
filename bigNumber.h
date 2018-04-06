#ifndef B_N
#define	B_N

#include "intlist.h"

typedef intlist bigNumber;

bigNumber somaAritmetica(bigNumber primeiro, bigNumber segundo);
bigNumber multAritmetica(bigNumber primeiro, bigNumber segundo);
bigNumber newBigNumber(int h, bigNumber rest);
bigNumber leitura (char s[]);
int comparation(bigNumber valor1, bigNumber valor2);

bigNumber multAritmeticaBnInt(bigNumber primeiro, int segundo);
bigNumber subtracaoAritmetica(bigNumber primeiro, bigNumber segundo);
bigNumber subtracao(bigNumber primeiro,bigNumber segundo);


#endif