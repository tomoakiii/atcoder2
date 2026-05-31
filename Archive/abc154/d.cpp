#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
typedef long long ll;

int main(){    
    ll n,k; cin>>n>>k;
    vector<double> p(n);
    rep(i,n) {
        double pi; cin>>pi;
        p[i] = (pi+1) / 2;
    }
    vector<double> sm(n+1);
    rep(i,n) sm[i+1] = sm[i] + p[i];
    int l=0, r=k;
    double ans = 0;
    while(r<=n){
        chmax(ans, sm[r++] - sm[l++]);
    }
    printf("%.10f\n", ans);
    return 0;
}