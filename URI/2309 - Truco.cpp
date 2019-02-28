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

void C( int &a ){
	if( a <= 3 ) a += 7;
	else if( a <= 7 ) a -= 3;
	else if( a == 11 ) a = 6;
	else if( a == 12 ) a = 5;
	else a = 7;
}

int main(){
	int n, a[5], b[5];
	while( scanf("%d", &n ) != EOF ){
		int aa = 0, bb = 0;
		rep( i, 0, n ){
			rep( j, 0, 3 ){
				scanf("%d", &a[j] );
				C( a[j] );
			}
			int cnt = 0;
			rep( j, 0, 3 ){
				scanf("%d", &b[j] );
				C( b[j] );
				if( b[j] > a[j] ) cnt++;
			}
			if( cnt >= 2 ) bb++;
			else aa++;
		}
		printf("%d %d\n", aa, bb );
	}
}

