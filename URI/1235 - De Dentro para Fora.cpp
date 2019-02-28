#include<iostream>
#include<cstring>
 
using namespace std;
 
int main(){
    int t1, t2, n;
    char s[200], r[200], t[200];
 
    cin >> n;
    cin.ignore();
     
    while(n--){
        gets(s);
         
        t1=strlen(s);
        t2=t1/2;
                 
        for(int i=0; i<t2; i++){
            r[i]=s[t2-i-1];
        }
        
        for(int i=0; i<=t1; i++){
            t[i]=s[t1-i-1];
        }
        t[t1+1]='\0';
        
        for(int i=t2; i<t1; i++){
        	r[i] = t[i-t2];
        }
		
		r[t1]='\0';
         
        cout << r << endl;
    }
    return(0);
}
