#include <bits/stdc++.h>

#define INF 200*18+10
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

	int n;
	char s[100100];
	
	while( scanf("%d", &n) != EOF ){
		scanf("%s", s );
		int x = 0, y = 0, cnt = 0;
		int last = -1, at = -1;
		rep( i, 0, n ){
			if( s[i] == 'U' ) y++;
			else if( s[i] == 'R' ) x++;
			if( x > y ) at = 1;
			else if( x < y ) at = 2;
			if( last == -1 ) last = at;
			if( at != last ) cnt++, last = at;
		}
		printf("%d\n", cnt );
	}	
	
}
