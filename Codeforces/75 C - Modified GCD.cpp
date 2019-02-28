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

bitset<10000005> bs;  
vector<int> primos;
ll limite = 100000;
 
void crivo(){  
    bs.set(); 
    bs[0] = bs[1] = 0;
    for( ll i = 2; i < limite; i++ )
        if ( bs[i] ){
            for( ll j = i*i; j < limite; j += i)
                bs[j] = 0;
            primos.push_back(i);
        }
}


vector<int> p, e, divisor;

int fatora(int N){
	int PF, idx = 0;
	PF = primos[idx++];
	while( N > 1 && PF * PF <= N ){
		if( N % PF == 0 ){
			p.push_back(PF);
			e.push_back(0);
			while( N % PF == 0 ){
				e[e.size()-1] ++;
				N /= PF;
			}
		}
		PF = primos[idx++];
	}
	if( N > 1 ){
	  p.push_back(N);
	  e.push_back(1);
	}
	return p.size();
}

void divisores(int i, int qt, int D) {
	if (i == qt){
		divisor.push_back(D);
		return;
	}

	for (int k=0; k <= e[i]; k++) {
		divisores(i+1, qt, D);
		D *= p[i];
	}
}

int main(){
	crivo();
	int a, b, q, r, l;
	while( scanf("%d%d", &a, &b ) != EOF ){
		fatora( __gcd(a,b) );
		divisores( 0, p.size(), 1 );
		sort( all( divisor ) );
		scanf("%d", &q );
		while( q-- ){
			scanf("%d%d", &r, &l );
			vector<int> :: iterator p = upper_bound( all(divisor), l );
			--p;
			if( *p < r ) printf("-1\n");
			else printf("%d\n", *p );
		}
	}
}	

