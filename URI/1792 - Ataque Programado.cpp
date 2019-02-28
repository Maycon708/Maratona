#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();
int n, d[20000], m, s, a, b, e[20000], f[20000], vis[20000];
 
vector < int > adj[20000];
 
 
bool dfs(){
	priority_queue < ii > pq;
     
    rep( i, 1, n+1 ){
        vis[i] = false;
        if(d[i] == 0 ) pq.push( ii( -e[i], i ) );
    }
     
    while(!pq.empty()){
         
        int u = pq.top().S;
        int c = -pq.top().F;
        pq.pop();
		if( vis[u] || s <= c ) continue;
        s += f[u];
        vis[u] = true;
		rep( i, 0, adj[u].size() ){
            int w = adj[u][i];
            d[w]--;
            if( !d[w] ){ // w no lugar de i !!
                pq.push( ii( -e[w], w ) );
            }
        }
         
    }
     
	rep( i, 1, n+1 )
        if( !vis[i] ) return false;
     
    return true;
}
 
int main(){
     
    while( 1 ){
        n = readInt();
        m = readInt();
        s = readInt();
        
        if( !n && !m && !s ) break;
        
        rep( i, 1, n+1 ) {
            e[i] = readInt();
            d[i] = 0;
            adj[i].clear();
        }
         
        rep( i, 1, n+1 ) f[i] = readInt();
         
        while(m--){
			a = readInt();
			b = readInt();
            adj[a].push_back(b);
            d[b]++;
        }
         
        if( dfs() ) cout << "possivel" << endl;
        else cout << "impossivel" << endl;
    }
     
    return 0;
}

ll readInt () {
    bool minus = false;
    ll result = 0; char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}

