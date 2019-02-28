#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 181442
#define MAXN 110
#define F first
#define SS second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef pair <int, int> ii;
typedef pair <string, int> si;
typedef long long int ll;

ll readInt();
int pai[MAXV];
inline int C( string s ){
	return s == "123456780";
}

struct board{
	string S;
	int pos;
};	

board v[MAXV];
unordered_map < string, int > mp;
vector < int > adj[MAXV];

inline bool dentro( int x, int y ){
	return x >= 0 && x < 3 && y >= 0 && y < 3;
}

inline int cmp( board a, board b ){
	return a.S < b.S;
}

void pre_comp(){
	int vis[MAXV];
	memset( vis, 0, sizeof vis );
	board res, aux;
	res.S = "123456780"; res.pos = 8;
	mp[res.S] = 1;
	v[1] = res;
	queue < int > q;
	q.push( 1 );
	int k = 2;
	while( !q.empty() ){
		int u = q.front();
		int K = v[u].pos;
		q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		if( K > 2 ){
			aux.S = v[u].S;
			swap( aux.S[K], aux.S[K-3] );
			aux.pos = K-3;
			if( !mp.count( aux.S ) ){
				v[k] = aux;
				mp[aux.S] = k++;
			}
			adj[u].pb( mp[aux.S] );
			q.push( mp[aux.S] );
		}
		if( K < 6 ){
			aux.S = v[u].S;
			swap( aux.S[K], aux.S[K+3] );
			aux.pos = K+3;
			if( !mp.count( aux.S ) ){
				v[k] = aux;
				mp[aux.S] = k++;
			}
			adj[u].pb( mp[aux.S] );
			q.push( mp[aux.S] );
		}
		if( K%3 > 0 ){
			aux.S = v[u].S;
			swap( aux.S[K], aux.S[K-1] );
			aux.pos = K-1;
			if( !mp.count( aux.S ) ){
				v[k] = aux;
				mp[aux.S] = k++;
			}
			adj[u].pb( mp[aux.S] );
			q.push( mp[aux.S] );
		}
		if( K%3 < 2 ){
			aux.S = v[u].S;
			swap( aux.S[K], aux.S[K+1] );
			aux.pos = K+1;
			if( !mp.count( aux.S ) ){
				v[k] = aux;
				mp[aux.S] = k++;
			}
			adj[u].pb( mp[aux.S] );
			q.push( mp[aux.S] );
		}
	}
}
void Print( string s ){
	int k = 0;
	rep( i, 0, 3 ){
		rep( j, 0, 3 ){
			printf("%c", s[k++]);
		}
		printf("\n");
	}
}

int bfs( int ini ){
	queue < ii > q;
	q.push( ii( ini, 0 ) );
	int vis[MAXV];
	rep( i, 0, MAXV ) vis[i] = 0, pai[i] = -1;
	while( !q.empty() ){
		int u = q.front().F;
		int c = q.front().SS;
		q.pop();
		if( u == 1 ) return c;
		if( vis[u] ) continue;
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int w = adj[u][i];
			if( pai[w] == -1 ) pai[w] = u;
			q.push( ii( w, c+1 ));
		}
	}
	return -1;
}

void back( int ini ){
	int x = 1;
	vector < int > V;
	while( x != ini ){
		V.pb(x);
		x = pai[x];
	}
	reverse( all( V ) );
	rep( i, 0, V.size() ){
		if( i ) printf("\n");
		Print( v[ V[i] ].S );
	}
}

int main(){
	pre_comp();
	string s1, s2, s3;
	while( cin >> s1 ){
		cin >> s2 >> s3;
		int ans = bfs( mp[ s1+s2+s3 ] );
		if( ans == -1 ){
			printf("Problema sem solucao\n");
			continue;
		}
		printf("Quantidade minima de passos = %d\n", ans );
		back( mp[ s1+s2+s3 ] );
	}
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


