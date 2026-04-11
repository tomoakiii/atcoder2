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
typedef modint998244353 mint;
int main(){
    ll N,M;
    cin >> N >> M;
    set<ll> st;
    mint ans=1;
    rep(i,N) {
        int a; cin>>a;
        if(a==0) ans*=M;
        else st.insert(a);
    }
    rep(i,st.size()) {
        ans *= M-i;
    }
    cout<<ans.val()<<endl;
    return 0;
}