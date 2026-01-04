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
    unordered_set<ll> st;
    ll mx = 0;
    rep(i,N) {
        ll a; cin>>a;
        st.insert(a);
        chmax(mx,a);
    }
    auto st2 = st;
    for(auto s: st2){
        if(!st.contains(s)) continue;
        ll x = s;
        while(x <= mx) {
            x*=2;
            if(st.contains(x)) st.erase(x);
        }
    }
    cout<<st.size()<<endl;
    return 0;
}