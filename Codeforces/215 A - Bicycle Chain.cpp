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
	int n, m, a[100], b[100];
	
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ) scanf("%d", &a[i] );
		scanf("%d", &m );
		rep( i, 0, m ) scanf("%d", &b[i] );
		int at = -1, cnt;
		rep( i, 0, m ){
			rep( j, 0, n ){
				if( b[i]%a[j] ) continue;
				if( b[i]/a[j] == at ) cnt++;
				else if( b[i]/a[j] > at ) cnt = 1, at = b[i]/a[j];
			}
		}
		printf("%d\n", cnt );
	}
}

