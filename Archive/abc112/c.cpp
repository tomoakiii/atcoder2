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
    vector H(101, vector<ll>(101));
    vector<pair<ll, pair<int,int>>> LXY(N);
    rep(i,N) cin>>LXY[i].second.first>>LXY[i].second.second>>LXY[i].first;
    sort(LXY.rbegin(),LXY.rend());
    rep(i,101) rep(j,101) {
        ll nh = LXY[0].first + abs(i-LXY[0].second.first) + abs(j-LXY[0].second.second);
        bool flg = true;
        rep(k,N){
            ll nh2 = LXY[k].first + abs(i-LXY[k].second.first) + abs(j-LXY[k].second.second);
            if(LXY[k].first == 0) {
                if(nh2 >= nh) continue;
                else flg = false;
            } else {
                if(nh != nh2) flg = false;
            }
        }
        if(flg) {
            cout<<i<<" "<<j<<" "<<nh<<endl;
            return 0;
        }
    }
    return 0;
}