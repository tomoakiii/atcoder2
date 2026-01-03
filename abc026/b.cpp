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
    vector<ll> R(N);
    rep(i,N) cin>>R[i];
    if(N%2 == 1) {
        R.push_back(0);
        N++;
    }
    sort(R.rbegin(), R.rend());
    double ans = 0;
    for(int i=0; i<N; i+=2) {
        double dr = (R[i]*R[i] - R[i+1]*R[i+1]);
        ans += dr * M_PI;
    }
    printf("%.10f\n", ans);
    return 0;
}