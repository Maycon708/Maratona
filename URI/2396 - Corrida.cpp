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

int p[1000], aux[1000];

bool cmp( int a, int b ){
	if( p[a] != p[b] ) return p[a] < p[b];
	return a < b;
}

int main(){
	int n, m, v;
	while( cin >> n >> m ){
		rep( i, 0, n ){
			p[i] = 0; aux[i] = i;
			rep( j, 0, m ){
				cin >> v;
				p[i] += v;
			}
		}
		sort( aux, aux+n, cmp );
		rep( i, 0, 3 ) printf("%d\n", aux[i]+1 );
	}
}

