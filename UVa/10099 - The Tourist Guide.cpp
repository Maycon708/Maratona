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

int pai[111];

void init( int v ){
    for( int i = 0; i <= v; i++ )
        pai[i] = i;
}
 
int findset( int i ){
    if( i != pai[i] ) 
        pai[i] = findset( pai[i] );
    return pai[i];
}
  
void unionset( int a, int b ){
    int aa = findset(a); 
    int bb = findset(b);
    pai[bb] = aa;
}
 
bool sameset( int a, int b ){
    return findset(a) == findset(b); 
}

int main(){
	int n, m, u, v, c, s, d, t, test = 1;
	while( scanf("%d%d", &n, &m ) != EOF && n ){
		priority_queue< pair<int, ii> > pq;
		init( n+1 );
		while( m-- ){
			scanf("%d%d%d", &u, &v, &c );
			pq.push( mk( c, ii( u, v ) ) );
		}
		scanf("%d%d%d", &s, &d, &t );
		int lower;
		while( !pq.empty() && !sameset(s, d) ){
			u = pq.top().S.F;
			v = pq.top().S.S;
			c = pq.top().F;
			pq.pop();
			lower = c;
			if( !sameset(u, v) ){
				unionset( u, v );
			}
		}
		lower--;
		printf("Scenario #%d\n", test++ );
		printf("Minimum Number of Trips = %d\n\n", t/lower + ( t%lower != 0 ) );
	}
}
