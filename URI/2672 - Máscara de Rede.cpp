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
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

bool S( string s, int v[] ){
	int k = 0, ans = 0, aux = 0;
	rep( i, 0, s.size() ){
		aux |= ( s[i] == '/');
		if( s[i] >= '0' && s[i] <= '9' ){
			ans *= 10;
			ans += s[i] - '0';
		}
		else{
			v[k++] = ans;
			ans = 0;
		}
	}
	v[k] = ans;
	return aux;
}

int main(){
	string s;
	char l;
	int M, v[100];
	while( getline( cin, s ) ){
		int aux;
		
		if( S( s, v ) )	aux = 32 - v[4];
		else{
			aux = 32;
			rep( i, 4, 8 ) aux -= __builtin_popcount(v[i]);
		}
		int k = 3;
		M = aux;
		ll tot = (1LL << M) - 2;
		while( M >= 8 ) v[k--] = 0, M -= 8;
		rep( i, 0, M ){
			v[k] &= ~(1<<i);
		}
		printf("Endereco de rede: %d.%d.%d.%d\n", v[0], v[1], v[2], v[3] );
		M = aux;
		k = 3;
		while( M >= 8 ) v[k--] = 255, M -= 8;
		rep( i, 0, M ){
			v[k] |= (1<<i);
		}
		printf("Endereco de broadcast: %d.%d.%d.%d\n", v[0], v[1], v[2], v[3] );
		
		printf("Numero de maquinas: %lld\n\n", tot );
	}
}
