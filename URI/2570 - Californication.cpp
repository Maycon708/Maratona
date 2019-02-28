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

#define N 1010

int main(){
	int n, m, k, v, cnt[4];
	ii l[N], c[N];
	char op;
	
	while( scanf("%d%d%d", &n, &m, &k ) != EOF ){
		rep( i, 0, n ) l[i] = ii( -1, -1 );
		rep( i, 0, m ) c[i] = ii( -1, -1 );
		rep( i, 0, 4 ) cnt[i] = 0;
		int turn = 0;
		rep( i, 0, k ){
			scanf(" %c%d", &op, &v );
			v--;
			if( op == 'L' ) l[v] = ii( turn, i );
			else c[v] = ii( turn, i );
			turn++;
			if( turn == 4 ) turn = 0;
		}
		rep( i, 0, n ){
			rep( j, 0, m ){
				if( l[i].F != -1 && c[j].F != -1 ){
					if( l[i].S > c[j].S ) cnt[l[i].F]++;
					else cnt[c[j].F]++;
				}
				else if( l[i].F != -1 ) cnt[l[i].F]++;
				else if( c[j].F != -1 ) cnt[c[j].F]++;
			}
		}
		printf("R%d H%d C%d P%d\n", cnt[0], cnt[1], cnt[2], cnt[3] );
		return 0;
	}

}
