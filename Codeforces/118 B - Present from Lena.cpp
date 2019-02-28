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
	
	int n, cnt;
	while( scanf("%d", &n ) != EOF ){
		cnt = 0;
		bool d = 1;
		rep( i, 0, 2*n+1 ){
			rep( j, 0, 2*(n-cnt) ) printf(" ");
			rep( j, 0, cnt+1 ) printf("%s%d", (j)? " " : "",  j );
			for( int j = cnt-1; j >= 0; j-- ) printf(" %d", j );
			printf("\n");
			if( d ) cnt++;
			else cnt--;
			if( cnt == n ) d = 0;
		}
	}
	
}

