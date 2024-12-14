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
    ll H,W,X;
    cin >> H >> W >> X;
    ll P, Q;
    cin >> P >> Q;
    P--, Q--;
    vector S(H, vector<ll>(W));
    rep(i,H) rep(j,W) cin>>S[i][j];
    struct edge{
        int x;
        int y;
        ll p;
    };
    auto comp = [](edge &a, edge &b){return a.p > b.p;}; // > (<) is smallest (largest) first
    priority_queue<edge, vector<edge>, decltype(comp)> pq(comp);
    int dy[] = {1, -1, 0, 0};
    int dx[] = {0, 0, 1, -1};
    ll strong = S[P][Q];
    vector visit(H, vector<bool>(W,false));
    visit[P][Q] = true;
    rep(i,4) {
        edge e;
        e.y = P+dy[i];
        e.x = Q+dx[i];
        if(e.y<0 || e.y>=H || e.x<0 || e.x>=W) {
            continue;
        }
        visit[e.y][e.x] = true;
        e.p = S[e.y][e.x];
        pq.push(e);
    }
    while(!pq.empty()) {        
        auto q = pq.top();
        pq.pop();
        
        ll sdx = strong / X;        
        if(sdx*X < strong) {
            if(q.p <= sdx) {
                // ok;
            } else {
                cout << strong << endl;
                return 0;
            }                        
        } else {
            if(q.p < sdx) {
                // ok;
            } else {
                cout << strong << endl;
                return 0;
            }                        
        }
        strong += q.p;

        rep(i,4) {
            edge e;
            e.y = q.y + dy[i];
            e.x = q.x + dx[i];            
            if(e.y<0 || e.y>=H || e.x<0 || e.x>=W) {
                continue;
            }
            if(visit[e.y][e.x]) continue;
            visit[e.y][e.x] = true;
            e.p = S[e.y][e.x];
            pq.push(e);
            
        }                
    }
    cout << strong << endl;
    return 0;
}