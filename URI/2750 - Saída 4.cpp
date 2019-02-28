#include<bits/stdc++.h>


using namespace std;

int main(){
	
	int v[20];
	
	for( int i = 0 ; i < 16; i++ ) v[i] = i;
	
	printf("---------------------------------------\n");
	printf("|  decimal  |  octal  |  Hexadecimal  |\n");
	printf("---------------------------------------\n");
	for( int i = 0; i < 16; i++ )
		printf("|     %2d    |   %2o    |       %X       |\n", v[i], v[i], v[i] );
	printf("---------------------------------------\n");
	
}
