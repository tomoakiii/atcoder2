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
    ll N,M,P,Q,R;
    cin >> N >> M >> P >> Q >> R;
    vector C(N, vector<ll>(M));
    rep(i,R) {
        ll x,y,z;
        cin>>x>>y>>z;
        x--,y--;
        C[x][y]=z;
    }
    vector<int> ORD(M,1);
    rep(i,M-Q) ORD[i] = 0;
    ll ans = 0;
    do{
        priority_queue<ll> que;
        rep(i,N) {
            ll sm = 0;
            rep(j,M) {
                if(ORD[j]==0) continue;
                sm += C[i][j];
            }
            que.push(sm);
        }
        ll tmp = 0;
        rep(k,P) {
            tmp += que.top();
            que.pop();
        }
        chmax(ans,tmp);
    }while(next_permutation(ORD.begin(), ORD.end()));
    cout << ans << endl;
    return 0;
}