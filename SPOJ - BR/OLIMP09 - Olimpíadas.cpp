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

struct T{
	int o, p, b, id;
	void init( int i ){ o = p = b = 0, id = i; }
};

bool cmp( T a, T b ){
	if( a.o != b.o ) return a.o > b.o;
	if( a.p != b.p ) return a.p > b.p;
	if( a.b != b.b ) return a.b > b.b;
	return a.id < b.id;
}

int main(){
	int n, m, a, b, c;
	T v[200];
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n+1 ) v[i].init(i);
		rep( i, 0, m ){
			scanf("%d%d%d", &a, &b, &c );
			--a, --b, --c;
			v[a].o++; v[b].p++; v[c].b++;
		}
		sort( v, v+n, cmp );
		rep( i, 0, n ) printf("%d%s", v[i].id+1, ( i+1 == n )? "\n" : " " );  
	}

}
