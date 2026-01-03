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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
    }

    ll ans = 0;
    rep(kkk, 2){
        map<ll,vector<int>> mp;
        rep(i,N) {
            mp[A[i]].push_back(i);
        }
        rep(i,N) {
            ll a = A[i];
            if(a % 5 != 0) continue;
            ll t3 = a / 5 * 3;
            ll t7 = a / 5 * 7;
            if(!mp.contains(t3) || !mp.contains(t7)) continue;
            int j3 = lower_bound(mp[t3].begin(), mp[t3].end(), i) - mp[t3].begin();
            int j7 = lower_bound(mp[t7].begin(), mp[t7].end(), i) - mp[t7].begin();
            ans += (mp[t3].size() - j3) * (mp[t7].size() - j7);
        }
        reverse(A.begin(),A.end());
    }
    cout << ans << endl;
    return 0;
}