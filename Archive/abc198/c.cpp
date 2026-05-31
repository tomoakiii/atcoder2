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
    ll R, X, Y; cin>>R>>X>>Y;
    ll T = X*X+Y*Y;
    ll Q = sqrtl(T);
    if(R*R == T) cout<<1<<endl;
    else if(R*R > T) cout<<2<<endl;
    else if(Q*Q == T) cout << (Q+R-1)/R << endl;
    else cout<<1+Q/R<<endl;
    return 0;
}