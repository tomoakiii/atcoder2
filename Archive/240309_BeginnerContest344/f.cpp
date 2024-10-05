#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INFl = 0x0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F;
const int INF = 0x0F0F0F0F;

int main () {
    int N;
    cin >> N;
    vector<vector<ll>> P(N, vector<ll>(N));
    for(auto &g1:P) for(auto &g2:g1) cin>>g2;

    vector<vector<ll>> R(N, vector<ll>(N-1));
    for(auto &g1:R) for(auto &g2:g1) cin>>g2;

    vector<vector<ll>> D(N-1, vector<ll>(N));
    for(auto &g1:D) for(auto &g2:g1) cin>>g2;

    struct node{
        int cnt;
        ll rem;
        ll maxP;
        node(int cnt=INF, ll rem=-INF): cnt(cnt), rem(rem){}
        bool operator<(const node *n) const {
            if (cnt != n.cnt) return cnt < n.cnt;
            return rem > n.rem;
        }
    };

    vector<vector<node>> G(N, vector<node>(N, node(INF, 0)));
    G[0][0].cnt = 0;
    G[0][0].rem = 0;

    struct xy{
        int x;
        int y;
    };

    queue<xy> que;
    que.push({0, 0});
    while(!que.empty()){
        auto q = que.front();
        que.pop();
        G[q.y][q.x].maxP = max(G[q.y][q.x].maxP, P[q.y][q.x]);
        xy dr[2];
        dr[0] = {q.x, q.y+1};
        dr[1] = {q.x+1, q.y};
        vector<ll> cost(2, 0);
        if (q.y < N-1) cost[0] = D[q.y][q.x];
        if (q.x < N-1) cost[1] = R[q.y][q.x];
        
        for (int i=0; i<2; i++){
            if (cost[i] == 0) continue;
            xy q2 = dr[i];
            auto chg = cost[i] - G[q.y][q.x].rem;
            auto chgN = max(0ll, chg / G[q.y][q.x].maxP);
            auto cnt = G[q.y][q.x].cnt + chgN +1;
            if (G[q2.y][q2.x].cnt == INF) que.push(q2);
            if (G[q2.y][q2.x].cnt > cnt) {
                G[q2.y][q2.x].cnt = cnt;
                G[q2.y][q2.x].rem = chgN * G[q.y][q.x].maxP - chg;
            } else if (G[q2.y][q2.x].cnt == cnt) {
                G[q2.y][q2.x].rem = max(G[q2.y][q2.x].rem, chgN * G[q.y][q.x].maxP - chg);
            } else {
                continue;
            }
        }
    }
    cout << G[N-1][N-1].cnt << endl;
    return 0;
}

