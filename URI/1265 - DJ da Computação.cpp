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
	int n, q, u;
	char nome[30][111];
	while( scanf("%d%d", &n, &q ) != EOF && n+q ){
		vector<ll> pot(1, 1), sum(1, 0);
		rep( i, 1, 100 ){
			pot.pb( pot[i-1] * n );
			sum.pb( i * pot[i] + sum[i-1] );
			if( sum[i] > 100000000 ) break;
		}
		rep( i, 1, n+1 ) scanf("%s", nome[i] );
		strcpy( nome[0], nome[n] );
		rep( i, 0, q ){
			scanf("%d", &u );
			int pos = lower_bound( all(sum), u ) - sum.begin();
			u -= sum[pos-1];
			vector<int> word;
			for( int i = pos; i > 0	; i-- ){
				int aux = pos * pot[i-1];
				word.pb( u/aux + ( u%aux != 0 ));
				u %= aux;//( aux*(u/aux) );
			}
			if( !u ) u = pos;
			printf("%s\n", nome[word[u-1]] );
		}
		printf("\n");
	}
}

