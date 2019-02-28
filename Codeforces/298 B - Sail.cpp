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
	int t, sx, sy, ex, ey;
	char s[100010];
	while( scanf("%d%d%d%d%d", &t, &sx, &sy, &ex, &ey ) != EOF ){
		scanf("%s", s );
		int ans = -1;
		rep( i, 0, t ){
			if( s[i] == 'W' && sx > ex ) sx--;
			if( s[i] == 'E' && sx < ex ) sx++;
			if( s[i] == 'S' && sy > ey ) sy--;
			if( s[i] == 'N' && sy < ey ) sy++;
			if( sx == ex && sy == ey ){
				ans = i+1;
				break;	
			}	
		}
		printf("%d\n", ans );
	}
}
