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
    const int N = 9;
    ll M;
    cin >> M;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    string p, goal;
    p = goal = "000000000";
    rep(i,8) {
        int j; cin>>j; j--;
        goal[j] = '1' + i;
        p[i] = '1' + i;
    }
    queue<ll> que;
    unordered_map<string, ll> mp;
    unordered_map<ll, string> mp2;
    unordered_map<ll,ll> dist, emp;
    ll ind=0;
    dist[ind] = 0;
    emp[ind] = 8;
    mp[p] = ind;
    mp2[ind] = p;
    que.push(ind);

    auto jdg = [&](string &p)->bool{        
        return (p == goal);
    };

    while(!que.empty()){
        int q = que.front();
        que.pop();                
        string p = mp2[q];
        if(jdg(p)) {
            cout<<dist[q];
            return 0;
        }
        int u = emp[q];
        for(auto nx: uv[u]) {
            char g = p[nx];
            p[u] = g;
            p[nx] = '0';
            if(mp.contains(p)) {
                
            } else {
                ind++;
                mp[p] = ind;
                mp2[ind] = p;
                dist[ind] = dist[q] + 1;
                emp[ind] = nx;                
                que.push(ind);
            }
            p[u] = '0';
            p[nx] = g;
        }
    }
    cout<<-1<<endl;

    return 0;
}