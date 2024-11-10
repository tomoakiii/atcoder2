#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, S, K;
    cin >> N >> S >> K;
    long asum = 0;
    for(int n=1;n<=N;n++){
        int P, Q;
        cin >> P >> Q;
        asum += P * Q;
    }
    if (asum < S){
        asum += K;
    }
    cout << asum << endl;
    return 0;
}