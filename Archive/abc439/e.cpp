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
typedef pair<ll, pair<ll,ll>> pll;
int main(){
    ll N;
    cin >> N;
//    vector<pair<ll,ll>> BA(N);
    map<ll,vector<ll>> mp;
    rep(i,N) {
        ll a,b; cin>>a>>b;
  //      BA[i].second = a;
  //      BA[i].first = b;
        mp[b].push_back(a);
    }
    vector<ll> A(N);
    int id = 0;
    for(auto [b, v]: mp) {
        auto v2 = v;
        sort(v2.rbegin(), v2.rend());
        for(auto k: v2){
            A[id++] = k;
        }
    }


    vector<int> uc(N), dc(N); // Count which order number each index is assigned
    vector<int> up, dn; // Storage table which number is temporally stored, like as dp
    rep(i,N) {
        auto it = lower_bound(up.begin(), up.end(), A[i]);
        if(it == up.end()) {
            up.push_back(A[i]);
            uc[i] = up.size();
        } else {
            *it = A[i];
            uc[i] = it - up.begin() + 1;
        }
    }
    int ans = 0;
    rep(i,N) {
        chmax(ans, uc[i]);
    }
    cout << ans << endl;
    return 0;
}