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

	int t, aux[] = { 5, 3, 4, 1, 2, 0 }; 
	char s[10];
	
	scanf("%d", &t );
	while( t-- ){
		rep( i, 0, 6 ){
			scanf(" %c", &s[i] );
		}
		int ans = 1, cnt = 0;
		rep( i, 0, 6 ){
			if( s[aux[i]] == '*' && s[i] == '*' ) cnt++;
		}
		while( cnt ) ans *= cnt, cnt -= 2;
		printf("%d\n", ans );
	}	

}
