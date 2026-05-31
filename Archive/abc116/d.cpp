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
typedef pair<ll,int> pli;
int main(){
    ll N,K;
    cin >> N >> K;
    vector<pair<ll,int>> DT(N);
    rep(i,N) {
        cin>>DT[i].second>>DT[i].first;
        DT[i].second--;
    }
    sort(DT.rbegin(), DT.rend());
    ll smd = 0;
    ll cnt = 0;
    vector<multiset<ll>> USE(N);
    
    rep(i,K) {
        auto [d,t] = DT[i];
        smd += d;
        if(USE[t].empty()) cnt++;
        USE[t].insert(d);
    }

    priority_queue<ll,vector<ll>,greater<ll>> que;
    rep(i,N) {
        if(USE[i].size() > 1) {
            auto it = USE[i].begin();
            rep(j, USE[i].size()-1) {
                que.push(*it);
                it++;
            }
        }
    }

    ll ans = smd + cnt*cnt;

    vector<ll> SW(N);
    for(int i=K; i<N; i++) {
        auto [d,t] = DT[i];
        chmax(SW[t], d);
    }   
    priority_queue<ll> que2;
    rep(i,N) {
        if(!USE[i].empty()) continue;
        if(SW[i]==0) continue;
        que2.push(SW[i]);
    }
    while(!que.empty() && !que2.empty()) {
        auto q = que.top();
        auto q2 = que2.top();
        que.pop(); que2.pop();
        smd += q2 - q;
        cnt++;
        chmax(ans, smd + cnt*cnt);
    }
    cout << ans << endl;
    return 0;
}