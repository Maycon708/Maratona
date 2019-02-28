#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	
	int H, M, S, T;
    
	scanf("%d", &T );
	
	H = T/3600;
	M = ((T - H*3600)/60);
	S = (T - H*3600 - M *60);
	
	printf("%d:%d:%d\n", H, M, S );         
}
