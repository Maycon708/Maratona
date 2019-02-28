#include<bits/stdc++.h>

using namespace std;

int main(){
	char c[60];
	int p;
	
	while(gets(c)){
		double cont=0;
		int t=0;
		cin>>p;
		cin.ignore();
		
		for(int i=0; i<strlen(c); i++){
			if(c[i]=='R')cont++;
			else{
				t+=ceil(cont/p);
				t++;
				cont=0;
			}
		}
		t+=ceil(cont/p);
		cout<<t<<endl;
	}
	
}
