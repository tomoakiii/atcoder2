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
    vector<int> a(N), b(N), c(N), d(N);
    int sc = 0, sd = 0;
    int sa = 0, sb = 0;
    rep(i,N) {
        cin>>a[i]>>b[i];
        sa += a[i];
        sb += b[i];
    }
    rep(i,N) {
        cin>>c[i]>>d[i];
        sc += c[i];
        sd += d[i];
    }
    set<pair<double,double>> st0, st1;
    rep(i,N) {
        double x = a[i]*N - sa;
        double y = b[i]*N - sb;
        double r = x*x+y*y;
        if(abs(x) > 0.0001) st0.insert({r, atan(y/x)});
        else if(y>0) st0.insert({r, M_PI});
        else st0.insert({r, -M_PI});
    }
    rep(i,N) {
        double x = c[i]*N - sc;
        double y = d[i]*N - sd;
        double r = x*x+y*y;
        if(abs(x) > 0.0001) st1.insert({r, atan(y/x)});
        else if(y>0) st1.insert({r, M_PI});
        else st1.insert({r, -M_PI});
    }
    for(auto s: st0) {
        for(auto s1: st1) {
            bool flg = true;
            auto st2 = st1;
            double theta;
            if(abs(s1.first - s.first) > 0.001) {
                flg = false; break;
                theta = s1.second - s.second;

            }
            for(auto s3: st0) {
                double alpha = theta + s3.second;
                double r = s3.first;
                
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}