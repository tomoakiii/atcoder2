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
    vector<pair<ll,ll>> HS(N);
    rep(i,N) cin>>HS[i].first>>HS[i].second;
    vector<ll> P(M);
    rep(i,M) cin>>P[i];
    sort(HS.begin(),HS.end());
    sort(P.begin(), P.end());
    priority_queue<ll> que;
    int j=0;
    ll ans = 0;
    rep(i,M) {
        while(j<N && P[i] >= HS[j].first) {
            que.push(HS[j].second);
            j++;
        }
        if(que.empty()) {
            cout<<-1<<endl;
            return 0;
        }
        ans+=que.top();
        que.pop();
    }
    cout<<ans<<endl;
    return 0;
}