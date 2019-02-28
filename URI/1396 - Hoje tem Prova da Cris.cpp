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
	
	int n, k, u[110], t = 1;
	string s;
	while( cin >>  n >> k ){
		if( !n && !k ) break; 
		vector < string > aux, ans;
		rep( i, 0, n ){
			cin >> s;
			aux.pb( s );
			u[i] = 1;
		}
		int ini = 0;
		while( k && ini < n ){
			s = ""; int cnt = 0, pos, cust, i = ini;
			while( cnt <= k && i < n ){
				if( ( s == "" || aux[i] < s ) && u[i] ) s = aux[i], pos = i, cust = cnt;
				cnt += u[i];
				i++;
			}
			ans.pb( aux[pos] );
			k -= cust;
			u[pos] = 0;
			while( !u[ini] && ini < n ) ini++;
		}
		rep( i, 0, aux.size() ) if( u[i] ) ans.pb( aux[i] );
		printf("Instancia %d\n", t++ );
		rep( i, 0, ans.size() ){
			printf("%s ", ans[i].c_str() );
		}
		printf("\n\n");
	}


}


