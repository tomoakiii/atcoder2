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
    rep(i,N) cin>>A[i];
    int deg = 0;
    set<int> st;
    st.insert(0);
    rep(i,N) {
        deg += A[i];
        deg %= 360;
        st.insert(deg);
    }
    int ls = 0, mx = 0;
    for(auto s: st) {
        chmax(mx, s - ls);
        ls = s;
    }
    chmax(mx, 360-ls);
    cout<<mx<<endl;
    return 0;
}