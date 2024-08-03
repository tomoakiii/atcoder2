#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector dp(N+1, vector<ll>(2));
    vector<ll> A(N), B(N);
    rep(i, N) {
        cin >> A[i];
    }
    rep(i, N) {
        cin >> B[i];
    }

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    
    rep(i, N) {
        
    }

    
    cout << sm << endl;
    return 0;
}