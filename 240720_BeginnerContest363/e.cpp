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
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j+=W-1){        
            e.pH = i;
            e.pW = j;
            e.a = A[i][j];
            visit[i][j] = true;
            que.push(e);
        }
    }
    for(int i=0; i<H; i+=H-1) {
        for(int j=1; j<W-1; j++){        
            e.pH = i;
            e.pW = j;
            e.a = A[i][j];
            visit[i][j] = true;
            que.push(e);
        }
    }    
    int nx[4] = {1, -1, 0, 0};
    int ny[4] = {0, 0, 1, -1};
    ll ans = H*W;
    while(Y--) {
        cr++;        
        while(true){
            if(que.empty()) {                
                break;
            }
            auto q = que.top();
            if(cr < q.a) {                
                break;
            } else {
                ans--;
                que.pop();                
            }
            rep(k, 4){
                int ni = q.pH + ny[k];
                int nj = q.pW + nx[k];
                if(ni < 0 || ni >= H || nj < 0 || nj >= W) {
                    continue;
                }
                if (visit[ni][nj]) continue;
                e.pH = ni;
                e.pW = nj;
                e.a = A[ni][nj];
                visit[ni][nj] = true;
                que.push(e);
            }            
        }
        cout << ans << endl;
    }
    return 0;
}