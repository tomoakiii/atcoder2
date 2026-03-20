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
    ll N,K;
    cin >> N >> K;
    ll T=0, A=0;
    rep(i,N) {
        ll a; cin>>a;
        if(T+a <= K) T+=a;
        else A+=a;
    }
    if(A>T) cout<<"Aoki"<<endl;
    else if(T>A) cout<<"Takahashi"<<endl;
    else cout<<"Draw"<<endl;
    return 0;
}