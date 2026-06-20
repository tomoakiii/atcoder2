#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    vector<ll> X(N),C(N);
    rep(i,N) cin>>X[i]>>C[i];
    ll ans = 0;
    int r = -1;
    int l = 0;
    ll cost = 0;
    vector<bool> visit(N);
    rep(i,N) {
        while(r+1<N && cost + C[r+1] <= M) {
            r++;
            cost += C[r];
            visit[r] = true;
        }
        if(r > i) chmax(ans, X[r]-X[i]);
        chmax(r,i);
        while(l<=i){
            if(visit[l]) cost -= C[l];
            l++;
        }
    }
    cout<<ans<<endl;
    return 0;
}