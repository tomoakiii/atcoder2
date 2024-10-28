#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
struct edge{
    int to;
    ll dist;
};
typedef pair<long long, int> pli;
typedef map<int, long long> mil;

int main(){
    ll N;
    cin >> N;
    vector<vector<edge>> r(N, vector<edge>(2));
    vector<ll> dist(N+1, INF);
    ll a, b;
    int x;
    for(int i=0; i<N-1; i++){
        cin >> a >> b >> x;
        r[i][0].to = i+1;
        r[i][1].to = x-1;
        r[i][0].dist = a;
        r[i][1].dist = b;
    }
    dist[0]=0;
    priority_queue<pli, vector<pli>, greater<pli>> que;
    que.push(pli{0, 0});

    while(!que.empty()){
        ll dist_nd = que.top().first;
        ll nd = que.top().second;
        que.pop();
        if (dist[nd] < dist_nd) continue;
        for (int i=0; i<2; i++){
            if (dist[r[nd][i].to] <= dist[nd] + r[nd][i].dist) continue;
            dist[r[nd][i].to] = dist[nd] + r[nd][i].dist;
            que.push(pli{dist[r[nd][i].to], r[nd][i].to});
        }
    }
    cout << dist[N-1] << endl;
    return 0;
}

