#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	
	int P, O, M, A, G, T, B, V;
    
	scanf("%d", &V );
	
	P = V/100;
	O = ((V - P*100)/50);
	M = (V - P*100 - O * 50)/20;
	A = (V - P*100 - O * 50 - M * 20)/10;
	G = (V - P*100 - O * 50 - M * 20 - A*10)/5;
	T = (V - P*100 - O * 50 - M * 20 - A*10 - G*5 )/2;
	B = (V - P*100 - O * 50 - M * 20 - A*10 - G*5 - T*2);
	     
	printf("%d\n", V );
	printf("%d nota(s) de R$ 100,00\n", P );
	printf("%d nota(s) de R$ 50,00\n",  O );
	printf("%d nota(s) de R$ 20,00\n",  M );
	printf("%d nota(s) de R$ 10,00\n",  A );
	printf("%d nota(s) de R$ 5,00\n",   G );
	printf("%d nota(s) de R$ 2,00\n",   T );
	printf("%d nota(s) de R$ 1,00\n",   B );    
}
