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

double pd[1010][1010];
int memo[1010][1010], cnt, t;

double solve( int w, int b ){
	if( !w ) return 0;
	if( memo[w][b] == cnt ) return pd[w][b];
	memo[w][b] = cnt;
	double &ans = pd[w][b];
	int turn = t - w - b;
	if( turn%3 ==  0 ){
		ans = (double)w/(w+b);
		if(b) ans += (double)b/(w+b) * solve( w, b-1 );
	}
	else{
		ans = 0;
		if( b > 1 ) ans += (double)b/(w+b) * (double)(b-1)/(w+b-1) * solve(w, b-2);
		if( w && b ) ans += (double)b/(w+b) * (double)w/(w+b-1) * solve(w-1, b-1);
	} 
	return ans;
}

int main(){
	int a, b;
	while( scanf("%d%d", &a, &b ) != EOF ){
		t = a+b;
		cnt++;
		printf("%.10f\n", solve(a, b) );
	}
}
