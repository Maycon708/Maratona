#include <bits/stdc++.h>
    
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 10015
#define F first
#define S second
#define EPS 1e-9
    
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
    
using namespace std;
    
typedef pair <int, int> ii;
typedef long long int ll;

struct a {
	int custo;
	int DSP;
	int PPP;
};

a C[1000];
vector < int > adj[1000];
int pd[1000][10101], pd2[1010][10101];
int k, c[1010], d;
bool vis[1010];

int readInt () {
    bool minus = false;
    int result = 0; char ch;
      
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

a bfs( int ini ){
	queue < int > q;
	q.push( ini );
	int cont = 0;	
	int cont1 = 0;
	int cont2 = 0;
	while( !q.empty() ){
		int u = q.front();
		q.pop();
		if( vis[u] ) continue;
		vis[u] = true;
		cont += c[u];
		cont1 += ( u < d );
		cont2 += ( u >= d ); 
		int tam = adj[u].size();
		rep( i, 0, tam ){
			int v = adj[u][i];
			q.push( v );
		}
	}
	a aux;
	aux.custo = cont;
	aux.DSP = cont1;
	aux.PPP = cont2;
	return aux;
}

int solve( int pos, int cap ){
	if( pos == k ) return 0;
	if( !cap ) return 0;
	if( pd[pos][cap] != -1 ) return pd[pos][cap];
	int ans = solve( pos+1, cap );
	if( C[pos].DSP < C[pos].PPP && C[pos].custo <= cap ) ans = max( ans, solve( pos+1, cap - C[pos].custo )  + C[pos].PPP - C[pos].DSP );
	return pd[pos][cap] = ans;
}
int solve2( int pos, int cap ){
	if( pos == k ) return 0;
	if( !cap ) return 0;
	if( pd2[pos][cap] != -1 ) return pd2[pos][cap];
	int ans = solve2( pos+1, cap );
	if( C[pos].DSP > C[pos].PPP && C[pos].custo <= cap ) ans = max( ans, solve2( pos+1, cap - C[pos].custo )  + C[pos].DSP - C[pos].PPP );
	return pd2[pos][cap] = ans;
}

void init( int n, int c ){
	rep( i, 0, n+1 ){
		adj[i].clear();
		vis[i] = false;
		rep( j, 0, c+1 ){
			pd[i][j] = pd2[i][j] = -1;
		}
	}
	k = 0;
}

int main(){
	int p, r, b, u, v;
	while( scanf("%d", &d ) != EOF ){
		p = readInt();
		r = readInt();
		b = readInt();
		init( p + d, b );
		rep( i, 0, d ){
			c[i] = readInt();
		}
		rep( i, 0, p ){
			c[ d+i ] = readInt();
		}
		while( r-- ){
			u = readInt();
			v = readInt();
			u--, v += d-1;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		rep( i, 0, d+p ){
			if( !vis[i] ){
				C[k] = bfs( i ), k++;
			}
		}
		printf("%d %d\n", d+solve( 0, b ), p+solve2( 0, b ) );
	}
}
