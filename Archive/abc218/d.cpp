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
    vector<ll> X(N), Y(N);
    set<pair<ll,ll>> st;
    rep(i,N) {
        ll x,y;
        cin>>x>>y;
        X[i] = x, Y[i] = y;
        st.insert({x,y});
    }
    int ans = 0;
    rep(i,N) {
        rep(j,N) {
            if(Y[i] < Y[j] && X[i] < X[j]) {
                if(st.contains({X[j], Y[i]}) && st.contains({X[i], Y[j]}) ) ans++;
            }            
        }
    }
    cout<<ans<<endl;
    return 0;
}