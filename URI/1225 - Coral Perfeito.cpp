#include <bits/stdc++.h>
      
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pf push_front
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM(x,l,c) { rep( i, 0, l ){ rep(j, 0, c ) cout << x[i][j] << " ";  cout << "\n"; }};
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair
      
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
      
using namespace std;
      
typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){

	int n, v[101010];

	while( scanf("%d", &n ) != EOF ){
		
		int media = 0, cont = 0;
		rep( i, 0, n ){
			scanf("%d", &v[i] );
			media += v[i];
		}
		if( media%n ) printf("-1\n");
		else{		
			media /= n;
	    	rep( i, 0, n )
	    		if( media > v[i] ) cont += ( media - v[i] );
	        printf("%d\n", cont+1 );
	    }
	}
}
