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
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;

char mat[1505][1505];
int cont[1505][1505];
ii v[1505505], best;

bool cmp( ii a, ii b ){
	if( a.F != b.F ) return a.F > b.F;
	return a.S > b.S;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m );
	rep( i, 0, n ) scanf("%s", mat[i] );
	rep( j, 0, m ){
		int tmp = 0;
		rep( i, 0, n ){
			if( mat[i][j] == '#' ) tmp = 0;
			else tmp++;
			cont[i][j] = tmp;
		}
	}
	int id = 0;
	rep( i, 0, n ){
		stack<ii> s;
		rep( j, 0, m ){
			int l = j;
			while( !s.empty() && cont[i][j] < s.top().F ){
				ii x = s.top();
				s.pop();
				v[id] = ii( j-x.S, x.F );
				if( v[id].F > v[id].S ) swap( v[id].F, v[id].S );
				if( v[id].F ) id++;
				l = x.S;
			}
			if( s.empty() || cont[i][j] > s.top().F )
				s.push(ii(cont[i][j], l));
		}
		while( !s.empty() ){
			ii x = s.top();
			s.pop();
			v[id] = ii( n-x.S, x.F );
			if( v[id].F > v[id].S ) swap( v[id].F, v[id].S );
			if( v[id].F ) id++;
		}
	}
//	rep( i, 0, id ) debug2( v[i].F, v[i].S );
	sort( v, v+id, cmp );
	int tmp = 0;
	rep( i, 0, id ){
		if(!i || v[i].S > v[tmp-1].S ) v[tmp++] = v[i];
	}
	reverse( v, v+tmp );
	int q, ans = 0;
	scanf("%d", &q );
	while( q-- ){
		int a, b;
		scanf("%d%d", &a, &b );
		int it = lower_bound(v, v+tmp, ii(a, 0)) - v;
		if( it != tmp && v[it].S >= b ){
			int area = a * b;
			if( ans < area || ( ans == area && b > best.S ) ){
				ans = area, best = ii( a, b );
			}
		}
		it = lower_bound(v, v+tmp, ii(b, 0)) - v;
		if( it != tmp && v[it].S >= a ){
			int area = a * b;
			if( ans < area || ( ans == area && b > best.S ) ){
				ans = area, best = ii( a, b );
			}
		}
		
	}
	printf("%d %d\n", best.F, best.S );
}
