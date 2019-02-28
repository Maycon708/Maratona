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

int main(){
	
	int t;
	char s1[111], s2[111];
	cin >> t;
	gets(s1);
	while( t-- ){
		gets(s1);
		gets(s2);
		int t1 = strlen(s1), t2 = strlen(s2);
		for( int i = 0; i < t1; i += 2 ){
			printf("%c", s1[i] );
			if( i+1 != t1 ) printf("%c", s1[i+1] );
			for( int j = i; j < min( t2, i+2 ); j++ ) printf("%c", s2[j] );
		}
		printf("\n");
	}
	
}
