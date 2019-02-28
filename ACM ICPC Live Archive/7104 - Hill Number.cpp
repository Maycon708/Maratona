#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef unsigned long long int ll;
typedef pair<int,int> ii;

ll pd[77][10][2][2];
int memo[77][10][2][2], cnt, t;
char s[77];

ll solve( int i, int l, int p, int op ){
	if( i == 0 ) return 1;
	ll &ret = pd[i][l][p][op];
	if( memo[i][l][p][op] != cnt ){
		memo[i][l][p][op] = cnt; 
		ret = 0;
		int c = s[t-i]-'0';
		rep( k, 0, 10 ){
			if( ( op && k > l ) || ( p && k > c ) ) continue;
			if( op ) ret += solve( i-1, k, p && k == c, 1 );
			else if( k >= l ) ret += solve( i-1, k, p && k == c, 0 );
			else ret += solve( i-1, k, p && k == c, 1 );
		}
	}
	return ret; 
}

bool check(){
	int l = s[0]-'0', aux = 0;
	rep( i, 1, t ){
		if( s[i]-'0' > l ){
			if( aux ) return 1;
		}
		else if( s[i] - '0' < l ) aux = 1;
		l = s[i] - '0';
	}
	return 0;
}


int main(){

	int test;
	scanf("%d", &test );
	while( test-- ){
		scanf("%s", s );
		cnt++;
		t = strlen(s);
		if( check() ){
			puts("-1");
			continue;
		}
		ll ans = 0;
		int c = s[0] - '0';
		rep( i, 1, c+1 ) ans += solve( t-1, i, (i == c), 0 );
		for( int i = t-1; i > 0; i-- ){
			rep( j, 1, 10 )
				ans += solve( i-1, j, 0, 0 );
		}
		printf("%llu\n", ans );
	}

	return 0;
}	
