#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<map>
 
using namespace std;
 
int main(){
     
    int t, n, m;
                    
        
    map<int, int> mp;
    map<int, int> :: iterator it;
     
    cin >> t;
    
    while(t>0){
    
		cin >> n;
		
		while(n>0){
			
			cin>>m;
			
			mp[m] +=1;
			
			n--;
		}	
		
		cout << mp.size() << endl;
    	
    	mp.clear();
    	
    	t--;
	}
	      
}
