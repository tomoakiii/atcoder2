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
    ll N, M;
    cin >> N >> M;

    vector<ll> C(N);
    rep(i,N) cin>>C[i];
    
    vector zoo(N, vector<int>{});
    vector<ll> rank(N);

    
    rep(i,M) {
        int K;
        cin>>K;
        rep(j, K) {
            int a;
            cin>>a;
            a--;
            zoo[a].emplace_back(i); // zoo #a has animal i
        }
    }

    ll mn = INF;
    map<vector<int>, ll> cost;
    auto f = [&](auto f, ll c, vector<int> &cnt, int rem) -> void{        
        
        rep(i, N) {            
            vector cnt2 = cnt;
            ll cst = c + C[i];
            int rem2 = rem;
            if(cst > mn) continue;
            bool flg = false;
            
            for(auto a: zoo[i]) {                
                if(cnt2[a] > 0) {
                    flg = true;
                    cnt2[a]--;
                    if(cnt2[a] == 0) rem2--;
                }
            }
            if(!flg) continue;            
            if(rem2 == 0) {
                chmin(mn, cst);                
            } else {
                if(cost.contains(cnt2)){
                    if (cost[cnt2] <= cst) {
                        continue;
                    } else {
                        cost[cnt2] = cst;
                    }
                } else {
                    cost[cnt] = cst;
                }
                // cout << rem << " " << i << endl;
                f(f, cst, cnt2, rem2);
            }                        
        }
    };

    vector<int> cntm(M, 2);
    f(f, 0, cntm, M);
    cout << mn << endl;
    return 0;
}