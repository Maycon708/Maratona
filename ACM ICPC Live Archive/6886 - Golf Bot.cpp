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
typedef complex<double> comp;

#define PI  2*acos(0)
#define MAX_N  1000000

int rev[MAX_N];
comp roots[MAX_N];
		
void preCalc(int N, int BASE){
    for (int i = 1; i < N; ++i) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (BASE - 1));
    int NN = N >> 1;
    roots[NN] = comp(1, 0);
    roots[NN + 1] = comp(cos(2 * PI / N), sin(2 * PI / N));
    for (int i = 2; i < NN; ++i) roots[NN + i] = roots[NN + i - 1] * roots[NN + 1];
    for (int i = NN - 1; i > 0; --i) roots[i] = roots[2 * i];

}
void fft( vector<comp> &a, bool invert ){
	int N = a.size();
	if (invert) rep(i, 0, N) a[i] = conj(a[i]);
    rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < N; k *= 2){
        for (int i = 0; i < N; i += 2 * k){
            rep(j, 0, k){
                comp B = a[i + j + k] * roots[k + j];
                a[i + j + k] = a[i + j] - B;
                a[i + j] = a[i + j] + B;
            }
        }
    } 
    if(invert) rep(i, 0, a.size()) a[i] /= N;
}

vector<comp> multiply_real( vector<comp>& a, vector<comp> c ){
	int n = a.size();
	int m = a.size();

	int base = 0, N = 1;
	while (N < n+m-1) base++, N <<= 1;
	preCalc(N, base);

	a.resize(N, comp(0,0));
	c.resize(N);
	rep( i, 0, a.size() ) a[i] = comp( real(a[i]), real(a[i]) );
	fft(a, 0);
	rep( i, 0, N ) {
		int j = (N - i) & (N - 1);
        c[i] = (a[i] * a[i] - conj(a[j] * a[j])) * comp(0, -0.25);
	}
	fft(c, 1);
	return c;
}


void corrige( vector<comp>& v ){
	rep( i, 0, v.size() ){
		v[i] = comp( fabs( real( v[i] ) ) > 1e-3, 0 );
	}
}

		
int main() {
	
	int n, k, u[200020];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, MAX_N ) rev[i] = 0, roots[i] = comp(0,0); 
		vector<comp> a, ans;
		a.clear(), ans.clear();
		int maior = 0;
		rep( i, 0, n ){
			scanf("%d", &u[i] );
			maior = max( maior, u[i]+10 );
		}
		
		a.resize( maior );
		rep( i, 0, a.size() ) a[i] = comp( 0, 0 );
		a[0] = comp( 1, 0 );
		
		rep( i, 0, n ) a[u[i]] = comp( 1, 0 );
		ans = multiply_real( a, ans );
		corrige(ans);
		scanf("%d", &n );
		
		int cnt = 0;
		rep( i, 0, n ){
			scanf("%d", &k );
			if( ans.size() > k && real( ans[k] ) == 1  ) cnt++;
		}
		printf("%d\n", cnt );
	}
	 
}
