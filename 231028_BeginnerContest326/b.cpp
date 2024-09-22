#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int main()
{
    int N;
    cin >> N;
    for (int n = N; n < 1000; n++){
        int ncopy = n;
        int a = ncopy/100;
        ncopy-= a*100;
        int b = ncopy/10;
        ncopy-= b*10;
        if (a * b == ncopy){
            cout << n << endl;
            return 0;
        } 
    }
    return 0;
}