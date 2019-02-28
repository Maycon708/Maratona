#include<iostream>
#include<algorithm>
#include<string.h>
 
using namespace std;
 
int main(){
     
    int n, m, p[100000], im[100000], contp, conti;
	
	cin >> n;
	contp=0; conti=0;
    	
    for(int i=0; i<n; i++){
    	
    	cin>> m;
    	
    	if(m%2==0){
    		p[contp]=m;
    		contp++;
		}
		else{
			im[conti]=m;
			conti++;
		}	
	}    
	
	sort(p, p+contp);
	sort(im, im+conti);
	
	for(int i=0; i<contp; i++){
		cout << p[i] << endl;
	}
	
	for(int i=conti-1; i>=0; i--){
		cout << im[i] << endl;
	}
	
    return 0;
}
