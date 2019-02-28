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
typedef set<int> :: iterator _it;

#define N 112345

int bit[N];

void update( int x, int v = 1 ){
	for( int i = x; i < N; i += ( i&-i ))
		bit[i] += v;
}

int query( int x ){
	int sum = 0;
	for( int i = x; i > 0; i -= ( i&-i ))
		sum += bit[i];
	return sum;
}

int main(){
	int ip, m, na, pc;
	
	while( scanf("%d%d", &ip, &m ) != EOF ){
		memset( bit, 0, sizeof bit );
		while( m-- ){
			scanf("%d%d", &pc, &na );
			int a = query( min( pc+ip, N-5 ) ) - query( max( 0, pc-ip-1 ) );
			if( a <= na ) update(pc, 1);
		}
		printf("%d\n", query(N-5) );
	}
}
