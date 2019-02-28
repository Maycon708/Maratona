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

int id[10], n;
double a[10], b[10];

bool check( double t ){
	double last = a[id[0]];
	rep( i, 1, n ){
		double aux = last + t;
		if( aux <= b[id[i]] ) last = max( aux, a[id[i]] );
		else return 0;
	}
	return last <= b[id[n-1]];
}

int main(){
	int test = 1;
	while( scanf("%d", &n ) != EOF && n ){
		rep( i, 0, n ){
			cin >> a[i] >> b[i];
			a[i] *= 60, b[i] *= 60;
			id[i] = i;
		}
		
		double ans = -INF;
		do{
			double ini = 0, fim = 86400, mid;
			while(fabs(ini-fim) >= 1e-3 ){
				mid = ( ini+fim )/2;
				if( check(mid) ) ini = mid;
				else fim = mid;
			}
			ans = max( ans, mid );
		}while( next_permutation( id, id+n ) );
		ans = int( ans + .5 );
		printf("Case %d: %d:%02d\n", test++, (int)(ans/60), (int)ans%60 );
	}	
}

