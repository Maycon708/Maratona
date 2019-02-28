#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;


#define gc getchar

void scanint( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ); c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

int pai[10010];

void init(int v){
    for( int i = 0; i <= v; i++ )
        pai[i] = i;
}

int findset( int i ){ 
    if (i != pai[i] ) 
        pai[i] = findset( pai[i] );
    return pai[i];
}
 
void unionset(int a, int b){
    int aa = findset(a); 
    int bb = findset(b);
    pai[bb] = aa;
}

bool sameset(int a, int b){
    return findset(a) == findset(b); 
}

int main(){
	int n, m, u, v, c;
	while( 42 ){
		scanint(n), scanint(m);
		if( !n ) break; 
		
		priority_queue< pair<int, ii> > pq, pq2;
		
		for( int i = m; i > 0; i-- ){
			scanint(u), scanint(v), scanint(c);
			pq.push( mk( -c, ii( u, v ) ) );
			pq2.push( mk(  c, ii( u, v ) ) );
		}
		int a = 0, b = 0;
		int cnt = 1;
		init(n);
		while( !pq.empty() ){
			if( cnt == n ) break;
			
			int u = pq.top().S.F, v = pq.top().S.S;
			int c = -pq.top().F; pq.pop();
			
			if( !sameset( u, v ) ){
				a += c;
				unionset( u, v );
				cnt++;
			} 
		}
		cnt = 1;
		init(n);
		while( !pq2.empty() ){
			if( cnt == n ) break;
			
			int u = pq2.top().S.F, v = pq2.top().S.S;
			int c = pq2.top().F; pq2.pop();
			
			if( !sameset( u, v ) ){
				b += c;
				unionset( u, v );
				cnt++;
			} 
		}
		printf("%d\n", b - a );		
	}
}

