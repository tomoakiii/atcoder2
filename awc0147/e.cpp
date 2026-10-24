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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M, K;
    cin >> N >> M >> K;
    vector<pair<ll,ll>> RL(N), LR;
    rep(i,M){
        ll l,r; cin>>l>>r;
        RL[i] = {r,l};
    }
    sort(RL.begin(),RL.end());
    for(auto [r,l]:RL) {
        while(!LR.empty() && LR.back().first >= l){
            LR.pop_back();
        }
        LR.push_back({l,r});
    }
    vector
    return 0;
}