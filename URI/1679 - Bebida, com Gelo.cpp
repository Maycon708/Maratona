#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

int main(){
	
	double m_w, m_i, t_w, t_i, cw = 4.19, ci = 2.09, em = 335.0;
	while( scanf("%lf%lf%lf%lf", &m_w, &m_i, &t_w, &t_i ) != EOF ){
		if ( m_w == 0.0 && m_i == 0.0 && t_w == 0.0 && t_i == 0.0) break;
		double e_w = cw * m_w * t_w;
		double e_i = ci * m_i * -t_i;
		if( e_w <= e_i ){
			e_i -= e_w;
			t_w = 0;
			t_i = ( -e_i )/ ( ci * m_i );
			e_w = em * m_w;
			if( e_w <= e_i ){
				e_i -= e_w;
				t_i = ( -e_i )/( ci * m_i );
				t_i = m_i * t_i / ( m_i + m_w );
				m_i += m_w;
				m_w = 0;
			}
			else{
				t_i = 0;
				m_w -= e_i/ em;
				m_i += e_i/ em;
			}
		}
		else{
			e_w -= e_i;
			t_i = 0;
			t_w = ( e_w )/ ( cw * m_w );
			e_i = em * m_i;
			if( e_w <= e_i ){
				t_w = 0;
				m_i -= e_w/ em;
				m_w += e_w/ em;
			}
			else{
				e_w -= e_i;
				t_w = ( e_w )/( cw * m_w );
				t_w = m_w * t_w / ( m_w + m_i );
				m_w += m_i;
				m_i = 0;
			}
		}
		printf("%.1f g of ice and %.1f g of water at %.1f C\n", m_i, m_w, t_i + t_w );
	}

}

ll readInt () {
    bool minus = false;
    ll result = 0; char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}

