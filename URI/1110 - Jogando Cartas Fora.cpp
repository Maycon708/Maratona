#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<queue>
  
using namespace std;
  
int main(){
      
    int t, v[50], i;
                     
    queue<int> q;	
      
    cin >> t;
     
    while(t!=0){
    	
    	for(i=1; i<=t; i++){
    		q.push(i);
		}
		
		cout << "Discarded cards: ";
		
		while(q.size()!=2){
			
			cout << q.front() << ", ";
			q.pop();
			q.push(q.front());
			q.pop();
		} 
		 	cout << q.front() << endl;
		 	q.pop();
		
	
		cout << "Remaining card: " << q.front() << endl;
		 
        cin >> t;
        
        q.pop();
       
    }
           
    return(0);
}
