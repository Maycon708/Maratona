#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	vector<int> v1;
	vector<int> v2;
    map <int, bool> mp1;
    map <int, bool> mp2;
    map <int, int> mp;
     
    int a, b, x, cont1, cont2;
     
    cin >> a >> b;
     
    while(a!=0 || b!=0){
        for(int i=0; i<a; i++){
            cin >> x;
         	if(!mp1[x]) v1.push_back(x);
            mp1[x]=true;
            
        }
        for(int i=0; i<b; i++){
            cin >> x;
     		if(!mp2[x]) v2.push_back(x);
            mp2[x]=true;
        }
        
        mp1.clear();
        mp2.clear();
        if(v1.size()>v2.size()){
        	for(int i=0; i<v2.size(); i++) mp[v2[i]]++;
        	
        	for(int i=0; i<v1.size(); i++) if(mp[v1[i]]!=0) mp[v1[i]]++;
        }
        else{
        	for(int i=0; i<v1.size(); i++) mp[v1[i]]++;
        	
        	for(int i=0; i<v2.size(); i++) if(mp[v2[i]]!=0) mp[v2[i]]++;
        }
        
        int cont=0;
        
        for(int i=0; i<100001; i++) if(mp[i]==1) {
       
			cont++;
        }
        
        cout<<cont<<endl;
        
        mp.clear();
        v1.clear();
        v2.clear();
        
        cin >> a >> b;
    }
     
    return 0;
}
