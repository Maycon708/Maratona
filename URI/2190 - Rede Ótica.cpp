#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int pai[110];

int findset( int u ){
	if( pai[u] != u ){
		pai[u] = findset( pai[u] );
	}
	return pai[u];
}

void unionset( int u, int v ){
	int a = findset( u );
	int b = findset( v );
	pai[a] = b;
}

bool sameset( int u, int v ){
	return findset( u ) == findset( v );
}

void init( int n ){
	rep( i, 0, n+1 ) pai[i] = i;
}

int main(){
	
	int n, t = 1, m;
	while( cin >> n >> m ){
		if( !n && !m ) break;
		priority_queue < pair < int, ii > > pq;	
		vector < ii > V;
		init( n );
		rep( i, 0, m ){
			int a, b, c;
			cin >> a >> b >> c;
			pq.push( mk( -c, ii( -a, -b ) ) );
		}
		printf("Teste %d\n", t++ );
		while( !pq.empty() ){
			int u = -pq.top().S.F, v = -pq.top().S.S;
			if( u > v ) swap( u, v );
			if( !sameset( u, v ) ){
				V.pb( ii( u, v ) );
				unionset( u, v );
			}
			pq.pop();
		}
		rep( i, 0, V.size() ) printf("%d %d\n", V[i].F, V[i].S );
		printf("\n");
	}
}


