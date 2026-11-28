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
vector<pair<ll, int>> encode(vector<ll> str) {
    int n = (int)str.size();
    vector<pair<ll, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ans = 1;
    auto ret = encode(A);
    reverse(ret.begin(), ret.end());
    unordered_map<ll,ll> mp;
    ll sm = 0;
    for(auto [r,c]:ret){
        ans += c * (sm - mp[r]);
        mp[r]++;
        sm++;
    }
    cout << ans << endl;
    return 0;
}