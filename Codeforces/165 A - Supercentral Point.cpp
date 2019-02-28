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

int main(){
	int n, x[222], y[222];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ) scanf("%d%d", &x[i], &y[i] );
		int cnt = 0;
		rep( i, 0, n ){
			bool l = 0, r = 0, u = 0, d = 0;
			rep( j, 0, n ){
				if( x[i] == x[j] ){
					if( y[i] > y[j] ) d = 1;
					if( y[i] < y[j] ) u = 1;
				}
				if( y[i] == y[j] ){
					if( x[i] > x[j] ) l = 1;
					if( x[i] < x[j] ) r = 1;
				}
			}
			if( l && r && u && d ) cnt++;
		}
		printf("%d\n", cnt );
	}
}

