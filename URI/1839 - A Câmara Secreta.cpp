#include<bits/stdc++.h>

#define rep(i,a,b) for(int i = a; i < b; i++)

using namespace std;

const int MAX_N = 10000;
const int mod = 1000000007;

int C[MAX_N][MAX_N];

void calc_pascal(){
	memset(C, 0, sizeof(C));
	for(int i = 0; i < MAX_N; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j) C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
	}
}

int main(){
	
	calc_pascal();
	
	int n, m, a, b, c, d;
	char s[60][60];
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> s[i][j];
	
	while(cin >> a >> b >> c >> d){
		int cont = 0, cont1 = 0;
		for(int i=a-1; i<c; i++)
			for(int j=b-1; j<d; j++){
				if(s[i][j]=='#') cont++;
				cont1++;
			}
		cout << C[cont1][cont]-1 << endl;
	}
	
	
	
	return 0;
}
