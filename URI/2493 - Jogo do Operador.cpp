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
	ll a[60], b[60], c[60], id, n;
	string nome;
	char op;
	while( scanf("%lld", &n ) != EOF ){
		vector<string> w;
		rep( i, 0, n ){
			scanf("%lld %lld=%lld", &a[i], &b[i], &c[i] );
		}
		rep( i, 0, n ){
			cin >> nome >> id >> op;
			id--;
			switch(op){
				case '+':
					if( a[id] + b[id] != c[id] ) w.pb(nome);
					break;
				case '-':
					if( a[id] - b[id] != c[id] ) w.pb(nome);
					break;
				case '*':
					if( a[id] * b[id] != c[id] ) w.pb(nome);
					break;
				case 'I':
					if( a[id] + b[id] == c[id] ) w.pb(nome);
					else if( a[id] - b[id] == c[id] ) w.pb(nome);
					else if( a[id] * b[id] == c[id] ) w.pb(nome);
					break;
			}
		}
		if( w.empty() ) printf("You Shall All Pass!\n");
		else if( w.size() == n ) printf("None Shall Pass!\n");
		else{
			sort( all(w) );
			rep( i, 0, w.size() ){
				if( i ) printf(" ");
				printf("%s", w[i].c_str() );
			}
			printf("\n");
		}
	}
}

