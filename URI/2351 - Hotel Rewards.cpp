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
	int n, k, v[111000];
	while( scanf("%d%d", &n, &k ) != EOF ){
		int sum = 0;
		rep( i, 0, n ) scanf("%d", &v[i] ), sum += v[i];
		priority_queue<int> pq;
		int cnt = 1;
		rep( i, k, n ){
			cnt = ( i+1 )/( k+1 );
			if( pq.size() < cnt ) pq.push( -v[i] );
			else{
				int u = -pq.top();
				if( v[i] <= u ) continue;
				pq.pop();
				pq.push( -v[i] );
			}
		}
		while( !pq.empty() ){
			sum += pq.top();
			pq.pop();
		}
		printf("%d\n", sum );
	}
}

