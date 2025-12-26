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
    set<ll> st;
    st.insert(0);
    rep(i,N){
        ll a; cin>>a;
        set<ll> st2;
        st2.insert(0);
        for(auto s:st) {
            st2.insert(s+a);
            st2.insert(s);
        }
        swap(st, st2);
    }
    ll ans = 0;
    for(auto s : st) {
        if(s % 10 != 0) chmax(ans, s);
    }
    cout << ans << endl;
    return 0;
}