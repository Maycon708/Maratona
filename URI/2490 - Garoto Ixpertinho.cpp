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

int pai[1111];

typedef pair<int,int> ii;

void init( int v ){
	for( int i = 0; i <= v; i++ )
		pai[i] = i; 
}
	
int findset( int i ){
	if( i != pai[i] ) 
		pai[i] = findset(pai[i]);
	return pai[i];
}
 
void unionset( int a, int b ){
	int aa = findset(a); 
	int bb = findset(b);
	pai[bb] = aa; 
}

bool sameset( int a, int b ){
	return findset(a) == findset(b);
}

int main(){
	int n, m, a, b;
	double d, c;
	while( scanf("%d%d%lf", &n, &m, &d ) != EOF && n ){
		init(n);
		priority_queue< pair<double, ii> > pq;
		while( m-- ){
			scanf("%d%d%lf", &a, &b, &c );
			pq.push( mk( -c, ii( a, b ) ));
		}
		double S = 0;
		int cnt = 0;
		while( !pq.empty() ){
			int u = pq.top().S.F;
			int v = pq.top().S.S;
			double c = -pq.top().F;
			pq.pop();
			if( sameset( u, v ) ) continue;
			if( c > d ) cnt++, S += 2;
			S += c;
			unionset( u, v );
		}
		printf("%.2f %d\n", S, cnt );
	}
}

