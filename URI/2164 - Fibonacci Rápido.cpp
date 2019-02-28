#include<bits/stdc++.h>

int main(){

	int n;
	while( scanf("%d", &n ) != EOF ){
		printf("%.1f\n", ( pow( ( 1 + sqrt(5) )/2.0, n ) - pow( ( 1 - sqrt(5) )/2.0, n ) )/ sqrt(5) ); 
	}
}
