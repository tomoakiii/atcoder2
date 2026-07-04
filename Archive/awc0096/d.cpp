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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    ll h=0;
    ll h2=0;
    rep(i,N) {
        ll a; cin>>a;
        h += a;
        if(h<0) h=0;
        h2 += a;
        if(h2<0) h2=0;
        chmin(h2,h/2);
    }
    cout<<min(h,h2)<<endl;
    return 0;
}