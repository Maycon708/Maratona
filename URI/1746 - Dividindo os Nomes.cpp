#include <bits/stdc++.h>

#define INF 200*18+10
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

const int MAX = 200*18+10;

int sig[MAX][30], cnt, freq[MAX];
int R[MAX], down[MAX];
int pd[MAX][100];

void init(){
	cnt = 1;
	memset( freq,  0, sizeof freq );
	memset(  sig, -1, sizeof  sig );
	memset(   pd, -1, sizeof   pd );
}

void add( char* s ){
	int t = strlen(s), x = 0;
	rep( i, 0, t ){
		int c = s[i] - 'A';
		if( sig[x][c] == -1 ) sig[x][c] = cnt++;
		x = sig[x][c];
		freq[x]++;
	}
}

void calc(){
	for( int i = 0; i < cnt; i++ ){
		int last = -1;
		for( int j = 26; j >= 0; j-- ){
			if( sig[i][j] != -1 ){
				R[sig[i][j]] = last;
				last = sig[i][j];
			}
		}
		down[i] = last;
	}
}

int solve( int x, int st, int d ){
	int &ans = pd[x][st];
	if( ans == -1 ){
		ans = INF;
		for( int i = 0; i <= min( st, freq[x] ); i++ ){
			if( R[x] == -1 && i != st ) continue;
			int cur = 0;
			if( i == 1 ) cur += d;
			if( freq[x] - i == 1 ) cur += d;
			if( R[x] != -1 ) cur += solve( R[x], st-i, d );
			if( down[x] != -1 ){
				cur += solve(down[x], i, d+1);
				if( i == 1 ) cur -= d+1;
				if( freq[x] - i == 1 ) cur -= d+1;
			}
			ans = min( ans, cur );
		}
	}
	return ans;
}

int main(){
	
	int n;
	char s[20];
	
	while( scanf("%d", &n ) != EOF ){
		init();
		rep( i, 0, 2*n ){
			scanf("%s", s );
			add(s);
		}
		calc();
		printf("%d\n", n * solve( down[0], n, 1 ));
	}
	
}


