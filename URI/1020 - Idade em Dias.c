#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	
	int H, M, S, T;
    
	scanf("%d", &T );
	
	H = T/365;
	M = ((T - H*365)/30);
	S = (T - H*365 - M *30);
    
	printf("%d ano(s)\n", H );
	printf("%d mes(es)\n", M );
	printf("%d dia(s)\n", S );
     
}
