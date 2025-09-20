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
struct ST{
    int a,b,c,d;
    const bool operator<(const ST &x) const{
        return b < x.b;
    };
};
int main(){
    ll N,M,Q;
    cin >> N >> M >> Q;
    vector<ST> A(Q);

    rep(i,Q) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--, b--;
        A[i] = {a,b,c,d};
    }

    ll ans = 0;

    auto dfs = [&](auto dfs, int cur, int arr[], int low)->void{
        if(cur == N) {
            ll score = 0;
            rep(i,Q) {
                if(arr[A[i].b] - arr[A[i].a] == A[i].c) score += A[i].d;
                chmax(ans, score);
            }
            return;
        }
        for(int i=low; i<M; i++) {
            arr[cur] = i;
            dfs(dfs, cur+1, arr, i);
        }
        return;
    };
    int arr[10];
    dfs(dfs, 0, arr, 0);
    cout << ans << endl;
    return 0;
}
