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
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    rep(i,N) cin>>X[i]>>Y[i];    
    double h;
    double ans = -1;
    rep(i,N-1) {
        if(X[i+1] == X[i]) h = Y[i];
        else {            
            ll dX = (X[i+1] - X[i]);
            ll dY = (Y[i+1] - Y[i]);
            ll p = Y[i+1] * dX - X[i+1] * dY;            
            h = (double)p / (double)dX;
        }
        chmax(ans, h);
    }    
    if (ans < 0) printf("-1\n");
    else printf("%.10f\n", ans);
    return 0;
}