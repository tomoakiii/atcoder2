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
    ll N,G,F;
    cin >> N >> G >> F;
    vector<pair<ll,ll>> PR(N);
    rep(i,N) cin>>PR[i].first>>PR[i].second;
    sort(PR.begin(),PR.end());
    PR.push_back({G,0});
    priority_queue<ll> que;
    ll ans=0;
    ll last = 0;
    for(auto [p,r]: PR){
        while(!que.empty() && p-last > F) {
            ans++;
            F+=que.top();
            que.pop();
        }
        if(p-last>F) {
            cout<<-1<<endl;
            return 0;
        }
        F-=p-last;
        last=p;
        que.push(r);
    }
    cout<<ans<<endl;
    return 0;
}