#include<bits/stdc++.h>

using namespace std;

map <char, double> mp;

int main(){
	
	mp['W']=1;
	mp['H']=1/2.0;
	mp['Q']=1/4.0;
	mp['E']=1/8.0;
	mp['S']=1/16.0;
	mp['T']=1/32.0;
	mp['X']=1/64.0;
	
	int r;
	double cont;
	char c[300];
	
	while(gets(c), c[0]!='*'){
		r=0;
		
		for(int i=0; i<strlen(c); i++){
			if(c[i]=='/'){
				if(cont==1) r++;
				cont=0;
			}
			cont+=mp[c[i]];
		}
		
		cout<<r<<endl;
		
	}
		
	
	return 0;
}
