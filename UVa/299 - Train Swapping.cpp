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

int n, v[100];

int bubble(){
	int cnt = 0, aux = 1;
	while( aux ){
		aux = 0;
		rep( i, 0, n-1 ){
			if( v[i] <= v[i+1] ) continue;
			aux = 1;
			cnt++;
			swap( v[i], v[i+1] );
		}
	}
	return cnt;
}

int main(){
	int t;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		rep( i, 0, n ) scanf("%d", &v[i] );
		printf("Optimal train swapping takes %d swaps.\n", bubble() );
	}
}

