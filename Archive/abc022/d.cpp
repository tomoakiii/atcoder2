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
    vector<double> X(N),Y(N);  
    vector<double> X2(N),Y2(N);  
    double xm=0, ym=0, xm2=0, ym2=0;
    rep(i,N) {
        cin>>X[i]>>Y[i];
        xm += X[i], ym += Y[i];
    }
    rep(i,N) {
        cin>>X2[i]>>Y2[i];
        xm2 += X2[i], ym2 += Y2[i];
    }
    xm /= (double)N;
    ym /= (double)N;
    xm2 /= (double)N;
    ym2 /= (double)N;
    double p = 0, p2 = 0;
    rep(i,N) {
        p += (X[i]-xm)*(X[i]-xm) + (Y[i]-ym)*(Y[i]-ym);
        p2 += (X2[i]-xm2)*(X2[i]-xm2) + (Y2[i]-ym2)*(Y2[i]-ym2);
    }
    printf("%.10f\n", sqrt(p2/p));
    return 0;
}