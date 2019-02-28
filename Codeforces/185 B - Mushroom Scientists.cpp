#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

int main(){
	double s, a, b, c;
	cin >> s >> a >> b >> c;
	if( fabs(a+b+c) < 1e-9 ) printf("%.10f 0 0\n", s ); 
	else printf("%.10f %.10f %.10f\n", a*s/(a+b+c), b*s/(a+b+c), c*s/(a+b+c) );
}

