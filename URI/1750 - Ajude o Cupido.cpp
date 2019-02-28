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

int main(){

	int n, v[25], u, aux;
	
	while( scanf("%d", &n ) != EOF ){
		vector < int > V;
		rep( i , 0, 25 ) v[i] = 0;
		rep( i, 0, n ){
			scanf("%d", &u );
			u += 12;
			v[u]++;
		}
		int a = 0, b;
		rep( i, 0, 25 ) if( v[i]&1 ) V.pb( i - 12 );
		if( V.empty() ){
			printf("0\n"); 
			continue;
		}
		for( int i = 0; i < V.size();  i += 2 ){
			a += abs( V[i] - V[i+1] );
		}
		b = 24 - abs( V[0] - V.back() );
		for( int i = 1; i < V.size()-1;  i += 2 ){
			b += abs( V[i] - V[i+1] );
		}
		printf("%d\n", min( a, b ) );
	}	

}

