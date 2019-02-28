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

bool cmp( int a, int b ){
	return a > b;
}

void erase( vector<int> &v, int c ){
	for( int i = v.size()-1; i >= 0; i-- ){
		if( v[i]%3 == c ){
			v.erase( v.begin()+i );
			return;
		}
	}
}

int main(){
	int n, r, cnt[3];
	while( scanf("%d", &n ) != EOF ){
		vector<int> v(n);
		rep( i, 0, 3 ) cnt[i] = 0;
		bool aux = 0;
		int sum = 0;
		rep( i, 0, n ){
			scanf("%d", &v[i] );
			sum += v[i];
			cnt[v[i]%3]++;
			if( v[i] == 0 ) aux = 1;
		}
		if( aux ){
			sort( all(v), cmp );
			if( sum%3 == 1 ){
				if( cnt[1] ) erase(v, 1);
				else{
					erase(v, 2);
					erase(v, 2);
				}
			}
			else if( sum%3 == 2 ){
				if( cnt[2] ) erase(v, 2);
				else{
					erase(v, 1);
					erase(v, 1);
				}
			}
			aux = 0;
			rep( i, 0, v.size() ) aux |= ( v[i] != 0 );
			if( aux ){
				rep( i, 0, v.size() ) printf("%d", v[i] );
				printf("\n");
			} 
			else puts("0");
		}
		else puts("-1");
	}
}
