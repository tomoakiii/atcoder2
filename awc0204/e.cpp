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
    ll H,W,M;
    cin >> H >> W >> M;
    vector<ll> A(H),B(W),Avis(H),Bvis(W);
    rep(i,H) cin>>A[i];
    rep(i,W) cin>>B[i];
    deque<tuple<ll,ll,bool>> RCT(M);
    rep(i,M){
        ll r,c; bool t;
        cin>>r>>c>>t;
        r--,c--;
        RCT[i] = make_tuple(r,c,t);
        Avis[r] = true;
        Bvis[c] = true;
    }
    vector<set<int>> RC(H), CR(W);
    rep(i,M){
        auto [r,c,t] = RCT[i];
        RC[r].insert(i);
        CR[c].insert(i);
    }

    vector<bool> visit(M);
    ll ans = 0, cnt = 0;
    bool flg = true;
    rep(h,H){
        if(RC[h].empty()) continue;
        int seed = *RC[h].begin();
        RC[h].erase(RC[h].begin());
        vector<pair<int, bool>> vv;

        queue<int> que;
        auto [r,c,t] = RCT[seed];
        map<ll,int> Rvis, Cvis;
        Rvis[r] = false;
        Cvis[c] = t;
        ll sm = 0;
        que.push(seed);
        visit[seed] = true;

        auto update = [&](ll r, ll c)->void{
            while(!CR[c].empty()){
                int j = *CR[c].begin();
                CR[c].erase(CR[c].begin());
                if(visit[j])continue;
                que.push(j);
                visit[j] = true;
            }

            while(!RC[r].empty()){
                int j = *RC[r].begin();
                RC[r].erase(RC[r].begin());
                if(visit[j])continue;
                que.push(j);
                visit[j] = true;
            }
        };
        while(!que.empty()){
            auto i = que.front();
            que.pop();
            auto [r,c,t] = RCT[i];
            bool col = false;
            if(Rvis.contains(r) && Cvis.contains(c)){
                col ^= Rvis[r];
                col ^= Cvis[c];
                if(col != t) {
                    flg = false;
                    break;
                }
            } else if(Rvis.contains(r)) {
                col ^= Rvis[r];
                if(col != t) {
                    Cvis[c] = true;
                } else {
                    Cvis[c] = false;
                }
                update(r,c);
            } else {
                col ^= Cvis[c];
                if(col != t) {
                    sm += A[r];
                    Rvis[r] = true;
                } else {
                    Rvis[r] = false;
                }
                update(r,c);
            }
            vv.push_back({i, Rvis[r] != Cvis[c]});
        }

        ll a = 0, b = 0;

        for(auto [i, v] : vv){
            auto [r,c,t]=RCT[i];
            if(v) {
                a+=A[r], b+=B[c];
                cnt++;
            } else b+=A[r]+B[c];
        }

        ans += min(a,b);
    }
    if(!flg) {
        cout << -1 << endl;
        return 0;
    }
    if(cnt%2 == 1){
        ll mn = INF;
        rep(i,H)if(!Avis[i]) chmin(mn, A[i]);
        rep(i,W)if(!Bvis[i]) chmin(mn, B[i]);
        if(mn == INF){
            cout << -1 << endl;
            return 0;
        }
        ans += mn;
    }
    cout << ans << endl;
    return 0;
}