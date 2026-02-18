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
    rep(i,M) {
        cin>>LR[i].first >> LR[i].second;
        LR[i].second *= -1;
    }
    sort(LR.begin(),LR.end());
    ll ed = 0, ced = 0;
    ll ans = 0;
    for(int i=0; i<M; i++) {
        auto [l,r] = LR[i];
        r *= -1;
        if (ced + 1 == l) {
            ans++;
            chmax(ed, r);
            ced = ed;
        } else if (ced + 1 < l) {
            if(ed + 1 < l) {
                cout<<-1<<endl;
                return 0;
            } else if (ed + 1 == l) {
                ans+=2;
                chmax(ed, r);
                ced = ed;
            } else {
                ans++;
                ced = ed;
            }
        }
        chmax(ed, r);

    }
    if(ed != N) {
        cout << -1 << endl;
        return 0;
    }
    if(ced != N) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}