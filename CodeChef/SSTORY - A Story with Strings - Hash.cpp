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
#define NN 250010
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef unsigned long long int ll;
typedef pair <ll, ll> ii;

const ll x = 37; 
//num. primo > que o maior caracter de S.

ll H[NN][2], X[NN];
string s1, s2;	
int n, m;

ll V(char c){ return c-'a'; }

ll my_hash(int i, int j, int id){
	ll ret = H[j][id];
	if(!i) return ret;
	return ret-(H[i-1][id]*X[j-i+1]);
}

void precompute(string s, int id){
	X[0] = 1;
	rep(i, 1, NN)
		X[i] = (X[i-1]*x);
	H[0][id] = V(s[0]);
	rep(i, 1, s.size())
		H[i][id] = ((H[i-1][id]*x) + V(s[i]));
}

int id;

bool C( int t ){
	set<ll> st;
	rep( i, 0, n-t+1 ) st.insert( my_hash(i, i+t-1, 0) );
	rep( i, 0, m-t+1 ){
		ll x = my_hash( i, i+t-1, 1 );
		if( st.count(x) ){
			id = i;
			return 1;
		}
	}	
	return 0;
}

int main(){
	
	
	cin >> s1 >> s2;
	n = s1.size(), m = s2.size();
	precompute( s1, 0 );
	precompute( s2, 1 );
	
	int lo = 0, hi = min( n, m ), mid, ans;
	while( lo <= hi ){
		mid = ( lo + hi +1 )/2;
		if( C(mid) ) ans = mid, lo = mid+1;
		else hi = mid-1;
	}
	cout << s2.substr( id, ans ) << endl << ans << endl;
 
}

