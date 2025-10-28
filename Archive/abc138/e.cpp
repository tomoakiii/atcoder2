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
    string S, T; cin>>S>>T;
    vector pos('z'-'a'+1, vector<ll>{});
    rep(i,S.size()) {
        int c = S[i] - 'a';
        pos[c].push_back(i);
    }
    ll last = -1;
    ll ans = 0;
    for(auto t: T) {
        int j = t - 'a';
        if(pos[j].empty()) {
            cout<<-1<<endl;
            return 0;
        }
        auto it = lower_bound(pos[j].begin(), pos[j].end(), last+1);
        if(it == pos[j].end()) {
            it = lower_bound(pos[j].begin(), pos[j].end(), 0);
            ans += S.size();
        }
        last = *it;
    }
    cout << ans + last + 1 << endl;
    return 0;
}