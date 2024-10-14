
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<int> grp(N);
    vector<int> pw(3);
    vector<int> B(N);
    int sm = 0;
    rep(i,N){
        int a, b;
        cin >> a >> b;
        a--;
        grp[i] = a;
        pw[a] += b;
        B[i] = b;
    }
    int dp[N+1][501][501];
    dp[0][pw[0]][pw[1]] = 0;
    rep(i, N) {
        rep(j,15000) {
            int oj = grp[i];
            int nj = oj+j+1;
            if (nj >= 3) nj-=3;
            vector tpw = pw;
            tpw[nj] += B[i];
            tpw[oj] -= B[i];
            dp[i+1][tpw[0]][tpw[]]
        }
        
    }



    sm = pw[0] + pw[1] + pw[2];
    if (sm%3 != 0) {
        cout << -1 << endl;
        return 0;
    }
    int tgt = sm/3;
    
    map<vector<int>, int> mp;
    mp[pw] = 0;
    
    queue<pair<pair<vector<int>, vector<int>>,int>> que;
    que.push({{grp, pw}, 0});
    int ans = INFi;
    while(!que.empty()){
        auto [p, cnt] = que.front();        
        auto tgp = p.first;
        auto tpw = p.second;
        que.pop();
        if(tpw[0] == tgt && tpw[1] == tgt && tpw[2] == tgt) {
            chmin(ans, cnt);
            break;
        }
        rep(i,N){
            rep(j,2) {
                int oj = tgp[i];
                int nj = oj+j+1;
                if (nj >= 3) nj-=3;                
                if(tpw[oj] < B[i]) continue;
                tpw[nj] += B[i];
                tpw[oj] -= B[i];
                if (mp.count(tpw)) continue;
                tgp[i] = nj;
                mp[tpw] = cnt;              
                que.push({{tgp, tpw}, cnt+1});
                tgp[i] = oj;
                tpw[nj] -= B[i];
                tpw[oj] += B[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}