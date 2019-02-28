#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define N 200200

using namespace std;

typedef long long int ll;

int v[N], esq[N], dir[N], mx;
int main(){
	int n;
	cin >> n;
	rep( i, 0, n ){
		scanf("%d", &v[i] );
		mx = max( mx, v[i]);
	}
	esq[0] = -1;
	rep( i, 1, n ){
		esq[i] = i-1;
		while( esq[i] >= 0 && v[i] >= v[esq[i]] )
			esq[i] = esq[esq[i]];
	}  
	dir[n-1] = n;
	for( int i = n-2; i >= 0; i-- ){
		dir[i] = i+1;
		while( dir[i] < n && v[i] >= v[ dir[i] ] )
			dir[i] = dir[dir[i]];
	}
	bool check = true;
	rep( i, 0, n ){
		if( v[i] == mx ) continue;
		if( (dir[i]-esq[i]+1)&1 ) check = 0;
	}
	puts( check? "YES":"NO" );
}

