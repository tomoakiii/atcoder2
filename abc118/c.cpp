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
    rep(i,N) {
        ll a; cin>>a;
        st.insert(a);
    }

    while(true) {
        set<ll> st2;
        ll p = *st.begin();
        for(auto s:st) {
            if(s%p != 0) st2.insert(s%p);
        }
        if(st2.empty() || *st2.begin() == *st.begin()) {
            cout<<p<<endl;
            return 0;
        }
        swap(st,st2);
    }
    return 0;
}