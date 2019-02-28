#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i <= int(b); i++)
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

#define MAXV 100100

int n, bit[MAXV], vet[MAXV];

void update(int x, int v){
    while(x <= n){
        bit[x] = bit[x] + v;
        x = x + (x&-x);
    }
}

int query(int x){
    int ans = 0;
    while(x > 0){
        ans = ans + bit[x];
        x = x - (x&-x);
    }
    return ans;
}

int main(){
	int m, ans[MAXV], u;
//	freopen("bolhas.in", "r", stdin );
	while( scanf("%d%d", &n, &m ) && n+m ){
		memset( bit, 0, sizeof bit );
		memset( ans, 0, sizeof ans );
		rep( i, 1, m ){
			scanf("%d", &u );
			int pos = 1 + u + query(u);
			update( u, 1 );
			while(ans[pos]) pos++;
			ans[pos] = i;
		}
		rep( i, 1, n ) printf("%d%s", ans[i]? ans[i]: ++m, i == n ? "\n" : " ");
	}
}

