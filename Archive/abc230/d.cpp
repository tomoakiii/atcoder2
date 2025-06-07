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
    ll N,D;
    cin >> N >> D;
    vector<pair<ll,ll>> LR(N);
    rep(i,N) {
        cin >> LR[i].second >> LR[i].first;
    }
    sort(LR.begin(), LR.end());
    int i = 0;
    int cnt = 0;
    while(i < N) {
        auto [r, l] = LR[i++];
        cnt++;        
        while(i < N) {
            auto [r2, l2] = LR[i];
            if(l2 <= r + D - 1) i++;
            else break;
        }
    }
    cout << cnt << endl;
    return 0;
}