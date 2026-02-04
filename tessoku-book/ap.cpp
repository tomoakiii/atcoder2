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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll N,K;
    cin>>N>>K;
    vector<pair<ll,ll>> AB(N);
    rep(i,N)cin>>AB[i].first >> AB[i].second;
    sort(AB.begin(), AB.end());
    ll l = 0;
    ll ans = 0;
    rep(i,N) {
        while(AB[l].first + K < AB[i].first) {
            l++;
        }
        vector<ll> B(101);
        for(int j=l;j<=i;j++) {
            B[AB[j].second]++;
        }
        rep(j,100) B[j+1] += B[j];
        for(int j=K+1; j<=100; j++) {
            chmax(ans, B[j]-B[j-K-1]);
        }
    }
    cout << ans << endl;
    return 0;
}