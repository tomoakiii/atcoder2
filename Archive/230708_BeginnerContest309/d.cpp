#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N1, N2, M;
    cin >> N1 >> N2 >> M;
    vector<vector<vector<int>>> side(2);
    side[0].resize(N1);
    side[1].resize(N2);     
    int a, b;
    rep(i, M){
        cin >> a >> b;
        a--, b--;
        if (a >= N1) {
            a -= N1;
            b -= N1;
            side[1][a].push_back(b);
            side[1][b].push_back(a);
        } else {
            side[0][a].push_back(b);
            side[0][b].push_back(a);
        }
    }
    vector<vector<ll>> dist(2);
    dist[0].resize(N1, INF);
    dist[1].resize(N2, INF);
    ll mx[] = {0, 0};    
    auto func = [&](auto func, int st, int k)->void{
        queue<pair<int,ll>> que;
        que.push({st, 0});
        while (!que.empty()){
            auto [i, td] = que.front();
            que.pop();
            for(auto d: side[k][i]){
                if (dist[k][d] == INF){
                    dist[k][d] = td+1;
                    mx[k] = max(mx[k], td+1);
                    que.push({d, td+1});
                }
            }
        }        
    };
    dist[0][0] = 0;
    dist[1][N2-1] = 0;
    func(func, 0, 0);
    func(func, N2-1, 1);
    cout << mx[0] + mx[1] + 1 << endl;
    return 0;
}