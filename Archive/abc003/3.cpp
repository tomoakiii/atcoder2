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
    ll N,K; cin>>N>>K;
    vector<double> R(N);
    rep(i,N) cin>>R[i];
    sort(R.rbegin(), R.rend());
    while(R.size() > K) R.pop_back();
    reverse(R.begin(), R.end());
    double c = 0;
    for(auto r: R) {
        double c2 = (c + r) / 2;
        if(c2 < c) {
            continue;
        }
        if(K) {
            K--;
            c = c2;
        }         
    }

    printf("%.10f\n", c);
    return 0;
}