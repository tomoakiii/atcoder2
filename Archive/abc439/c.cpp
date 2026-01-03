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
    vector<ll> mp(N+1);
    for(ll x = 1; ; x++) {
        if(x*x+x*x > N) break;
        for(ll y = x+1; ; y++) {
            if(x*x+y*y > N) break;
            mp[x*x+y*y]++;
        }
    }
    set<ll> st;
    rep(i,N+1) {
        if(mp[i] == 1) {
            st.insert(i);
        }
    }
    cout << st.size() << endl;
    for(auto s: st) {
        cout<<s<<" ";
    }
    cout << endl;
    return 0;
}