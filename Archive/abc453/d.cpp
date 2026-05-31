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
typedef pair<int,int> pii;
typedef tuple<ll, int,int,int> tp;
struct node{
    ll d=INF;
    int cp=-1;
    int py=-1,px=-1,pp=-1;
};
int main(){
    ll H,W; cin>>H>>W;
    vector<string> S(H);
    int ey,ex;
    vector dist(H, vector(W, vector<node>(4, {INF,-1})));
    priority_queue<tp, vector<tp>, greater<tp>> que;

    int dy[] = {1,0,-1,0}; // d,r,u,l
    int dx[] = {0,1,0,-1};
    char ac[] = {'D','R','U','L'};

    auto push = [&](int i, int j, int k, ll d, int pi=-1, int pj=-1, int pk=-1)->void{
        if(dist[i][j][k].d<=d) return;
        que.push(make_tuple(d, i, j, k));
        dist[i][j][k].d = d;
        dist[i][j][k].py=pi;
        dist[i][j][k].px=pj;
        dist[i][j][k].cp=k;
        dist[i][j][k].pp=pk;
    };

    rep(i,H) {
        cin>>S[i];
        rep(j,W) {
            if(S[i][j] == 'S') {
                rep(k,4) {
                    push(i,j,k,0);
                }
            }
            else if(S[i][j] == 'G') {
                ey=i; ex=j;
            }
        }
    }

    while(!que.empty()) {
        auto [d, i, j, p] = que.top();
        que.pop();
        if(dist[i][j][p].d < d) continue;
        rep(k,4) {
            if(S[i][j] == 'x' && k==p) continue;
            if(S[i][j] == 'o' && k!=p) continue;
            int ny=dy[k]+i;
            int nx=dx[k]+j;
            if(ny<0||ny>=H||nx<0||nx>=W) continue;
            if(S[ny][nx] == '#') continue;
            push(ny,nx,k,dist[i][j][p].d+1,i,j,p);
        }
    }

    ll lm = 5e6;
    node cur;
    string ans;
    rep(k,4) {
        if(chmin(lm, dist[ey][ex][k].d)) {
            cur = dist[ey][ex][k];
        }
    }
    if(cur.d==INF) {
        cout<<"No"<<endl;
        return 0;
    }

    while(cur.d != 0) {
        //cerr<<cur.py<<" "<<cur.px<<" "<<ac[cur.pp]<<" "<<ac[cur.cp]<<endl;
        node pre = dist[cur.py][cur.px][cur.pp];
        ans.push_back(ac[cur.cp]);
        cur = pre;
    }

    reverse(ans.begin(), ans.end());
    cout<<"Yes"<<endl;
    cout<<ans<<endl;
    return 0;
}