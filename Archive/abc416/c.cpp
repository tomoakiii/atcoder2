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
    ll N,K,X; cin>>N>>K>>X;
    vector<string> S(N);
    rep(i,N) {
        cin>>S[i];
    }    
    vector<string> ans{};
    ll NK = 1;
    rep(i,K) NK*=N;
    rep(i, NK) {
        ll j = i;
        string t;
        rep(i,K) {
            t = t + S[j%N];
            j /= N;
        }
        ans.push_back(t);
    }
    sort(ans.begin(), ans.end());
    cout << ans[X-1] << endl;
    return 0;
}