#include <bits/stdc++.h>

using namespace std;

int main(){

    int a;
    float b;
    char c;
    char d[60];

    scanf("%d", &a);
    scanf("%f", &b);
    cin >> c;
    cin.ignore();
	gets(d);

    printf("%d%.6f%c%s\n", a, b, c, d );
    printf("%d\t%.6f\t%c\t%s\n", a, b, c, d );
    printf("%10d%10.6f%10c%10s\n", a, b, c, d );

    return 0;
}

