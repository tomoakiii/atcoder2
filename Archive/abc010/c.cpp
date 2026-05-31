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
    ll xa,ya,xb,yb,T,V; cin>>xa>>ya>>xb>>yb>>T>>V;
    ll N; cin >> N;
    bool flg = false;
    rep(i,N) {
        ll x, y; cin>>x>>y;
        if(sqrt((double)(xa-x)*(xa-x)+(ya-y)*(ya-y)) + sqrt((double)(xb-x)*(xb-x)+(yb-y)*(yb-y)) <= (double)T*V) {
            flg = true;
        }
    }
    if(flg) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}