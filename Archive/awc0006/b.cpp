#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N,K,T;
    cin >> N >> K >> T;
    ll sm = 0;
    rep(i,N) {
        ll d,r; cin>>d>>r;
        if(r>=d*K) sm+=r;
    }
    if(sm>=T) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}