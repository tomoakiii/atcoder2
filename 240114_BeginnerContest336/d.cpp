#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N, 0);
    for(auto &a:A){
        cin >> a;
    }
    int c, d=1;
    vector<long long> top1(N, 0), top2(N, 0);
    top1[0] = 1;
    for (int i=1; i<N; i++){
        top1[i] = min(A[i], top1[i-1]+1);
    }
    top2[N-1] = 1;
    for (int i=N-2; i>=1; i--){
        top2[i] = min(A[i], top2[i+1]+1);
    }
    long long m = 0;
    for (int i=0; i<N; i++){
        m = max(m, min(top1[i], top2[i]));
    }
    
    cout << m << endl;
    return 0;
}

