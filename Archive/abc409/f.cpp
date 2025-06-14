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
typedef pair<ll, int> pli;
int main(){
    ll N, Q;    
    cin >> N >> Q;
    vector<ll> X(N+Q), Y(N+Q);
    int pp = N;
    rep(i,N) {
        ll x,y;
        cin>>x>>y;
        X[i] = x;
        Y[i] = y;
    }
    auto dist = [&](ll i, ll j) -> ll {
        return abs(X[i]-X[j]) + abs(Y[i]-Y[j]);
    };
    dsu UF(N+Q);            
    map<ll, int> mp;
    priority_queue<pli, vector<pli>, greater<pli>> que;
    vector<pair<int,int>> vp;
    rep(i,N) {
        for(int j = i+1; j < N; j++) {
            ll d = dist(i,j);            
            vp.push_back({i,j});
            que.push({d, vp.size()-1});
        }
    }
    while(Q--) {
        int g;
        cin>>g;
        if (g == 1) {
            ll x,y;
            cin>>x>>y;
            X[pp] = x;
            Y[pp] = y;                             
            rep(j, pp) {
                ll d = dist(pp, j);
                vp.push_back({j, pp});
                que.push({d, vp.size()-1});
            }
            pp++;
        } else if (g==2) {            
            ll dm = -1;            
            while(!que.empty()) {
                auto [q, pi] = que.top();
                que.pop();
                auto [i, j] = vp[pi];                
                if(UF.same(i,j)) continue;
                dm = q;            
                UF.merge(i,j);
                break;
            
            }
            while(!que.empty()) {
                auto [q, pi] = que.top();
                if(q!=dm) break;
                que.pop();
                auto [i, j] = vp[pi];
                if(UF.same(i,j)) continue;
                UF.merge(i,j);                
            }
            cout<<dm<<endl;
        } else {
            ll u,v;
            cin>>u>>v;
            u--,v--;
            if(UF.same(u,v)) {
                cout<<"Yes"<<endl;
            } else {
                cout<<"No"<<endl;
            }
        }

    }
    return 0;
} 