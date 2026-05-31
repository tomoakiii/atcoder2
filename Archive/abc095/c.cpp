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
    ll A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    C*=2;
    ll ans = INF;
    chmin(ans, X*A + Y*B);
    chmin(ans, C * max(X, Y));
    ll t = C*X;
    if(Y > X) t += B*(Y-X);
    chmin(ans, t);
    t = C*Y;
    if(X > Y) t += A*(X-Y);
    chmin(ans, t);
    cout<<ans<<endl;
    return 0;
}