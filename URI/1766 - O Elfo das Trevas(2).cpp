#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

struct rena{
	int p, i;
	double h;
	string nome;
};

bool cmp( rena a, rena b ){
	if( a.p != b.p ) return a.p > b.p;
	if( a.i != b.i ) return a.i < b.i;
	if( a.h != b.h ) return a.h < b.h;
	return a.nome < b.nome;
}

int main(){
	int t, n, m, test = 1;
	rena aux;
	scanf("%d", &t );
	while( t-- ){
		vector<rena> v;
		scanf("%d%d", &n, &m );
		while( n-- ){
			cin >> aux.nome >> aux.p >> aux.i >> aux.h;
			v.pb(aux);			
		}
		debug2( v.size(), v[0].nome )
		sort( v.begin(), v.end(), cmp );
		printf("CENARIO {%d}\n", test++ );
		rep( i, 0, m )
			printf("%d - %s\n", i+1, v[i].nome.c_str() ); 
	}
}	
