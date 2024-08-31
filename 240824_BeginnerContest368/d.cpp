#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, K;
    cin >> N >> K;
    vector A(N, vector<ll>{});
    ll a,b;
    rep(i, N-1) {
        cin >> a >> b;
        a--, b--;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    vector<int> V(N);
    rep(i,K){
        cin >> V[i];
        V[i]--;
    }
    vector<int> depth(N, 0);
    auto d=[&](auto d, int cur, int from, int dep)->void{
        depth[cur] = dep;
        for(auto a: A[cur]){
            if (a == from) continue;
            d(d, a, cur, dep+1);
        }
    };
    d(d, 0, -1, 0);
    vector<bool> visit(N, false);
    ll cnt = 1;
    ll highest = V[0];
    visit[V[0]] = true;
    rep(i, K){
        int cur = V[i];
        if (visit[cur]) continue;
        visit[cur] = true;
        cnt++;
        bool fflg = false;
        while(!fflg){
            if (depth[highest] <= depth[cur]){                
                for(auto a: A[cur]){
                    if (depth[a] < depth[cur]) {
                        cur = a;                        
                    }
                }
                if (visit[cur]) fflg = true;                
                else {
                    visit[cur] = true;
                    cnt++;
                }
            } else {                
                for(auto a: A[highest]){
                    if (depth[a] < depth[highest]) {
                        highest = a;
                    }
                }
                if (visit[highest]) fflg = true;           
                else {
                    visit[highest] = true;
                    cnt++;
                }
            }


        }
        
    }    
   
    cout << cnt << endl;
    return 0;
}