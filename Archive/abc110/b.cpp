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
    ll N,M,X,Y; cin>>N>>M>>X>>Y;
    ll mx=-INF, my=INF;
    ll x,y;
    rep(i,N) {
        cin>>x;
        chmax(mx,x);
    }
    rep(i,M) {
        cin>>y;
        chmin(my,y);
    }
    if(max(mx,X) < min(my, Y)) cout<<"No War"<<endl;
    else cout<<"War"<<endl;
    return 0;
}