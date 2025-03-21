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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> p{};
    map<ll, vector<pair<ll,int>>> mp;
    rep(i, Q) {
        ll r, x;
        cin >> r >> x;
        r--;
        mp[r].push_back({x, i});
    }
    auto m = mp.begin();
    // ll y = 0;
    vector<ll> ans(Q);
    rep(i,N) {
        auto it = lower_bound(p.begin(), p.end(), A[i]);
        if(it == p.end()) {
            p.push_back(A[i]);
        } else {
            *it = A[i];
        }                      
        if(m->first == i) {
            for(auto [x, ind] : m->second) {
                auto it2 = lower_bound(p.begin(), p.end(), x);
                if(it2 == p.end()) {
                    ans[ind] = p.size();
                } else if (*it2 == x) {
                    ans[ind] = it2 - p.begin() + 1;
                } else {
                    ans[ind] = it2 - p.begin();
                }
            }
            m++;
        }
        if(m == mp.end()) break;
    }
    rep(i, Q) {
        cout << ans[i] << endl;
    }
    return 0;
}