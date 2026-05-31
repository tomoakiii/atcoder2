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

ll mygcd(ll x, ll y){
    if(x < y) swap(x, y);
    if(y == 0) return x;
    ll k = x%y;
    return gcd(y, k);
}


int main(){
    ll N;
    cin >> N;

    set<ll> st;
    ll g; cin >> g;
    rep(i,N-1) {
        ll a; cin>>a;
        st.insert(a);
        g = mygcd(a, g);
    }
    cout << g << endl;
    return 0;
}