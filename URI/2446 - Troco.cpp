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
	int k, n, v;
	while( cin >> k >> n ){
		vector<int> pd( k+1, 0 );
		pd[0] = 1;
		rep( i, 0, n ){
			cin >> v;		
			for( int i = k; i >= 0; i-- ){
				int u = i + v;
				if( u <= k && pd[i] ) pd[u] = 1;
			}
		}
		if( pd[k] ) printf("S\n");
		else printf("N\n");
	}
}

