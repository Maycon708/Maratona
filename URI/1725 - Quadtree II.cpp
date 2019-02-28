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

char xmb[520][520];

string solve( int top, int left, int sz ){
	if( sz == 1 ){
		string s;
		s.pb( xmb[top][left] ); 
		return s;
	}
	string l  = "Q";
	l += solve( top, left, sz/2 );
	l += solve(top, left+sz/2, sz/2 ); 
	l += solve(top+sz/2, left, sz/2 );
	l += solve(top+sz/2, left+sz/2, sz/2);
	if( l == "QWWWW" ) return "W";
	if( l == "QBBBB" ) return "B";
	return l;
}

int main(){
	
	char lixo[100];
	int n, x;
	
	while( cin >> lixo >> lixo >> n  ){
		cin >> lixo >> lixo >> n;
		cin >> lixo >> lixo >> lixo >> lixo >> lixo;
		rep( i, 0, n ){
			rep( j, 0, n/8 ){
				scanf("%x,", &x );
				rep( k, 0, 8 ){
					xmb[i][j*8+k] = ( x&(1<<k) )? 'B' : 'W';
				}
			}
		}
		cin >> lixo;
		string s = solve(0, 0, n);
		cout << n << endl;
		cout << s << endl;
	}
}

