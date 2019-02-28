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

int mat[1111][1111], n, m, dx[] = {1, -1, 0, 0}, dy[] = { 0, 0, 1, -1 };
ii pai[1111][1111];

inline bool fora( int x, int y ){
	return x < 0 || x >= n || y < 0 || y >= m;
}

inline int C( ii a ){
	return mat[a.F][a.S];
}

inline bool cmp( ii a, ii b ){
	return C(a) > C(b);
}

ii findset(ii i){ 
    if(i != pai[i.F][i.S]) 
        pai[i.F][i.S] = findset(pai[i.F][i.S]);
    return ( pai[i.F][i.S] == i ) ? i : ( pai[i.F][i.S] = findset(pai[i.F][i.S]));
}
  
void unionset(ii a, ii b){
    ii aa = findset(a); 
    ii bb = findset(b);
    pai[bb.F][bb.S] = aa; 
}
 
bool sameset(ii a, ii b){
    return findset(a) == findset(b); 
}

int main(){
	int z, q, t[100010];
	scanf("%d", &z );
	while( z-- ){
		vector<ii> v;
		vector<int> aux;
		scanf("%d%d", &n, &m );
		for( int i = 0; i < n; i++ ){
			for( int j = 0; j < m; j++ ){
				scanf("%d", &mat[i][j] );
				v.pb( ii( i, j ) );
				pai[i][j] = ii( i, j );
			}
		}
		scanf("%d", &q );
		int ans = 0, id = 0;
		for( int i = 0; i < q; i++ ){
			scanf("%d", &t[i] );
		}
		sort( all(v), cmp );
		reverse( t, t+q );
		for( int i = 0; i < q; i++ ){
			for( ; id < (int)v.size() && C(v[id]) > t[i]; id++ ){
				ans++;
				for( int j = 0; j < 4; j++ ){
					int x = v[id].F + dx[j], y = v[id].S + dy[j];
					if( fora( x, y ) || C(ii(x, y) ) < C(v[id]) ) continue;
					if( !sameset( ii(x,y), v[id] ) ){
						ans--;
						unionset( ii(x,y), v[id] );
					}
				}
			}
			aux.pb(ans);
		}
		reverse( all(aux) );
		for( int i = 0; i < (int)aux.size(); i++ ) printf("%d ", aux[i] );
		printf("\n");
	}
}
