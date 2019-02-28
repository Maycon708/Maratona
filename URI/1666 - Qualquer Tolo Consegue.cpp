#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

string s;

int pd[202][202], pd2[202][202];

int LIST( int i, int j );
int EL( int i, int j );

int SET( int i, int j ){
	if( s[i] != '{' || s[j] != '}' ) return 0;
	if( i+1 == j ) return 1;
	if( pd[i][j] != -1 ) return pd[i][j];
	return pd[i][j] = LIST(i+1, j-1);
}

int LIST( int i, int j ){
	if( pd2[i][j] != -1 ) return pd2[i][j];
	int ans = EL( i, j );
	rep( k, i+1, j ){
		if( s[k] == ',' )
			ans |= ( LIST( i, k-1 ) && LIST(k+1, j) );
	}
	return pd2[i][j] = ans;
}

int EL( int i, int j ){
	if( i == j ) return s[i] == '{' || s[i] == '}' || s[i] == ',';
	return SET( i, j );	
}

int main(){
	
	int t, word = 1;
	scanf("%d", &t );
	while( t-- ){
		cin >> s;
		rep( i, 0, s.size() ) rep( j, 0, s.size() ) pd[i][j] = pd2[i][j] = -1;
		printf("Word #%d: ", word++ );
		if( SET( 0, s.size()-1 ) ) puts("Set");
		else puts("No Set");
	}
	
	return 0;
}
