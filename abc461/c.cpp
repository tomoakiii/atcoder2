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
    ll N,K,M;
    cin >> N >> K >> M;
    priority_queue<pair<ll,ll>> que1, que2;
    rep(i,N) {
        ll c, v; cin>>c>>v;
        c--;
        que2.push({v,c});
    }
    vector<int> visit(N);
    ll sm = 0;
    while(que1.size() < K){
        auto [v,c] = que2.top();
        que1.push({-v,c});
        que2.pop();
        sm+=v;
        visit[c]++;
    }
    ll cnt= 0;
    rep(i,N) if(visit[i])cnt++;
    while(cnt < M){
        auto [v,c] = que1.top();
        que1.pop();
        if(visit[c] == 1) continue;
        visit[c]--;
        sm+=v;
        while(!que2.empty()){
            auto [v2,c2] = que2.top();
            que2.pop();
            if(visit[c2] == 0){
                visit[c2]++;
                cnt++;
                sm+=v2;
                break;
            }
        }
    }
    cout<<sm<<endl;
    return 0;
}