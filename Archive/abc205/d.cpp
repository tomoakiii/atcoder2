#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
    }
    sort(A.begin(), A.end());
    vector<pair<ll,ll>> P;
    P.push_back({(ll)2E18 - N, 2E18});
    for(int i=N-1; i>=0; i--){
        auto [x, c] = P[P.size()-1];
        if(c == A[i]) {
            P[P.size()-1] = {x, c-1};
        } else {
            ll x2 = x - (c-A[i]);
            P.push_back({x2, A[i]-1});
        }        
    }    
    P.push_back({0, 0});
    reverse(P.begin(), P.end());
    while(Q--){
        ll tgt; cin >> tgt;
        pair<ll,ll> p = {tgt,0};
        int id = lower_bound(P.begin(), P.end(), p) - P.begin();        
        cout << P[id].second - (P[id].first - tgt) << endl;        
    }
    return 0;
}