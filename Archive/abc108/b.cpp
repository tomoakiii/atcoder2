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
    ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    ll dx = x2-x1, dy = y2-y1;
    ll x3=x2-dy, y3=y2+dx;
    cout<<x3<<" "<<y3<<" ";
    ll x4=x3-dx, y4=y3-dy;
    cout<<x4<<" "<<y4<<endl;
    return 0;
}