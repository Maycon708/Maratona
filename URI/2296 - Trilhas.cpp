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
	int n, k, last, u;
	while( scanf("%d", &n ) != EOF ){
		int ans = INF, id;
		rep( i, 0, n ){
			int a = 0, b = 0;
			scanf("%d%d", &k, &last );
			rep( j, 1, k ){
				scanf("%d", &u );
				if( u > last ) a += ( u - last );
				else b += ( last - u );
				last = u;
			}
			if( ans > min( a, b ) ){
				ans = min( a, b );
				id = i+1;
			}
		}
		printf("%d\n", id );	
	}
}

