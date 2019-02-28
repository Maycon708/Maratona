#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
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

struct aluno{
	string name;
	int n;
	bool operator < ( aluno q ) const {
		if( n != q.n ) return n < q.n;
		return name > q.name;
	}
};

int main(){
	int n, t = 1;
	aluno a[111];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			cin >> a[i].name >> a[i].n;
		}
		sort( a, a+n );
		printf("Instancia %d\n", t++ );
		cout << a[0].name << "\n";
		printf("\n");
	}	
}
