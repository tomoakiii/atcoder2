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
    ll S,A,B,X;cin>>S>>A>>B>>X;
    ll ans = S*A * (X/(A+B));
    X %= (A+B);
    if(X <= A) cout<<ans + S*X<<endl;
    else cout<<ans +  S*A<<endl;
    return 0;
}