#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	string s;
	while( cin >> s ){
		int cnt = 0;
		if( s.find("Danil") != s.npos ){
			size_t found = s.find("Danil");
			cnt++;
			if( s.find("Danil", found+1, 5) != s.npos) cnt++;
		}
		if( s.find("Olya") != s.npos ){
			size_t found = s.find("Olya");
			cnt++;
			if( s.find("Olya", found+1, 4) != s.npos) cnt++;
		}
		if( s.find("Slava") != s.npos ){
			size_t found = s.find("Slava");
			cnt++;
			if( s.find("Slava", found+1, 5)!= s.npos ) cnt++;
		}
		if( s.find("Ann") != s.npos ){
			size_t found = s.find("Ann");
			cnt++;
			if( s.find("Ann", found+1, 3)!= s.npos ) cnt++;
		}
		if( s.find("Nikita") != s.npos ){
			size_t found = s.find("Nikita");
			cnt++;
			if( s.find("Nikita", found+1, 6)!= s.npos ) cnt++;
		}
		printf("%s\n", cnt == 1 ? "YES" : "NO"); 
	}
}