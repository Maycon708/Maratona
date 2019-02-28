#include<iostream>
#include<cctype>
#include<stdlib.h>
#include<cstring>
#include<map>

using namespace std;

map<int, int> mp;
map<int, int> :: iterator iterator;

int main(){
	
	int t, n, l, r;
	string s, d;
	
	cin >> t;
	
	while(t--){
		r=0;
		cin >> n;
		
		for(int i=0; i<n; i++){
		
			cin >> s;
			
			if(s=="RIGHT"){
				r+=1;
				mp[i]=1;
			}
			else{
				if(s=="LEFT"){
					r+=-1;
					mp[i]=-1;
				}
				else{
					cin>> d >> l;
					r+=mp[l-1];
					mp[i]=mp[l-1];
					
				}
				
			}
		}
		
		cout << r << endl;
	}
	
	
	return(0);
}
