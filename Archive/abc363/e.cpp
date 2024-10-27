#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll H, W, Y;    
    cin >> H >> W >> Y;    
    vector A(H, vector<int>(W, 0));
    vector visit(H, vector<bool>(W, false));
    rep(i,H) rep(j,W) cin >> A[i][j];
    ll cr = 0;
    struct edge{
        int pH;
        int pW;
        long long a;
    };
    auto comp = [](edge &a, edge &b){return a.a > b.a;}; // > (<) is smallest (largest) first
    priority_queue<edge, vector<edge>, decltype(comp)> que(comp);

    edge e;
    rep(i,H) {
        rep(j,W) {        
            if (i==0 || i == H-1 || j == 0 || j == W-1){
                e.pH = i;
                e.pW = j;
                e.a = A[i][j];
                visit[i][j] = true;
                que.push(e);
            }
        }
    }
    int nx[4] = {1, -1, 0, 0};
    int ny[4] = {0, 0, 1, -1};
    ll ans = H*W;
    while(Y--) {
        cr++;        
        while(!que.empty()){
            auto q = que.top();
            if(cr < q.a) {                
                break;
            } else {
                ans--;
                que.pop();                
            }
            rep(k, 4){
                e.pH = q.pH + ny[k];
                e.pW = q.pW + nx[k];
                if(e.pH < 0 || e.pH >= H || e.pW < 0 || e.pW >= W) {
                    continue;
                }
                if (visit[e.pH][e.pW]) continue;
                e.a = A[e.pH][e.pW];
                visit[e.pH][e.pW] = true;
                que.push(e);
            }            
        }
        cout << ans << endl;
    }
    return 0;
}