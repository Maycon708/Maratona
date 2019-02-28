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

struct aluno{
	string nome;
	int p[20], total;
	void scan(){
		cin >> nome;
		rep( i, 0, 12 ) cin >> p[i];
		sort( p, p+12 );
		total = 0;
		rep( i, 1, 11 ) total += p[i];
	}
	bool operator < ( aluno A ) const{
		if( total != A.total ) return total > A.total;
		return nome < A.nome;
	}
};

int main(){
	int n, t = 1;
	aluno v[10001];
	while( cin >> n && n ){
		rep( i, 0, n ) v[i].scan();
		sort( v, v+n );
		int last = -1, id;
		printf("Teste %d\n", t++ );
		rep( i, 0, n ){
			if( v[i].total != last ) id = i+1, last = v[i].total;
			cout << id << " " << v[i].total << " " << v[i].nome << "\n";
		}
		printf("\n");
	}
}

