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

#define N 200010

int q, n, bit[N];

void update( int x, int v ){
	for( ; x <= n; x += x&-x ) bit[x] += v;
}

int query( int x ){
	int ans = 0;
	for( ; x > 0; x -= x&-x ) ans += bit[x];
	return ans;
}

int busca( set<int> &st, int k ){
	int i = k, j = n;
	while( i < j ){
		int mid = ( i + j ) >> 1;
		int p = query( mid );
		if( p < k ) i = mid+1;
		else j = mid;
	}
	return j;
}

int main(){
	
	int id[N];
	char op[N];
	
	while( scanf("%d", &q ) != EOF ){
		
		map<int, int> mp, mp2;
		map<int, int> :: iterator it;
		
		rep( i, 0, q ){
			scanf(" %c%d", &op[i], &id[i] );
			if( op[i] != 'K' ) mp[id[i]] = 1;
		}
		n = 1;
		for( it = mp.begin(); it != mp.end(); it++, n++ ) it -> S = n, mp2[n] = it -> F;
//		for( it = mp2.begin(); it != mp2.end(); it++ ) debug2( it->F, it-> S)
		set<int> st;
		int t = 0;
		rep( i, 0, q ){
			int p = mp[ id[i] ];
			
			if( op[i] == 'I' ) if( !st.count(p) ) st.insert(p), update( p, 1 );
			if( op[i] == 'D' ) if( st.count(p) ) st.erase( st.find(p) ), update( p, -1 );
			
			if( op[i] == 'C' ) printf("%d\n", query( p-1 ) );

			if( op[i] == 'K' ){
				if( id[i] > st.size() ) printf("invalid\n");
				else printf("%d\n", mp2[ busca( st, id[i] ) ] ); 
			}
		}
	}
}

