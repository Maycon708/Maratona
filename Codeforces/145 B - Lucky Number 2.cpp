#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	int a, b, c, d, op = 0;
	string s;
	
	scanf("%d%d%d%d", &a, &b, &c, &d );
	
	if( abs(c-d) > 1 || max(c, d) > min(a, b) || c == d && c == max(a, b) ){
		puts("-1");
		return 0;
	}
	
	int aux = max(c, d);
	if( d > c || c == d && a == c ) op = 1;
	a -= aux, b -= aux;
	if( c == d ) op? b-- : a--;
	
	rep( i, 0, aux ){
		if( op ){
			printf("7");
			if( i+1 == aux && c != d ) for( ; b > 0; b-- ) printf("7"); 
		}
		printf("4");
		for( ; a > 0; a-- ) printf("4");
		if( !op ){
			printf("7");
			if( i+1 == aux ) for( ; b > 0; b-- ) printf("7"); 
		}
	}
	if( c == d ) printf( op? "7" : "4" );
	if( c == d ) for( ; b > 0; b-- ) printf("7"); 
	printf("\n");
}
