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
	char t[1000];
	while( gets(t) ){
		int tam = strlen(t);
		double aux = 0;				
		stack<double> s, r;

		rep( i, 0, tam ){
			if( t[i] >= '0' && t[i] <= '9' ){
				aux *= 10;
				aux += t[i] - '0';
			}
			else if( t[i] == '-'){
				if(aux)s.push(aux); aux = 0;
				s.push(-1);
			}
			else if( t[i] == '|' ){
				if(aux)s.push(aux); aux = 0;
				s.push(-2);
			}
			else if( t[i] == '('){
				s.push(-3);
			}
			else{
				if(aux) s.push(aux); aux = 0;
				while( s.top() != -3 ){
					r.push(s.top());
					s.pop();
				}
				s.pop();
				aux = r.top(); r.pop();
				while( !r.empty() ){
					int op = r.top(); r.pop();
					double x = r.top(); r.pop();
					if( op == -1 ) aux += x;
					else aux = (aux*x)/(aux+x); 
				}
				s.push(aux); aux = 0;
			}
		}
		if( aux ) s.push(aux);
		while( !s.empty() ){
			r.push(s.top());
			s.pop();
		}
		aux = r.top(); r.pop();
		
		while( !r.empty() ){
			int op = r.top(); r.pop();
			double x = r.top(); r.pop();
			if( op == -1 ) aux += x;
			else aux = (aux*x)/(aux+x); 
		}
		printf("%.3f\n", aux );
	}
}
