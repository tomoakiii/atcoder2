#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<long> A(K+2), sum1(K+2, 0), sum2(K+2, 0);

    for (int i=1;i<=K;i++){
        cin>>A[i];
    }
    A[0]=A[1]; A[K+1]=A[K];
    for (int i=1;i<=K;i++){
        if (i%2==0){
            sum1[i]=A[i]-A[i-1]+sum1[i-1];
        } else {
            sum1[i]=sum1[i-1];
        }
    }
    if (K%2==0){
        cout << sum1[K] << endl;
        return 0;
    }
    for (int i=K;i>=1;i--){
        if ((K-i)%2==1){
            sum2[i]=A[i+1]-A[i]+sum2[i+1];
        } else {
            sum2[i]=sum2[i+1];
        }
    }
    long gap=N;
    
    for (int i=1;i<=K;i+=2){
        gap = std::min(gap, sum1[i-1] + sum2[i+1]);
    }   
    cout << gap << endl;
    return 0;
}