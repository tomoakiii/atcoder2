#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    for (auto &a:A) cin >> a;
    sort(A.begin(), A.end());
    auto it = lower_bound(A.begin(), A.end(), K);
    ll id = distance(A.begin(), it);
    ll sum1 = 0;
    ll lastA = -1;
    for(int i=0; i<N; i++){
        if (A[i]  == lastA) continue;
        lastA = A[i];
        if (A[i] <= K){
            sum1 += A[i];
        } else {
            break;
        }
    }

    ll sum;
    if (K%2 == 0) {
        sum = K/2;
        sum *= (K+1);        
    } else {
        sum = (K+1)/2;
        sum *= K;
    }

    cout << sum-sum1 << endl;
    return 0;
}