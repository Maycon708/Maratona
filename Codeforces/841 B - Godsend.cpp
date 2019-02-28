#include <bits/stdc++.h>

#define INF 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 200010

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){
	int n, a, sum;
	while( scanf("%d", &n ) != EOF ){
		sum = 0;
		rep( i, 0, n ){
			scanf("%d", &a );
			if( a&1 ) sum = 1;
		}
		if( sum ) puts("First");
		else puts("Second");
	}
	
}
