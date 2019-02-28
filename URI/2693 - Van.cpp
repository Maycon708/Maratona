#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = a; i < b; i++ )

using namespace std;

struct aluno{
	char nome[100];
	char dir;
	int dist;
	void read(){
		scanf("%s %c%d", nome, &dir, &dist );
	}
} v[1000000];

bool cmp( aluno a, aluno b ){
	if( a.dist != b.dist ) return a.dist < b.dist;
	if( a.dir != b.dir ) return a.dir < b.dir;
	return strcmp( a.nome, b.nome ) < 0;
}

int main(){
	
	int n;
	
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ) v[i].read();
		sort(v, v+n, cmp);
		rep( i, 0, n ) printf("%s\n", v[i].nome );
	}
	
	return 0;
}