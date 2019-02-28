#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){
	
	map < char, string > mp;
	mp['0'] = "10-01111";
	mp['1'] = "10-10111";
	mp['2'] = "10-11011";
	mp['3'] = "10-11101";
	mp['4'] = "10-11110";
	mp['5'] = "01-01111";
	mp['6'] = "01-10111";
	mp['7'] = "01-11011";
	mp['8'] = "01-11101";
	mp['9'] = "01-11110";
	string s, resp[10];
	while( cin >> s ){
		while( s.size() != 9 ) s = "0" + s;
		rep( i, 0, s.size() ){
			resp[i] = mp[ s[i] ];
		}
		rep( i, 0, 8 ){
			rep( j, 0, 9 ){
				printf("%c", resp[j][i] );
			}
			printf("\n");
		}
		printf("\n");
	}
	
}


