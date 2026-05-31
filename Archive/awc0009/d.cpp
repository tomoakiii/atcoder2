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
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> LR(M);
    rep(i,M) cin>>LR[i].first>>LR[i].second;
    sort(LR.begin(), LR.end());
    LR.push_back({INF,INF});
    ll ed = 0, cnt=0;
    M++;
    rep(i,M) {
        auto [l,r] = LR[i];
        if(l > ed) {
            ll sn = l-ed-1;
            if(cnt + sn >= N) {
                cout << ed + N - cnt << endl;
                return 0;
            }
            cnt += sn;
        }
        cerr<<l<<" "<<ed<<" "<<r<<" "<<cnt<<endl;
        chmax(ed,r);
    }
    cout<<-1<<endl;
    return 0;
}