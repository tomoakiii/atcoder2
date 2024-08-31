#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N, 0);
    rep(i, N) {
        cin >> A[i];        
    }
    rep(i,N) {
        cout << A[(N-K+i)%N] << " ";
    }    
    cout <<  endl;
    return 0;
}