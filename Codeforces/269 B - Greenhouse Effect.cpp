#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int n, m, v[5005];
int pd[5005][5005];
double inutil[5005];

int solve( int i, int j ){
	if( i == n+1 ) return 0;
	int &ans = pd[i][j];
	if( ans == -1 ){
		ans = solve( i+1, j );
		if( v[i] >= v[j] ) ans = max( ans, solve( i+1, i ) + 1 );
	}
	return ans;
}

int main(){
	scanf("%d%d", &n, &m );
	rep( i, 1, n+1 ){
		scanf("%d%f", &v[i], &inutil[i] );
		rep( j, 0, n+1 ) pd[i][j] = -1;
	}
	cout << n - solve( 1, 0 ) << endl;
}

