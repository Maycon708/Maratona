#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<map>
 
using namespace std;  
 
int main(){
     
    map<int, char> mp;
	 
    int n, aux, aux1;
    char s[51], p[51];
	
	cin >> n;  	
    while(n--){
    	aux=0; aux1=1;
    	cin >> p >> s;
    	
    	for(int i=0; i<strlen(p); i++){
    		mp[aux]=p[i];
    		aux+=2;
		}
		for(int i=0; i<strlen(s); i++){
    		mp[aux1]=s[i];
    		aux1+=2;
		}
		
		for(int i=0; i<120; i++){
			if(mp[i])cout << mp[i];
		}
		cout << endl;
		mp.clear();
 	}
	
    return 0;
}
