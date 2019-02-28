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

int main(){
	// ( x-1 ) ( y-1 ) + xy = z
	// 	   xy -x -y +1 + xy = z		
	// 		  2xy -x -y + 1 = z
	// 				2xy - x = z + y -1
	// 
	ll n;
	while( cin >> n ){
		int cnt = 0;
		rep( i, 2, sqrt(n)+1 ){
			int a = 2 * i - 1;
			int b = n + i - 1;
			if( b%a == 0 && i <= b/a ) cnt++;
		}
		printf("%d\n", cnt );
	}
	
}

