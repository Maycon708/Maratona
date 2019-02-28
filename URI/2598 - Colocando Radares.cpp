#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, ans, t;
    scanf("%d", &t );
    while( scanf("%d%d", &n, &ans ) != EOF ){
        printf("%d\n", ( n+ans-1 )/ans );
    }
}
