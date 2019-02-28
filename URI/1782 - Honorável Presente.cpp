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

#define MAXV 100001
 
int pai[MAXV];
ll p[MAXV];
ll resp[MAXV];

void init(int v){
    for( int i=1; i <= v; i++ )
        pai[i] = i, p[i] = 1; 
}
 
int findset(int i){ 
    if( i != pai[i] ) 
        pai[i] = findset(pai[i]);
    return (pai[i]==i) ? i : (pai[i]=findset(pai[i]));
}
  
void unionset(int a, int b){
    int aa = findset(a); 
    int bb = findset(b);
    p[aa] += p[bb];
    p[bb] = p[aa];
    pai[bb] = aa; 
}
 
bool sameset(int a, int b){
    return findset(a) == findset(b); 
}

int main(){
	
	int t, test = 1, n, u, w, c, q;
	scanf("%d", &t );
	while( t-- ){
		priority_queue< pair<int, ii> > pq;
		scanf("%d", &n );
		init(n);
		rep( i, 1, n ){
			scanf("%d%d%d", &u, &w, &c );
			pq.push( mk(-c, ii(u, w)) );
		}
		scanf("%d", &q );
		vector<ii> v(q);
		rep( i, 0, q ) scanf("%d", &v[i].F ), v[i].S = i;
		sort( all(v) );
		ll ans = n;
		rep( i, 0, v.size() ){
			while( !pq.empty() ){
				int c = -pq.top().F;
				if( c > v[i].F ) break;
				u = pq.top().S.F, w = pq.top().S.S;
				pq.pop();
				if( !sameset(u,w) ){
					ans += p[findset(u)] * p[findset(w)];
					unionset(u,w);
				}
			}
			resp[v[i].S] = ans;
		}
		printf("Caso #%d:", test++ );
		rep( i, 0, q ) printf(" %lld", resp[i] );
		printf("\n");
	}
}
