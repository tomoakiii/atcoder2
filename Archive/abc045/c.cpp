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
    string S;
    cin>>S;
    const int N = S.size() - 1;
    ll ans = 0;
    rep(k, 1<<N) {
        vector<ll> sm(1);
        sm[0] = S[0]-'0';
        rep(i,N) {
            if(k >> i & 1) {
                sm.push_back(S[i+1]-'0');
            } else {
                sm[sm.size()-1] = 10*sm[sm.size()-1]+S[i+1]-'0';
            }
        }
        ll t;
        for(auto s: sm) ans += s;
    }
    cout << ans << endl;
    return 0;
}