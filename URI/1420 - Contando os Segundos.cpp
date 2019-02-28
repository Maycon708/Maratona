#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 100005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair < int, ll >  ii;

bool bissexto(int ano){
	return ano%400 == 0 || ( ano%4 == 0 && ano%100 != 0 );
}

int mes_n[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mes_b[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int C( string aux, int i, int j ){
	int resp = 0;
	rep( k, i, j ){
		resp *= 10;
		resp += ( aux[k] - '0' );
	}
	return resp;
}

int main(){

	string s[] = { "", "JAN", "FEV", "MAR", "ABR", "MAI", "JUN", "JUL", "AGO", "SET", "OUT", "NOV", "DEZ" };
	string ss[] = {"DOM",  "SEG", "TER", "QUA", "QUI", "SEX", "SAB" };
	int D1, M1, A1, h1, m1, s1, t = 1, D0, M0, A0, h0, m0, s0;
	char dd[30], mm[30], lixo;
	map<string, int> mp;
	string in;
	
	rep( i, 0, 13 ) mp[ s[i] ] = i;
	rep( i, 0, 7 ) mp[ ss[i] ] = i;

	freopen( "in.txt", "r", stdin );	
	while( cin >> in ){
		if( in == "FIM" ) break;
		
		dd[0] = in[0], dd[1] = in[1], dd[2] = in[2], dd[3] = '\0'; 
		D0 = C( in, 4, 6 ); 
		mm[0] = in[6], mm[1] = in[7], mm[2] = in[8], mm[3] = '\0';  
		A0 = C( in, 9, 13 );
		h0 = C( in, 14, 16 );
		m0 = C( in, 17, 19 );
		s0 = C( in, 20, 22 );		
		
		
		printf("Previsao #%d\n", t++ );
		M0 = mp[mm];
		rep( i, 0, 5 ){
			D1 = D0, M1 = M0, A1 = A0, h1 = h0, m1 = m0, s1 = s0;
			ll cont;
			scanf("%lld", &cont );
			int a = cont%86400;
			int cnt = mp[dd];
			while( a-- ){
				s1++;
				if( s1 >= 60 ) s1 -= 60, m1++;
				if( m1 >= 60 ) m1 -= 60, h1++;
				if( h1 >= 24 ) h1 -= 24, D1++, cnt++;
				if( bissexto(A1) ){ 
					if( D1 > mes_b[M1] ) D1 -= mes_b[M1], M1++ ;
				}
				else if( D1 > mes_n[M1] ) D1 -= mes_n[M1], M1++;
				if( M1 > 12 ) M1 -= 12, A1++;
			}
			
			cont /= 86400;
			cnt += cont;
			while( cont-- ){
				D1++;
				if( bissexto(A1) ){ 
					if( D1 > mes_b[M1] ) D1 -= mes_b[M1], M1++; 
				}
				else if( D1 > mes_n[M1] ) D1 -= mes_n[M1], M1++;
				if( M1 > 12 ) M1 -= 12, A1++;
			}
			cnt %= 7;
			printf("%s,%02d%s%d:%02d:%02d:%02d\n", ss[cnt].c_str(), D1, s[M1].c_str(), A1, h1, m1, s1 );
		}
	}
}

