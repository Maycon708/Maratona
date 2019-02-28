#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 100*30
#define F first
#define S second
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

int main(){
	
	int c, v[200100], sum[200100], n, m, u;
	
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, 2*n ) sum[i] = v[i] = 0;
		scanf("%d", &m );
		rep( i, 0, m ){
			scanf("%d", &u );
			v[u] = 1;
		}
		rep( i, 0, 2*n ){
			sum[i] = v[i%n];
			if( i ) sum[i] += sum[i-1];
		}
		int k = n/m, aux;
		rep( i, 0, k ){
			aux = 1;
			for( int j = i+k; j < i+n; j += k ){
				int a = sum[j-k];
				int b = sum[j];
				if( abs( a - b ) != 1 ){
					aux = 0;
					break;
				}
			}
			if( aux ){
				puts("S");
				break;
			}
		}
		if( !aux ) puts("N");
	}
	
	return 0;
}
