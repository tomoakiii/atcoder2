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
    string S,T; cin>>S>>T;
    int N=S.size();
    int M=T.size();
    vector cnt(M, vector<int>{});
    rep(i,M) {
        rep(j, N) {
            if(S[j] == T[i]) cnt[i].push_back(j);
        }
    }
    ll D=cnt[0].size();
    vector<pair<ll,ll>> LR;
    rep(i,D) {
        int st = cnt[0][i];
        bool flg = true;
        for(int j=1; j<M; j++) {
            auto it= upper_bound(cnt[j].begin(),cnt[j].end(),st) - cnt[j].begin();
            if(it == cnt[j].size()) {
                flg = false;
                break;
            }
            st = cnt[j][it];
        }
        if(flg) LR.emplace_back(cnt[0][i], st);
    }
    if(LR.size()==0) {
        cout << (N*(N+1)/2) << endl;
        return 0;
    }
    int id=0;
    int ed=LR[0].second;
    ll ans = 0;
    rep(i,N) {
        if(id < LR.size() && i > LR[id].first) {
            id++;
        }
        if(id == LR.size()) ed = N;
        else ed = LR[id].second;
        //cerr<<ed-i<<endl;
        ans += ed-i;
    }
    cout<<ans<<endl;
    return 0;
}