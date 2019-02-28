#include<stdio.h>

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		if( n%6 ) printf("N\n");
		else printf("Y\n");
	}
}
