#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<b; i++)
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}

const int M = 100010, N = 50005;

struct Q{
    int x, y, id;
    Q(){};
    Q( int _x, int _y, int _z ){
    	x = _x, y = _y, id = _z;
	}
};
 
Q q[M];
int bSize, ans[M], n;
int v[N], bit[N];
deque<int> dq;

void update( int x, int v ){
    while( x <= n ){
        bit[x] = bit[x] + v;
        x = x + ( x & -x );
    }
}
int query( int x ){
    int ans = 0;
    while(x > 0){
        ans = ans + bit[x];
        x = x - (x&-x);
    }
    return ans;
}
 
bool cmp(Q a, Q b){
    if( a.x / bSize != b.x / bSize )
        return a.x / bSize < b.x / bSize;
    return a.y < b.y;
}

vector<int> adj[N];

void dfs( int u, int c ){
	if( v[u] ) return;
	v[u] = c;
	rep( i, 0, adj[u].size() ){
		int w = adj[u][i];
		dfs( w, min( c, w ) );
	}
}

int bb1( int t ){
	int a = 1, b = n, c;
	while( a < b ){
		c = ( a + b ) >> 1;
		int x = query(c) << 1;
		if( x >= t ) b = c;
		else a = c + 1;
	}
	while( b > 1 && query(b-1) == query(b) ) b--;
	return b;
}


int bb2( int t ){
	int a = 1, b = n, c;
	while( a < b ){
		c = ( a + b + 1 ) >> 1;
		int x = query(c) << 1;
		if( x <= t ) a = c;
		else b = c - 1;
	}
	while( a > 1 && query(a-1) == query(a) ) a--;
	return a;
}

#define gc getchar//_unlocked

void scan( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}
 
int main(){
	int m, a, b, u;
	while( 42 ){
		scan(n), scan(m);
		if( !n ) break;
		
		bSize = sqrt(n);
		rep( i, 0, n+1 ) adj[i].clear(), v[i] = bit[i] = 0;
		rep( i, 1, n+1 ) scan( u ), adj[u].push_back(i);
		
		rep( i, 0, m ){
			scan(a), scan(b);
			q[i] = Q( a, b, i );
		}
		rep( i, 1, n+1 ) if( !v[i] ) dfs(i, i);
		sort( q, q+m, cmp );
		int l = 1, r = 1;
            
        rep( i, 0, m ){
            int L = q[i].x;
            int R = q[i].y;
            
            if( i && L == q[i-1].x && R == q[i-1].y ){
            	ans[q[i].id] = ans[q[i-1].id];
				continue; 
			}
            
            while( r <= R ) update( v[r++], 1 );
            while( l < L ) update( v[l++], -1 );
            while( l > L ) update( v[--l], 1 );
            while( r > R+1 ) update( v[--r], -1 );
            
            int t = R - L + 1;
            int a = bb1(t);
            int b = bb2(t);
            if( abs( t - ( query(a) << 1 ) ) < abs( t - ( query(b) << 1 ) ) ) ans[q[i].id] = a;
            else ans[q[i].id] = b;
        }
        rep( i, 0, m ){
        	printf("%d\n", ans[i] );
		}
	}
    return 0;
}
