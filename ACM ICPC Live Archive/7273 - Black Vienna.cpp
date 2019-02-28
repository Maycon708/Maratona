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
#define Z 53
#define N 26
#define MAXV 120

int c, n;
vector <int> adj[MAXV];
int num[MAXV];
int low[MAXV];
int scc[MAXV];
stack <int> s;
map <string, int > mp;
 
int inSt[MAXV];
int nDfs, nScc, k, x, y, ss, t;

int F( int x ){
	return 2 * x;
} 
int T( int x ){
	return F(x)+1;
}
 
void addEdge(int x, bool bx, int y, bool by ) { // (x || y )
	int a, b , c, d;
	if (bx)   a = F(x) , d = T(x);
	else      a = T(x) , d = F(x);
	if (by)   c = F(y) , b = T(y);
	else      c = T(y) , b = F(y);
	adj[a].pb(b); 
	adj[c].pb(d);
}
 
void tarjanScc(int v) {
    num[v] = low[v] = nDfs++;
    s.push(v), inSt[v] = true;
    rep(i, 0, adj[v].size()){
        int w = adj[v][i];
        if( num[w] == -1 ){
            tarjanScc(w);
            low[v] = min ( low[v], low[w] );
        }
        else
            if( inSt[w] )
                low[v] = min ( low[v], low[w] );
    }
    if( low[v] == num[v]){
        int t;
        do {
            t = s.top();
            inSt[t] = false;
            scc[t] = nScc;
            s.pop();
        }while( t != v );
        nScc++;
    }
}

int C( int p, int s ){
	return p * 26 + s;
}
	         
void init(){
    rep(i, 0, MAXV){
        adj[i].clear();
        num[i] = -1;
        low[i] = -1;
        inSt[i] = false;
    }
    while(!s.empty()) s.pop();
    nDfs = nScc = 0;
}

int p[MAXV], card[MAXV][2], ans[MAXV];

int check( int a, int b, int c ){
	init();
	addEdge( Z, 0, Z, 0 );
	for( int i = 1; i <= N; i++ ){
		if( i == a || i == b || i == c ) continue;
		addEdge( C(0,i), 1, C(1, i), 1 );
		addEdge( C(0,i), 0, C(1, i), 0 );
	}
	rep( i, 0, 2 ){
		addEdge( C(i, a), 0, Z, 1 );
		addEdge( C(i, b), 0, Z, 1 );
		addEdge( C(i, c), 0, Z, 1 );
	}
	
	rep( i, 0, n ){
		if( ans[i] == 0 ){
			addEdge( C( p[i], card[i][0] ), 0, Z, 1 );
			addEdge( C( p[i], card[i][1] ), 0, Z, 1 );
		}
		else if( ans[i] == 2 ){
			addEdge( C( p[i], card[i][0] ), 1, Z, 1 );
			addEdge( C( p[i], card[i][1] ), 1, Z, 1 );
		}
		else{
			addEdge( C( p[i], card[i][0] ), 1, C( p[i], card[i][1] ), 1 );
			addEdge( C( p[i], card[i][0] ), 0, C( p[i], card[i][1] ), 0 );
		}
	}
	rep( i, 2, 108 )
        if( num[i] == -1 ) tarjanScc(i);
    rep( i, 1, Z ){
        if( scc[T(i)] == scc[F(i)] ) return 0;
    }
   	return 1;
}
 
int main(){
	
	string s;	
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			cin >> s >> p[i] >> ans[i];
			p[i]--;
			card[i][0] = s[0] - 'A' + 1;
			card[i][1] = s[1] - 'A' + 1;
		}
		int resp = 0;
		rep( i, 1, 27 )
			rep( j, i+1, 27 )
				rep( k, j+1, 27 )
					resp += check( i, j, k );
		printf("%d\n", resp );
	}			
}

