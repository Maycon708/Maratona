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

int check( ll n ){
	while(n){
		if( n%10 == 1 ) n /= 10;
		else if( n%100 == 14 ) n /= 100;
		else if( n%1000 == 144 ) n /= 1000;
		else return 0;
	}
	return 1;
}

int main(){
	ll n;
	while( cin >> n ){
		if( check(n) ) puts("YES");
		else puts("NO");
	}
}

