#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	
	
	int n;
	
	while( scanf("%d", &n ) != EOF && n ){
		int v[1000];
		set<int> st;
		rep( i, 0, n ){
			scanf("%d", &v[i] );	
			st.insert(v[i]);
		}
		if( st.size() != n ){
			printf("No solution\n");
			continue;
		}
		int troca = 0;
		vector<int> ans;
		do{
			int id = 0; troca = 0;
			rep( i, 0, n ) if( v[i] != i+1 ){ id = i+1; break; }
			for( int i = n-1; i >= id; i-- ){
				if( v[i] == id ){
					swap( v[i], v[i-1] );
					troca = 1;
					ans.pb(i);
				}
			}
		}while( troca );
		
		printf("%d", ans.size() );
		rep( i, 0, ans.size() ) printf(" %d", ans[i] );
		printf("\n");
		
	}
	
	
	
}
