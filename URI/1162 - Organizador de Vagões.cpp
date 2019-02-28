#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, l, v[55];
	
	scanf("%d", &n);
	
	while(n--){
		int cont=0;
		scanf("%d", &l);
		for(int i=0; i<l; i++) scanf("%d", &v[i]);
		
		for(int i=l-1; i>=1; i--){
			for(int j=0; j<i; j++){
				if(v[j]>v[j+1]){
					int aux=v[j];
					v[j]=v[j+1];
					v[j+1]=aux;
					cont++;
				}
			}
			
		}
		printf("Optimal train swapping takes %d swaps.\n", cont);
	}
}
