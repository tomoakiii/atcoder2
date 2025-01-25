#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int p = N/100;
    N -= p*100;
    printf("%.2d\n", N);
    return 0;
}