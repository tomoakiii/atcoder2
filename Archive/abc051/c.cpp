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
    ll sx,sy,tx,ty; cin>>sx>>sy>>tx>>ty;
    rep(i, tx-sx) cout<<"R";
    rep(i, ty-sy) cout<<"U";
    rep(i, tx-sx) cout<<"L";
    rep(i, ty-sy) cout<<"D";
    cout<<"D";
    rep(i, tx-sx+1) cout<<"R";
    rep(i, ty-sy+1) cout<<"U";
    cout<<"LU";
    rep(i, tx-sx+1) cout<<"L";
    rep(i, ty-sy+1) cout<<"D";
    cout<<"R"<<endl;
    return 0;
}