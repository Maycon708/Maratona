#include<bits/stdc++.h>
	
using namespace std;

long long int n, v[100000], total;
    
vector <string> vec;

long long int solve(long long int ini, long long int fim){
	
	// cout << ini << " " << fim << endl;
	
	
	long long int t1=0, t2=0;
	
	long long int mid = (fim+ini)/2;
	long long int k=1;
	
	for(int i=mid; i>=0; i--){
		
		// cout << vec[i] << v[i] * k << endl;
		
		t1+=v[i]*k;
		k++;
	}
	
	k=1;
	
	for(int i=mid+1; i<n; i++){
		
		//cout << vec[i] << v[i] * k << endl;
		
		t2+=v[i]*k;
		k++;
	}
	
	//cout << t1 << " " << t2 << endl;
	
	if(t1==t2) return mid;
	else{
		if(fim-ini<=1) return -1;
		if(t1>t2) solve(ini,mid);
		else solve(mid,fim);
	}
	
	
}


int main(){
    
    char c[20];
    
    while(cin >> n && n){
    	
		total=0;
    	
		for( int k=0; k<n; k++ ){
    		
			v[k]=0;
    		
			cin >> c;
			
			vec.push_back(c);
			
			int t=strlen(c);
			
			for(int i=0; i<t; i++){
				v[k]+=c[i];
			}
    	
		}
		
	
		
		long long int aux = solve(0, n-1);
		
		if(aux==-1) cout << "Impossibilidade de empate." << endl;
    	else cout << vec[aux] << endl;
    	
    	vec.clear();
    	
	}
	
     
    return 0;
}
