#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
typedef long long ll;
int main(){
    ll K;
    cin >> K;    
    ll ans = 0;
    set<vector<ll>> st;
    for(ll p = 1; (p-1) * (p-1) * (p-1) <= K; p++) {
        if(K%p == 0) {
            ll K2 = K/p;
            for(ll q = 1; (q-1) * (q-1) <= K2; q++) {
                if(K2%q == 0) {
                    vector<ll> v(3);
                    v[0] = p, v[1] = q, v[2] = K2/q;
                    sort(v.begin(), v.end());
                    st.insert(v);
                }
            }
        }
    }
    cout << st.size() << endl;
    return 0;
}