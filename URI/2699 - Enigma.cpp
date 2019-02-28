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

char s[1111];
int pd[1111][1111], mat[1111][1111], d, n;

int solve( int p, int r ){
	if( p == n ) return !r;
	int &ans = pd[p][r];
	if( ans == -1 ){
		ans = 0;
		if( s[p] == '?' ){
			mat[p][r] = -1;
			for( int i = 9; i >= 0; i-- ){
				if( !p && !i ) break;
				int a = solve( p+1, (r*10+i)%d );
				if( a ) mat[p][r] = i;
				ans |= a;
			}
		}
		else mat[p][r] = s[p]-'0', ans = solve( p+1, (r*10+s[p]-'0')%d ); 
	}
	return ans;
}

void back( int p, int r ){
	if( p == n ){
		printf("\n");
		return;
	}
	printf("%c", char('0'+mat[p][r] ));
	back(p+1, (r*10+mat[p][r])%d );
}

int main(){
	while( scanf("%s%d", s, &d ) != EOF ){
		n = strlen(s);
		memset( pd, -1, sizeof pd );
		if( solve( 0, 0 ) ) back( 0, 0 );
		else puts("*");
	} 
}
