#include <bits/stdc++.h>

#define rep(i, a, b) for(int i=a; i<b; i++)

typedef long long int ll;
using namespace std;

int main(){
	int N; cin >> N;
	ll mat[N][N];
	
	ll sum=0, l, c;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> mat[i][j];
			if(mat[i][j]==0) l=i, c=j;
		}	
	}
	if(N==1){
		printf("1\n");
		return 0;
	}
	if(l==0) rep(j, 0, N) sum+=mat[1][j];
	else rep(j, 0, N) sum+=mat[0][j];
//	cout << sum << endl;
	
	ll sl=0;
	rep(j, 0, N) sl+=mat[l][j];
	mat[l][c]=sum-sl;
	
	if(mat[l][c]<=0){
		printf("-1\n");
		return 0;
	}
	
	
//	cout << mat[l][c] << endl;
	
	rep(i, 0, N){
		ll aux=0;
		rep(j, 0, N){
			aux+=mat[i][j];
		}
		if(aux!=sum){
			printf("-1\n");
			return 0;
		}
	}
	rep(j, 0, N){
		ll aux=0;
		rep(i, 0, N){
			aux+=mat[i][j];
		}
		if(aux!=sum){
			printf("-1\n");
			return 0;
		}
	}
	ll aux=0;
	rep(i, 0, N){
		aux+=mat[i][i];
	}
	if(aux!=sum){
		printf("-1\n");
		return 0;
	}
	aux=0;
	rep(i, 0, N){
		int j=N-i-1;
		aux+=mat[i][j];
	}
	if(aux!=sum){
		printf("-1\n");
		return 0;
	}
	printf("%lld\n", mat[l][c]);
	
	
return 0;
}