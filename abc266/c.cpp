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
typedef pair<double, double> pdd;
bool flg = true;
int main(){
    pdd a[4];
    rep(i,4) cin >> a[i].first >> a[i].second;
    rep(i,4) {
        pdd ab = {a[i].first - a[(i+1)%4].first, a[i].second - a[(i+1)%4].second};
        pdd ac = {a[(i+2)%4].first - a[(i+1)%4].first, a[(i+2)%4].second - a[(i+1)%4].second};
        double prod = ab.first * ac.second - ab.second * ac.first;
        if(prod>0) flg=false;
    } 
    if(flg) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}