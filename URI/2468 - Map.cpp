#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 101000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

ll pai[MAXV], tam[MAXV];

void init(int v){
    for (int i=0; i <= v; i++)
    	tam[i] = 1,
        pai[i] = i;
}

int findset(int i){
    if (i != pai[i]){
		int u = findset( pai[i] );
		tam[i] = tam[u]; 
        pai[i] = u;
    }
    return pai[i];
}
 
void unionset(int a, int b){
    int aa = findset(a); 
    int bb = findset(b);
    tam[aa] += tam[bb];
	tam[bb] = tam[aa];
    pai[bb] = aa; 
}

bool sameset(int a, int b){
    return findset(a) == findset(b); 
}

int main(){
	int n, a, b, c;
	while( scanf("%d", &n ) != EOF ){
		init(n);
		stack<ii> s;
		rep( i, 1, n ){
			scanf("%d%d%d", &a, &b, &c );
			if( c ) s.push( ii( a, b ) );
			else unionset( a, b );
		}
		ll ans = 0;
		while( !s.empty() ){
			int u = s.top().F;
			int v = s.top().S;
			s.pop();
			if( sameset( u, v ) ) continue;
			ans += ( tam[u] * tam[v] );
			unionset( u, v );
		}
		printf("%lld\n", ans );
	}
}
