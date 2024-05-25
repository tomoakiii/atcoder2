#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;
int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) {
        ll a;
        cin >> a;
        A[i] = a;
    }        
    
    auto A3 = A;
    for(int i=1; i<N; i++){
        A3[i] += A3[i-1];
    }
    
    ll K = N-1;
    mint ans = 0;
    for(int i=N-1; i>=1; i--){
        ans += K * A[i];
        K--;
        ll f = 1;
        while (f <= A[i]){
            f*=10;
        }
        mint t = A3[i-1];
        t *= f;
        ans += t;
    }
    
    cout << ans.val() << endl;
    return 0;
}