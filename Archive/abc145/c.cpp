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
    ll N; cin >> N;
    vector<double> X(N),Y(N);    
    rep(i,N) cin>>X[i]>>Y[i];
    vector<int> ord(N);
    rep(i,N) ord[i] = i;
    auto dist = [&] (int i, int j)->double{
        return sqrtf((X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]));
    };
    double ans = 0;
    double cnt = 0;
    do{
        double d = 0;
        rep(i,N-1) {
            d += dist(ord[i], ord[i+1]);
        }
        ans += d;
        cnt += 1.;
    }while(next_permutation(ord.begin(),ord.end()));
    printf("%.10f\n", ans/cnt);
    return 0;
}