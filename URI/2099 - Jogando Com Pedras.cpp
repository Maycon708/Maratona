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

const int mod = 1e9+7;

int main(){
	int n, v[1001][2];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n+1 ) v[i][0] = v[i][1] = 0;
		v[0][0] = 1;
		rep( i, 1, n+1 ){
			rep( j, 0, n ){
				int u = i + j;
				if( u > n ) break;
				if( i&1 ) 
					v[u][0] = ( v[u][0] + v[j][0] )%mod, 
					v[u][1] = ( v[u][1] + v[j][1] )%mod;
				else  
					v[u][0] = ( v[u][0] + v[j][1] )%mod, 
					v[u][1] = ( v[u][1] + v[j][0] )%mod;
			}
		}
		printf("%d\n", v[n][1] );
	}
}

