#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	char nome[1000];
	while( scanf("%d", &n ) != EOF ){
		int cnt = 0;
		for( int i = 0; i < n; i++ ){
			scanf("%s", nome );
			if( !strcmp( nome, "Tetrahedron") ) 	cnt += 4;
			if( !strcmp( nome, "Cube") ) 			cnt += 6;
			if( !strcmp( nome, "Octahedron") ) 		cnt += 8;
			if( !strcmp( nome, "Dodecahedron") ) 	cnt += 12;
			if( !strcmp( nome, "Icosahedron") ) 	cnt += 20;
		}
		printf("%d\n", cnt );
	}
	return 0;
}
