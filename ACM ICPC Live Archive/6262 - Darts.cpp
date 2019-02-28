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

#define N 100100

int main(){
	int aux[] = { 20, 40, 60, 80, 100, 120, 140, 160, 180, 200 }; 
	int t, n, x, y;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		int ans = 0;
		rep( i, 0, n ){
			scanf("%d%d", &x, &y );
			rep( i, 0, 10 ){
				if( x*x+y*y <= aux[i]*aux[i] ){
					ans += ( 10 - i );
					break;
				}
			}
		}
		printf("%d\n", ans );
	}
}

