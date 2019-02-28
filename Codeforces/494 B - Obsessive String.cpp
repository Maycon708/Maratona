#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define N 100100

using namespace std;

typedef long long int ll;

const int mod = 1e9+7;

string p, t;
int P[N], q[N], a[N], q1[N], q2[N];


void kmp(){
	
	P[0] = -1;
	rep( i, 1, p.size()  ){
		P[i] = P[i-1];
		while( P[i] >= 0 && p[P[i]+1] != p[i] ) P[i] = P[P[i]];
		if( p[P[i]+1] == p[i] ) P[i]++;
	}
	
	int x = -1;
	rep( i, 0, t.size() ){
		while( x >= 0 && t[i] != p[x+1] ) x = P[x];
		if( p[x+1] == t[i] ) x++;
		q[i+1] = x+1 == p.size();
	}		
}

int main(){
	int sz;
	ll ans = 0;
	cin >> t >> p;
	kmp();
	
	sz = p.size();
	a[0] = q1[0] = q2[0] = 0;
	rep( i, 1, t.size()+1 ){
		if( q[i] ) a[i] = ( q2[i-sz] + i-sz+1 )%mod;
		else a[i] = a[i-1];
		q1[i] = ( q1[i-1] + a[i] )%mod;
		q2[i] = ( q2[i-1] + q1[i] )%mod;
		ans = ( ans + a[i] ) %mod;
	}
	
	cout << ans << "\n";
}

