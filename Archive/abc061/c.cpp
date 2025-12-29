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
    ll N, K;
    cin >> N >> K;
    vector<pair<ll,ll>> AB(N);
    rep(i,N) {
        cin>>AB[i].first>>AB[i].second;
    }
    sort(AB.begin(), AB.end());
    rep(i,N) {
        K -= AB[i].second;
        if(K<=0) {
            cout<<AB[i].first<<endl;
            return 0;
        }
    }
    return 0;
}