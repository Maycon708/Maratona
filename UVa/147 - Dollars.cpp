#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef unsigned long long int ll;

const int N = 31000;
int v[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
ll ans[N];

void solve(){
	ans[0] = 1;
	rep( j, 0, 11 ){
		rep( i, 0, N ){
			int w = i+v[j];
			if( w >= N ) continue;
			ans[w] += ans[i]; 
		}
	}
}

int main(){
	solve();
	char s[100];
	while( scanf("%s", &s ) != EOF ){
		int t = strlen( s ), n = 0;
		rep( i, 0, t ){
			if( s[i] == '.' ) continue;
			n *= 10;
			n += ( s[i] - '0' );
		}
		if( !n ) break;
		printf("%6.2f%17llu\n", n/100.0, ans[n] );
	}
}
s
