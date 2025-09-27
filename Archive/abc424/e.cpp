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
typedef double ld;

int main(){
    const ll M = 1000000000;
    int T; cin>>T;
    while(T--){
        ll N, K, X;
        cin >> N >> K >> X;
        priority_queue<pair<ld,ll>> que;
        rep(i,N) {
            ld a; cin>>a;
            que.push({a,1});
        }
        while(K) {
            auto [v, c] = que.top();
            que.pop();            
            if(K <= c) {
                c -= K;
                que.push({v/2, K*2});
                while(c < X) {
                    auto [v2, c2] = que.top();
                    v = v2;
                    que.pop();
                    c += c2;
                }
                printf("%12.12f\n", v);
                break;             
            }
            K -= c;
            if(c>M) que.push({v/2, M});
            else que.push({v/2, c*2});
        }
                
    }
    return 0;
}