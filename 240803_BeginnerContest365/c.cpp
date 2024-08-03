#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    
    ll mx = 0;
    rep(i, N) {
        cin >> A[i];        
        mx = max(A[i], mx);
    }
    
    auto f = [&](ll x) -> bool {
        ll sm = 0;
        rep(i, N){
            sm += min(x, A[i]);
        }        
        return sm<=M;
    };

    if (f(INF)) {
        cout << "infinite" << endl;
        return 0;
    }

    ll ok = 0, ng = mx;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (f(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}