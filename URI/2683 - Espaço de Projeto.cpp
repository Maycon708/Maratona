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

const int N = 2e6+500;
int pai[N];

void init(int v){
    for (int i = 0; i <= v; i++ )
        pai[i] = i;
}
 
int findset(int i){ 
    if ( i != pai[i] ) 
        pai[i] = findset(pai[i]);
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

int solve( pair<int, ii> a, int n = 0 ){
	
	int u = a.S.F + n;
	int v = a.S.S + n;
	int w = a.F;
	
	if( sameset( u, v ) ) return 0;
	unionset( u, v );
	return w;
}
 

int main(){

	int n, m, u, v, c;
	
	while( scanf("%d", &n ) != EOF ){
		
		init(2*n);
		vector< pair< int, ii > > pq;
		while( scanf("%d%d%d", &u, &v, &c ) != EOF && u+v+c ){
			pq.pb( mk( c, ii( u, v ) ) );
		}
		sort( all(pq) );
		int mn = 0, mr = 0, t = pq.size()-1;
		rep( i, 0, pq.size() ){
			mn += solve( pq[i] );
			mr += solve( pq[t-i], n );
		}
		printf("%d\n%d\n", mr, mn );		
	}
	
}
