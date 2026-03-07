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
    multiset<ll> st;
    rep(i,N) {
        ll a; cin>>a;
        st.insert(a);
    }
    ll ans = 0;
    bool flg = false;
    ll nx;
    while(!st.empty()) {
        if(!flg) {
            nx = *st.begin();
            st.erase(st.begin());
            flg = true;
            ans++;
        } else {
            if(st.contains(nx+1)){
                st.erase(st.find(nx+1));
                nx++;
            } else {
                flg = false;
            }
        }
    }
    cout << ans << endl;
    return 0;
}