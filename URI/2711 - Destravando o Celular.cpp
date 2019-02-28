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

struct Triple{ 
	long long d,x,y;
	Triple( long long q, long long w, long long e ):d(q),x(w),y(e){} 
}; 

Triple egcd( long long a, long long b ){ 
	if(!b) return Triple(a,1,0); 
	Triple q = egcd(b,a%b); 
	return Triple(q.d,q.y,q.x-a/b*q.y); 
}

long long invMod( long long a, long long n){ 
	Triple t = egcd(a,n); 
	if(t.d>1) return 0; 
	return(t.x%n+n)%n; 
}

ll bsgs( ll b, ll n, ll p ){ 
	if( n == 1 ) return 0; 
	map<ll,int>table; 
	ll m = sqrt(p)+1, pot = 1, pot2 = 1; 
	for( int j = 0; j < m; ++j ){ 
		if( pot == n ) return j; 
		table[(n*invMod(pot,p))%p] = j; 
		pot = (pot*b)%p; 
	} 
	for( int i = 0; i < m; ++i ){ 
		if( table.find(pot2) != table.end() ) 
			return i*m+table[pot2]; 
		pot2 = (pot*pot2)%p; 
	} 
	return-1; 
}

int main(){
	ll b, n, m;
	while( scanf("%lld%lld%lld", &b, &n, &m ) != EOF ){
		printf("%lld\n", bsgs(b, n, m ) );
	}
}
