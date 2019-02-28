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

typedef long long int ll;
typedef pair <ll, ll> ii;

/*
	t = ( B2 - B1 ) / ( A1 - A2 )					---			equação em r
	t = ( D1 - D2 +- k * 360 ) / ( C2 - C1 )		--- 		equação em theta
*/

ll a1, a2, b1, b2, c1, c2, d1, d2; 

ii reduz( ii a ){
	int gcd = __gcd( a.F, a.S );
	return ii( a.F/gcd, a.S/gcd );
}

ii solucao_em_theta(){
//	debug("theta")
	bool possivel = 1;
	d1 = ( ( d1%360 ) + 360 )%360;
	d2 = ( ( d2%360 ) + 360 )%360;
	ll num = d2 - d1;
	ll den = c1 - c2;
	if( den < 0 ) den *= -1, num *= -1;
	if( num < 0 ) num = ( (num%360) + 360 )%360;
	if( !den ) return ii( (!num) ? 0 : INF, 1 );
	else if( !num ) return ii( 0, 1 );
	else return reduz( ii( num, den ) );
}

ii solucao_em_r(){
	ll num = b2 - b1;
	ll den = a1 - a2;
	if( !den ){
		if( !num ) return solucao_em_theta();
		else return ii( INF, 1 );
	}
	else if( !num ) return ii( 0, 1 );
	else if( num * den > 0 ){
		num = abs(num), den = abs(den);
		ll theta1 = c1 * num + d1 * den;
		ll theta2 = c2 * num + d2 * den;
		if( ( a1 * num + b1 * den != 0 ) && ( theta1 - theta2 )%( 360*den ) != 0 ) return ii( INF, 1 ); 
	}
	else return ii( INF, 1 );
	return reduz( ii( num, den ) );
}

ii menor( ii a, ii b ){
	if( a.F * b.S > a.S * b.F ) return b;
	return a;
}

int main(){
//	freopen("higgs.in", "r", stdin );
	while( scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a1, &b1, &c1, &d1, &a2, &b2, &c2, &d2 ) != EOF ){
		if( !a1 && !b1 && !c1 && !d1 && !a2 && !b2 && !c2 && !d2 ) break;
		
		ii ans = solucao_em_r();
		a2 *= -1, b2 *= -1, d2 += 180;
		ans = menor( ans, solucao_em_r() );
		
		if( ans.F == INF ) puts("0 0");
		else printf("%lld %lld\n", ans.F, ans.S );
	}
}

