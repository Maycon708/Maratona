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

	int k, cnt[30];
	string s;
	while( scanf("%d", &k ) != EOF ){
		cin >> s;
		memset( cnt, 0, sizeof cnt );
		rep( i, 0, s.size() ){
			cnt[ s[i] - 'a' ]++;
		}
		bool aux = 1;
		string ans;
		rep( i, 0, 26 ){
			aux &= ( cnt[i]%k == 0 );
			rep( j, 0, cnt[i]/k ) ans += char('a'+i); 
		}
		if( !aux ) printf("-1\n");
		else{
			rep( i, 0, k ) printf("%s", ans.c_str() );
			printf("\n");
		}
	}
	
}

